﻿// Game Programming Patterns, Eugene Esaulenko, 2024

#pragma once

#include "CoreMinimal.h"
#include "Command/FCommandStack.h"
#include "GameFramework/Actor.h"
#include "ObjectPool/FActorPool.h"
#include "GamePatternsTestActor.generated.h"

class UActionCommand;

UCLASS()
class GAMEPATTERNS_API AGamePatternsTestActor : public AActor
{
    GENERATED_BODY()

public:
    AGamePatternsTestActor();

    virtual void Tick(float DeltaTime) override;

    UPROPERTY(EditDefaultsOnly, Category = "Object Pool")
    FActorPool ActorPool;

    UPROPERTY(EditDefaultsOnly, Category = "Object Pool")
    FVector SpawnLocation = FVector::ZeroVector;

    UPROPERTY(EditDefaultsOnly, Category = "Object Pool")
    float SpawnInterval = 1.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Object Pool")
    float ReturnInterval = 1.0f;

    UPROPERTY(EditDefaultsOnly, Category = "Command Stack")
    FCommandStack CommandStack;

protected:
    virtual void BeginPlay() override;
    virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

private:
    FTimerHandle SpawnTimerHandle;
    FTimerHandle ReturnTimerHandle;

    UPROPERTY()
    TArray<AActor*> ActiveActors;

    UPROPERTY()
    TArray<UActionCommand*> Commands;

    void StartObjectPoolTest();
    void SpawnPooledActor();
    void ReturnActorToPool();

    void StartCommandStackTest();
};
