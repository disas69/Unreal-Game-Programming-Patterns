﻿// Game Programming Patterns, Eugene Esaulenko, 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "../Command/FCommandStack.h"
#include "../EventQueue/FEventQueue.h"
#include "../ObjectPool/FActorPoolParams.h"
#include "TestActor.generated.h"

class UCharacterStateComponent;
class UActorPoolComponent;
class UActorPool;
class UActionCommand;

UCLASS()
class GAMEPATTERNS_API ATestActor : public AActor
{
    GENERATED_BODY()

public:
    ATestActor();

    UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Object Pool")
    UActorPoolComponent* ActorPoolComponent = nullptr;

    UPROPERTY(EditDefaultsOnly, Category = "Object Pool")
    FVector SpawnLocation = FVector::ZeroVector;

    UPROPERTY(EditDefaultsOnly, Category = "Object Pool")
    float SpawnInterval = 1.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Object Pool")
    float ReturnInterval = 1.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Command Stack")
    FCommandStack CommandStack;

    UPROPERTY(EditDefaultsOnly, Category = "Event Queue")
    FEventQueue EventQueue;

    UPROPERTY(EditDefaultsOnly, Category = "Event Queue")
    float EventQueueInterval = 1.0f;

    virtual void Tick(float DeltaTime) override;

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    FTimerHandle SpawnTimerHandle;
    FTimerHandle ReturnTimerHandle;
    FTimerHandle EventQueueTimerHandle;

    UPROPERTY()
    TArray<APooledActor*> ActiveActors;

    UPROPERTY()
    TArray<UActionCommand*> Commands;

    void StartObjectPoolTest();
    void SpawnPooledActor();
    void ReturnActorToPool();
    void StartCommandStackTest();
    void StartStateMachineTest();
    void StartServiceLocatorTest();
    void StartEventQueueTest();
    void EnqueueEvent();
};
