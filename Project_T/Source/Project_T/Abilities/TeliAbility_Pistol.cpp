// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/TeliAbility_Pistol.h"
#include "AbilitySystemComponent.h"

UTeliAbility_Pistol::UTeliAbility_Pistol()
	:Disance(1000.0f)
{
	
}


AActor* UTeliAbility_Pistol::FindTarget()
{
	if (GetAbilitySystemComponentFromActorInfo())
	{
		if (GetAbilitySystemComponentFromActorInfo()->GetAvatarActor())
		{
			// rayhit	
		}
	}

	return nullptr;
}

void UTeliAbility_Pistol::TryShoot()
{
	if (FindTarget())
	{
		UE_LOG(LogTemp, Warning, TEXT("UTeliAbility_Pistol::TryShoot"));

		// TODO : Apply Target GameplayEffect
	}
	//else
	//{
	//	// play anim only
	//}
}

