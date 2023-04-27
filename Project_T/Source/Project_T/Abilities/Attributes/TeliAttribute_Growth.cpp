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
	// GE에서 Instance로 값을 변경하면 Base가 변경됨. 아래의 PreAttributeChange 를 하면 Current가 변경됨. 그래서 BaseChange 함수는 계속 쌓이는 문제가 발생.
	if (NewValue > GetMaxGrowthMaterial())
	{
		NewValue = 1.0f;
	}
}

void UTeliAttribute_Growth::PreAttributeChange(const FGameplayAttribute& Attribute, float& NewValue)
{
	// 변경하기 전에 들어오는 함수.
	// NewValue를 변경하면 값 바뀌고 PostAttributeChange의 NewValue에 수정된 값으로 넘어간다. 

	if (NewValue > GetMaxGrowthMaterial())
	{
		NewValue = 1.0f;
	}
}

void UTeliAttribute_Growth::PostAttributeChange(const FGameplayAttribute& Attribute, float OldValue, float NewValue)
{
	// 값이 변경되면 들어오는 함수.

	ValueChangeEvent.ExecuteIfBound(NewValue);
}

void UTeliAttribute_Growth::OnRep_GrowthMaterial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTeliAttribute_Growth, GrowthMaterial, OldValue);
	
	// relativescaled3d rep 되는 걸로 나와있음.
	ValueChangeEvent.ExecuteIfBound(GrowthMaterial.GetCurrentValue());
}

void UTeliAttribute_Growth::OnRep_MaxGrowthMaterial(const FGameplayAttributeData& OldValue)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UTeliAttribute_Growth, MaxGrowthMaterial, OldValue);
}