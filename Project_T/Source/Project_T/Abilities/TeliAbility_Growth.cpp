// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/TeliAbility_Growth.h"

#include "Abilities/TeliAbilitySystemComponent.h"

#include "GameplayEffect.h"

UTeliAbility_Growth::UTeliAbility_Growth()
{

}

// Character������ target�� ability�� �����ٰ� play �ϴ� �������� �ؾ��ϳ�?
// TODO : ���ΰ� ���� ability? ����? 


void UTeliAbility_Growth::UpdateGrowthMaterialCount()
{
	if (GetActorInfo().OwnerActor != nullptr)
	{
		UTeliAbilitySystemComponent* ASC = Cast<UTeliAbilitySystemComponent>(GetAbilitySystemComponentFromActorInfo());
		//ASC->ApplyGameplayEffectToTarget()
	
	}

}