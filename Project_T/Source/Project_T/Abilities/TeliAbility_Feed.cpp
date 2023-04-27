// Fill out your copyright notice in the Description page of Project Settings.


#include "Abilities/TeliAbility_Feed.h"
#include "Character/TeliCharacter.h"

#include "AbilitySystemComponent.h"

UTeliAbility_Feed::UTeliAbility_Feed()
	:SensingDistance(50.0f)
{

}

void UTeliAbility_Feed::ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData)
{
	Super::ActivateAbility(Handle, ActorInfo, ActivationInfo, TriggerEventData);


	if (IsLocallyControlled() == true)
	{
		AActor* Target = FindTarget();

		if (Target == nullptr)
		{
			K2_CancelAbility();
			return;
		}

		Server_GiveItem(Target);
	}


	//UseItem();
}


void UTeliAbility_Feed::UseItem()
{
	if (FindTarget() == nullptr)
	{
		return ;
	}


	TWeakObjectPtr<ATeliCharacter> Poro = Cast<ATeliCharacter>(FindTarget());
	if (Poro == nullptr)
	{
		return;
	}
	UAbilitySystemComponent* TargetASC = Poro->GetAbilitySystemComponent();

	//  TODO :Inventory Item 감소
	UE_LOG(LogTemp, Warning, TEXT("UseItem Active"));

	//	포로 effect
	GiveItem(TargetASC);
	
}


AActor* UTeliAbility_Feed::FindTarget()
{
	UWorld* World = GetWorld();

	if (World == nullptr)
	{
		return nullptr;
	}

	
	const FTransform& Transform = GetActorInfo().AvatarActor->GetTransform();

	FCollisionObjectQueryParams ObjQueryParams;
	ObjQueryParams.AddObjectTypesToQuery(ECollisionChannel::ECC_Pawn);

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(GetActorInfo().AvatarActor.Get());

	TArray<FOverlapResult> OverlapResults;
	World->OverlapMultiByObjectType(OverlapResults, Transform.GetLocation(), Transform.GetRotation(), ObjQueryParams, FCollisionShape::MakeSphere(SensingDistance), QueryParams);

	DrawDebugSphere(World, Transform.GetLocation(), SensingDistance, 1, FColor::Red);

	if (OverlapResults.Num() <= 0)
	{
		return nullptr;
	}

	// temp
	return OverlapResults[0].GetActor();

}

void UTeliAbility_Feed::GiveItem(UAbilitySystemComponent* TargetASC)
{
	if (TargetASC == nullptr)
	{
		K2_CancelAbility();
		return;
	}

	FActiveGameplayEffectHandle Handle = TargetASC->ApplyGameplayEffectToSelf(FeedEffect->GetDefaultObject<UGameplayEffect>(), 1.0f, TargetASC->MakeEffectContext());
	if (Handle.WasSuccessfullyApplied() == true)
	{
		K2_EndAbility();
	}
	else
	{
		K2_CancelAbility();
	}
}

void UTeliAbility_Feed::Server_GiveItem_Implementation(AActor* Target)
{
	if (Target == nullptr)
	{
		K2_CancelAbility();
		return;
	}

	TWeakObjectPtr<ATeliCharacter> Poro = Cast<ATeliCharacter>(Target);
	if (Poro == nullptr)
	{
		K2_CancelAbility();
		return;
	}

	UAbilitySystemComponent* TargetASC = Poro->GetAbilitySystemComponent();

	//  TODO :Inventory Item 감소
	UE_LOG(LogTemp, Warning, TEXT("UseItem Active"));

	//	포로 effect
	GiveItem(TargetASC);
}