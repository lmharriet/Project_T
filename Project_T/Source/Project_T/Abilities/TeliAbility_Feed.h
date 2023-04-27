// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/TeliGameplayAbility.h"
#include "TeliAbility_Feed.generated.h"

/**
 * 
 */


// 먹이주기 어빌리티


UCLASS()
class PROJECT_T_API UTeliAbility_Feed : public UTeliGameplayAbility
{
	GENERATED_BODY()
	

public:

	UTeliAbility_Feed();
public:
	
	// Inventory Item 소모
	UFUNCTION(BlueprintCallable)
	void UseItem();

protected:

	// Server, Client 실행 
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;

private:
	// 콜리젼 검사.
	AActor* FindTarget();

	// gameplayEffect..?
	void GiveItem(UAbilitySystemComponent* TargetASC);


	UFUNCTION(Server, Reliable)
		void Server_GiveItem(AActor* Target);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Teli|GameplayEffect")
		TSubclassOf<UGameplayEffect> FeedEffect;

public:
	UPROPERTY(EditAnywhere,BlueprintReadWrite, Category = "Sensing")
	float SensingDistance;
};
