// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/Attributes/TeliAttribute_Growth.h"

#include "Net/UnrealNetwork.h"
#include "Abilities/TeliAbilitySystemComponent.h"


UTeliAttribute_Growth::UTeliAttribute_Growth()
	:GrowthMaterial(1.0f)
	, MaxGrowthMaterial(5.0f)
{

}

void UTeliAttribute_Growth::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UTeliAttribute_Growth, GrowthMaterial, COND_None, REPNOTIFY_Always);

	// TODO : Check if it will be changed quite often
	DOREPLIFETIME_CONDITION_NOTIFY(UTeliAttribute_Growth, MaxGrowthMaterial, COND_InitialOnly, REPNOTIFY_OnChanged);
}

void UTeliAttribute_Growth::PreAttributeBaseChange(const FGameplayAttribute& Attribute, float& NewValue) const
{
	// GE���� Instance�� ���� �����ϸ� Base�� �����. �Ʒ��� PreAttributeChange �� �ϸ� Current�� �����. �׷��� BaseChange �Լ��� ��� ���̴� ������ �߻�.
	if (NewValue > GetMaxGrowthMaterial())
	{
		NewValue = 1.0f;
	}
}

void UTeliAttribute_Growth::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	// �����ϱ� ���� ������ �Լ�.
	// NewValue�� �����ϸ� �� �ٲ�� PostAttributeChange�� NewValue�� ������ ������ �Ѿ��. 

	if (NewValue > GetMaxGrowthMaterial())
	{
		NewValue = 1.0f;
	}
}

void UTeliAttribute_Growth::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	// ���� ����Ǹ� ������ �Լ�.

	ValueChangeEvent.ExecuteIfBound(NewValue);
}

void UTeliAttribute_Growth::OnRep_GrowthMaterial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTeliAttribute_Growth, GrowthMaterial, OldValue);
	
	// relativescaled3d rep �Ǵ� �ɷ� ��������.
	ValueChangeEvent.ExecuteIfBound(GrowthMaterial.GetCurrentValue());
}

void UTeliAttribute_Growth::OnRep_MaxGrowthMaterial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTeliAttribute_Growth, MaxGrowthMaterial, OldValue);
}