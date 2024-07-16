﻿// Game Programming Patterns, Eugene Esaulenko, 2024

#include "CharacterJumpState.h"
#include "GameFramework/Character.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GamePatterns/GamePatternsTestCharacter.h"

void UCharacterJumpState::OnEnter()
{
    Super::OnEnter();

    UE_LOG(LogTemp, Warning, TEXT("JumpState: OnEnter"));
}

void UCharacterJumpState::OnExit()
{
    Super::OnExit();

    UE_LOG(LogTemp, Warning, TEXT("JumpState: OnExit"));
}

void UCharacterJumpState::Update(float DeltaTime)
{
    Super::Update(DeltaTime);

    UE_LOG(LogTemp, Warning, TEXT("JumpState: Update"));

    const bool bIsFalling = OwnerCharacter->GetCharacterMovement()->IsFalling();

    if (bWasFalling && !bIsFalling)
    {
        const AGamePatternsTestCharacter* TestCharacter = Cast<AGamePatternsTestCharacter>(OwnerCharacter);
        if (TestCharacter != nullptr)
        {
            TestCharacter->SetState(ETestCharacterState::Idle);
        }
    }

    bWasFalling = bIsFalling;
}