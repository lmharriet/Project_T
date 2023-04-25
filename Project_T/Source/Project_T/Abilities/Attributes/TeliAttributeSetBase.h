// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "TeliAttributeSetBase.generated.h"

/**
 * 
 */

class UTeliAbilitySystemComponent;

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
		GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)

UCLASS()
class PROJECT_T_API UTeliAttributeSetBase : public UAttributeSet
{
	GENERATED_BODY()
	
public:

	UTeliAbilitySystemComponent* GetTeliAbilitySystemComponent() const;
};
