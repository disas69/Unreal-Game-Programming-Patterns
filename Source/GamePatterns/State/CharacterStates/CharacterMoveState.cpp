﻿// Game Programming Patterns, Eugene Esaulenko, 2024

#include "CharacterMoveState.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GamePatterns/TestActors/TestCharacter.h"

void UCharacterMoveState::OnEnter()
{
    Super::OnEnter();

    UE_LOG(LogTemp, Warning, TEXT("MoveState: OnEnter"));
}

void UCharacterMoveState::OnExit()
{
    Super::OnExit();

    UE_LOG(LogTemp, Warning, TEXT("MoveState: OnExit"));
}

void UCharacterMoveState::Update(float DeltaTime)
{
    Super::Update(DeltaTime);

    const bool bIsMoving = OwnerCharacter->GetVelocity().SizeSquared() > 0.0f;
    const bool bIsFalling = OwnerCharacter->GetCharacterMovement()->IsFalling();

    if (bWasMoving && !bIsMoving && !bIsFalling)
    {
        const ATestCharacter* TestCharacter = Cast<ATestCharacter>(OwnerCharacter);
        if (TestCharacter != nullptr)
        {
            TestCharacter->SetState(ETestCharacterState::Idle);
        }
    }

    bWasMoving = bIsMoving;
}