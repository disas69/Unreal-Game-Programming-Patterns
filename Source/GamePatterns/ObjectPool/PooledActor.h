﻿// Game Programming Patterns, Eugene Esaulenko, 2024

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PooledActor.generated.h"

class UActorPool;
struct FActorPoolParams;

UCLASS()
class GAMEPATTERNS_API APooledActor : public AActor
{
    GENERATED_BODY()

public:
    APooledActor();

    virtual void Tick(float DeltaTime) override;

    virtual void Initialize(UActorPool* Pool);
    virtual void OnSpawnFromPool();
    virtual void OnReturnToPool();

    void Return();

protected:
    virtual void BeginPlay() override;

private:
    UPROPERTY()
    UActorPool* OwnerPool = nullptr;
};
