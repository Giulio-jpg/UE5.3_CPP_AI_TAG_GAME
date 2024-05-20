// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Ball.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AIPerceptionTypes.h"
#include "EnemyAIController.generated.h"


struct FAIVState : public TSharedFromThis<FAIVState>
{
	FAIVState()
	{
		Enter = nullptr;
		Exit = nullptr;
		Tick = nullptr;
	}

	FAIVState(TFunction<void(AAIController*, UBlackboardComponent*)> InEnter = nullptr,
			  TFunction<void(AAIController*, UBlackboardComponent*)> InExit = nullptr,
		      TFunction<TSharedPtr<FAIVState>(AAIController*, UBlackboardComponent*, const float)> InTick = nullptr)
	{
		Enter = InEnter;
		Exit = InExit;
		Tick = InTick;
	}

	FAIVState(const FAIVState& Other) = delete;
	FAIVState& operator=(const FAIVState& Other) = delete;
	FAIVState(FAIVState&& Other) = delete;
	FAIVState& operator=(FAIVState&& Other) = delete;

	void CallEnter(AAIController* AIController, UBlackboardComponent* BlackboardComponent)
	{
		if (Enter)
		{
			Enter(AIController, BlackboardComponent);
		}
	}

	void CallExit(AAIController* AIController, UBlackboardComponent* BlackboardComponent)
	{
		if (Exit)
		{
			Exit(AIController, BlackboardComponent);
		}
	}

	TSharedPtr<FAIVState> CallTick(AAIController* AIController, UBlackboardComponent* BlackboardComponent, const float DeltaTime)
	{
		if (Tick)
		{
			TSharedPtr<FAIVState> NewState = Tick(AIController, BlackboardComponent, DeltaTime);

			if (NewState != nullptr && NewState != AsShared())
			{
				CallExit(AIController, BlackboardComponent);
				NewState->CallEnter(AIController, BlackboardComponent);
				return NewState;
			}
		}

		return AsShared();
	}



protected:
	TFunction<void(AAIController*, UBlackboardComponent*)> Enter;
	TFunction<void(AAIController*, UBlackboardComponent*)> Exit;
	TFunction<TSharedPtr<FAIVState>(AAIController*, UBlackboardComponent*, const float)> Tick;

};




UCLASS()
class TAGGAME_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()
	
public:
	AEnemyAIController();
	void StartBehaviour();

	UFUNCTION()
	void OnPerception(AActor* InActor, FAIStimulus InStimulus);

	UFUNCTION()
	void OnTimerElapsed();

protected:
	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	TSharedPtr<FAIVState> CurrentState;

	TSharedPtr<FAIVState> GoToPlayer;
	TSharedPtr<FAIVState> GoToBall;
	TSharedPtr<FAIVState> GrabBall;
	TSharedPtr<FAIVState> SearchForBall;
	TSharedPtr<FAIVState> SearchForPatrolPoint;
	TSharedPtr<FAIVState> Patrol;
	TSharedPtr<FAIVState> Wait;

	FName TargetBallKey;
	FName PatrolLocationKey;
	FName PlayerSeenKey;

	UAISenseConfig_Sight* Sight;
};
