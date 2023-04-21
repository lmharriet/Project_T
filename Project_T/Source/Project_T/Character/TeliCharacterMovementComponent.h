// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "TeliCharacterMovementComponent.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_T_API UTeliCharacterMovementComponent : public UCharacterMovementComponent
{
	GENERATED_BODY()
	
public:

	UTeliCharacterMovementComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
public:
};
