// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "TeliGlobalDefines.generated.h"

/**
 * 
 */

UENUM(BlueprintType)
enum class ECharacterType : uint8
{
	None,
	Player,
	Solder,
	Guardian,
	Doctor,
	Gimmick_Growth,
};


//UCLASS()
//class PROJECT_T_API UTeliGlobalDefines : public UObject
//{
//	GENERATED_BODY()
//	
//};
