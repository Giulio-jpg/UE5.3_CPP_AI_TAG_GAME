# About

I did this simple project to familiarise myself with Unreal's API for AI and the use of C++ in Unreal.

NPCs move around the map to get spheres, and when they have one they go looking for the player. 
Once they have seen him they go towards him to leave the ball and come back for another one. 
When there are no more spheres they wait for them to be respawned





https://github.com/user-attachments/assets/a5f68452-087b-46f2-9c18-bcff4a748608




## State Machine

To manage NPCs behavior, I created a state machine.

I created a structure representing a state, which has 3 functions that are called at the beginning, at the end and during the execution of the state.

The EnemyAIController Tick will call the state Tick method, which always returns a state, in case it needs to change to a new state. Otherwise it returns the state itself.

``` c                                                                        
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
```

Then in the Begin method of the EnemyAIController, I defined the functions that will be called by each state via lambdas


## AI components

It was a bit tricky to figure out how to make unreal AI components work, since C++ documentation.

I set up the components I needed in the EnemyAIController constructor.

To use the EnemyAIController Blackboard, I used a temporary variable, because of how the new UE5 TObjectPtr are implemented:

``` c                                                                        
UBlackboardData* BlackboardAsset = CreateDefaultSubobject<UBlackboardData>(TEXT("BlackboardDataAsset"));
Blackboard = CreateDefaultSubobject<UBlackboardComponent>(TEXT("Blackboard"));

BlackboardAsset->UpdatePersistentKey<UBlackboardKeyType_Object>(TargetBallKey);
BlackboardAsset->UpdatePersistentKey<UBlackboardKeyType_Vector>(PatrolLocationKey);
BlackboardAsset->UpdatePersistentKey<UBlackboardKeyType_Bool>(PlayerSeenKey);

UBlackboardComponent* BlackboardTemp = Blackboard.Get();
UseBlackboard(BlackboardAsset, BlackboardTemp);
Blackboard = BlackboardTemp;
```

To use Perception Component, it was necessary to create a delegate that had this signature:

``` c                                                                        
void OnPerception(AActor* InActor, FAIStimulus InStimulus);
```
``` c                                                                        
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
PerceptionComponent->OnTargetPerceptionUpdated.AddDynamic(this, &AEnemyAIController::OnPerception);
```


























