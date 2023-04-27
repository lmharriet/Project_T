// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/TeliAbility_Growth.h"

#include "Abilities/TeliAbilitySystemComponent.h"

#include "GameplayEffect.h"

UTeliAbility_Growth::UTeliAbility_Growth()
{

}

// Character에서는 target의 ability를 가져다가 play 하는 방향으로 해야하나?
// TODO : 포로가 갖는 ability? 성장? 


void UTeliAbility_Growth::UpdateGrowthMaterialCount()
{
	if (GetActorInfo().OwnerActor != nullptr)
	{
		UTeliAbilitySystemComponent* ASC = Cast<UTeliAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo());
		//ASC->ApplyGameplayEffectToTarget()
	
	}

}