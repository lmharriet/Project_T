// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/Attributes/TeliAttributeSetBase.h"
#include "Abilities/TeliAbilitySystemComponent.h"

UTeliAbilitySystemComponent* UTeliAttributeSetBase::GetTeliAbilitySystemComponent() const
{
	return Cast<UTeliAbilitySystemComponent>(GetOwningAbilitySystemComponent());
}