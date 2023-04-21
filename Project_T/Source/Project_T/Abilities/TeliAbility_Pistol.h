// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/TeliGameplayAbility.h"
#include "TeliAbility_Pistol.generated.h"

/**
 * 
 */
UCLASS()
class PROJECT_T_API UTeliAbility_Pistol : public UTeliGameplayAbility
{
	GENERATED_BODY()
	
public:

	UTeliAbility_Pistol();
public:

	// Ÿ�� ã�� ����

	AActor* FindTarget();
	void TryShoot();


private:

	float Disance;
};
