// Fill out your copyright notice in the Description page of Project Settings.

#include "EnemyAIController.h"
#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Object.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Bool.h"
#include "Engine/EngineTypes.h"
#include "Math/Vector.h"
#include "AI/Navigation/NavigationTypes.h"
#include "Navigation/PathFollowingComponent.h"
#include "NavigationSystem.h"
#include "TagGameGameMode.h"

AEnemyAIController::AEnemyAIController()
{
	PerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("Perception"));
	Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("Sight"));

	Sight->SightRadius = 700.f;
	Sight->LoseSightRadius = 800.f;
	Sight->PeripheralVisionAngleDegrees = 90.f;
	Sight->DetectionByAffiliation.bDetectEnemies = true;
	Sight->DetectionByAffiliation.bDetectNeutrals = true;
	Sight->DetectionByAffiliation.bDetectFriendlies = true;

	PerceptionComponent->ConfigureSense(*Sight);
	PerceptionComponent->SetDominantSense(Sight->GetSenseImplementation());

}

void AEnemyAIController::BeginPlay()
{
	Super::BeginPlay();

	PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIController::OnPerception);

	TargetBallKey = TEXT("BestBall");
	PatrolLocationKey = TEXT("RandomPoint");
	PlayerSeenKey = TEXT("IsPlayerInSight");
	UBlackboardData* BlackboardAsset = NewObject<UBlackboardData>();
	BlackboardAsset->UpdatePersistentKey<UBlackboardKeyType_Object>(TargetBallKey);
	BlackboardAsset->UpdatePersistentKey<UBlackboardKeyType_Vector>(PatrolLocationKey);
	BlackboardAsset->UpdatePersistentKey<UBlackboardKeyType_Bool>(PlayerSeenKey);
	UBlackboardComponent* BlackboardTemp = Blackboard.Get();
	UseBlackboard(BlackboardAsset, BlackboardTemp);
	Blackboard = BlackboardTemp;



	GoToPlayer = MakeShared <FAIVState>(
		[](AAIController* AIController, UBlackboardComponent* BlackboardComponent)
		{
			AIController->MoveToActor(AIController->GetWorld()->GetFirstPlayerController()->GetPawn(), 20.0f);
		},
		nullptr,
		[this](AAIController* AIController, UBlackboardComponent* BlackboardComponent, const float DeltaTime) -> TSharedPtr<FAIVState>
		{
			const EPathFollowingStatus::Type State = AIController->GetMoveStatus();

			if (State == EPathFollowingStatus::Moving)
			{
				return nullptr;
			}

			AActor* TargetBall = Cast<AActor>(BlackboardComponent->GetValueAsObject(TargetBallKey));

			if (TargetBall)
			{
				TargetBall->AttachToActor(AIController->GetWorld()->GetFirstPlayerController()->GetPawn(), FAttachmentTransformRules::KeepRelativeTransform);
				TargetBall->SetActorRelativeLocation(FVector(0, 0, 0));
				BlackboardComponent->SetValueAsObject(TargetBallKey, nullptr);
			}

			return SearchForBall;
		}
	);



	SearchForBall = MakeShared <FAIVState>(
		[this](AAIController* AIController, UBlackboardComponent* BlackboardComponent)
		{
			const ATagGameGameMode* AIGameMode = Cast<ATagGameGameMode>(AIController->GetWorld()->GetAuthGameMode());
			const TArray<ABall*>& BallsList = AIGameMode->GetBalls();

			ABall* NearestBall = nullptr;

			for (int32 i = 0; i < BallsList.Num(); i++)
			{
				if (!BallsList[i]->GetAttachParentActor() &&
					(!NearestBall ||
						FVector::Distance(AIController->GetPawn()->GetActorLocation(), BallsList[i]->GetActorLocation()) <
						FVector::Distance(AIController->GetPawn()->GetActorLocation(), NearestBall->GetActorLocation())))
				{
					NearestBall = BallsList[i];
				}
			}
			
			BlackboardComponent->SetValueAsObject(TargetBallKey, NearestBall);
		},
		nullptr,
		[this](AAIController* AIController, UBlackboardComponent* BlackboardComponent, const float DeltaTime) -> TSharedPtr<FAIVState>
		{
			if (BlackboardComponent->GetValueAsObject(TargetBallKey))
			{
				return GoToBall;
			}
			else
			{
				return SearchForBall;
			}
		}
	);



	GoToBall = MakeShared <FAIVState>(
		[this](AAIController* AIController, UBlackboardComponent* BlackboardComponent)
		{
			AActor* TargetBall = Cast<AActor>(BlackboardComponent->GetValueAsObject(TargetBallKey));

			if (TargetBall)
			{
				AIController->MoveToActor(TargetBall, 50.0f);
			}
		},
		nullptr,
		[this](AAIController* AIController, UBlackboardComponent* BlackboardComponent, const float DeltaTime) -> TSharedPtr<FAIVState>
		{
			const EPathFollowingStatus::Type State = AIController->GetMoveStatus();

			if (State == EPathFollowingStatus::Moving)
			{
				const AActor* TargetBall = Cast<AActor>(BlackboardComponent->GetValueAsObject(TargetBallKey));
				if (TargetBall && TargetBall->GetAttachParentActor())
				{
					return SearchForBall;
				}

				return nullptr;
			}

			return GrabBall;
		}
	);



	GrabBall = MakeShared <FAIVState>(
		[this](AAIController* AIController, UBlackboardComponent* BlackboardComponent)
		{
			const AActor* TargetBall = Cast<AActor>(BlackboardComponent->GetValueAsObject(TargetBallKey));
			if (TargetBall && TargetBall->GetAttachParentActor())
			{
				BlackboardComponent->SetValueAsObject(TEXT("BestBall"), nullptr);
			}
		},
		nullptr,
		[this](AAIController* AIController, UBlackboardComponent* BlackboardComponent, const float DeltaTime) -> TSharedPtr<FAIVState>
		{
			AActor* TargetBall = Cast<AActor>(BlackboardComponent->GetValueAsObject(TargetBallKey));

			if (!TargetBall)
			{
				return SearchForBall;
			}

			TargetBall->AttachToActor(AIController->GetPawn(), FAttachmentTransformRules::KeepRelativeTransform);
			TargetBall->SetActorRelativeLocation(FVector(0, 0, 0));

			return SearchForPatrolPoint;
		}
	);

	SearchForPatrolPoint = MakeShared <FAIVState>(
		[this](AAIController* AIController, UBlackboardComponent* BlackboardComponent)
		{
			FNavLocation TargetLocation;
			UNavigationSystemV1* NavSystem = UNavigationSystemV1::GetCurrent(GetWorld());
			NavSystem->GetRandomReachablePointInRadius(AIController->GetPawn()->GetActorLocation(), 2000, TargetLocation);
			BlackboardComponent->SetValueAsVector(PatrolLocationKey, TargetLocation);
		},
		nullptr,
		[this](AAIController* AIController, UBlackboardComponent* BlackboardComponent, const float DeltaTime) -> TSharedPtr<FAIVState>
		{
			return Patrol;
		}
	);



	Patrol = MakeShared <FAIVState>(
		[this](AAIController* AIController, UBlackboardComponent* BlackboardComponent)
		{
			AIController->MoveToLocation(BlackboardComponent->GetValueAsVector(PatrolLocationKey), 20.f);
		},
		nullptr,
		[this](AAIController* AIController, UBlackboardComponent* BlackboardComponent, const float DeltaTime) -> TSharedPtr<FAIVState>
		{
			if (BlackboardComponent->GetValueAsBool(PlayerSeenKey))
			{
				return GoToPlayer;
			}
	
			if (FVector::Distance(AIController->GetPawn()->GetActorLocation(), 
				BlackboardComponent->GetValueAsVector(PatrolLocationKey)) <= 100.f)
			{
				return Wait;
			}
			
			return nullptr;
		}
	);



	Wait = MakeShared <FAIVState>(
		[this](AAIController* AIController, UBlackboardComponent* BlackboardComponent)
		{
			FTimerHandle TimerHandle;
			GetWorldTimerManager().SetTimer(TimerHandle, this, &AEnemyAIController::OnTimerElapsed, 2.f, false);
		},
		nullptr,
		[this](AAIController* AIController, UBlackboardComponent* BlackboardComponent, const float DeltaTime) -> TSharedPtr<FAIVState>
		{
			if (BlackboardComponent->GetValueAsBool(PlayerSeenKey))
			{
				return GoToPlayer;
			}

			return nullptr;
		}
	);

	StartBehaviour();
}

void AEnemyAIController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (CurrentState)
	{
		CurrentState = CurrentState->CallTick(this, Blackboard, DeltaTime);
	}
}

void AEnemyAIController::StartBehaviour()
{
	CurrentState = SearchForBall;
	CurrentState->CallEnter(this, Blackboard);
}

void AEnemyAIController::OnPerception(AActor* InActor, FAIStimulus InStimulus)
{
	if (InActor->ActorHasTag(TEXT("Player")))
	{
		Blackboard->SetValueAsBool(PlayerSeenKey, InStimulus.WasSuccessfullySensed());
	}
	else
	{
		Blackboard->SetValueAsBool(PlayerSeenKey, false);
	}
}

void AEnemyAIController::OnTimerElapsed()
{	
	if (CurrentState == Wait)
	{
		CurrentState = SearchForPatrolPoint;
		CurrentState->CallEnter(this, Blackboard);
	}
}
















