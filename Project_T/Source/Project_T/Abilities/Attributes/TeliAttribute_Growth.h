// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/Attributes/TeliAttributeSetBase.h"
#include "TeliAttribute_Growth.generated.h"


// ATTRIBUTE_ACCESSORS(UTeliAttributeSetBase, Health)

/**
 * 
 */
UCLASS()
class PROJECT_T_API UTeliAttribute_Growth : public UTeliAttributeSetBase
{
	GENERATED_BODY()


public:
	UTeliAttribute_Growth();
	

#pragma region AttributeSet Macros

	ATTRIBUTE_ACCESSORS(UTeliAttribute_Growth, GrowthMaterial);
	ATTRIBUTE_ACCESSORS(UTeliAttribute_Growth, MaxGrowthMaterial);

#pragma endregion

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	UFUNCTION()
	void OnRep_GrowthMaterial(const FGameplayAttributeData& OldValue);
	
	UFUNCTION()
	void OnRep_MaxGrowthMaterial(const FGameplayAttributeData& OldValue);


private:
	

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_GrowthMaterial, Category = "Teli|Material", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData GrowthMaterial;

	UPROPERTY(BlueprintReadOnly, ReplicatedUsing = OnRep_MaxGrowthMaterial, Category = "Teli|Material", Meta = (AllowPrivateAccess = true))
	FGameplayAttributeData MaxGrowthMaterial;
		
};
