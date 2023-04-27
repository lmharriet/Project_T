// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TeliCharacter.h"
#include "Character/TeliCharacterMovementComponent.h"
//#include "Components/InputComponent.h"  // TODO : if use enhanced Input system.



#include "Abilities/TeliAbilitySystemComponent.h"

#include "AttributeSet.h"

#include "Abilities/GameplayAbility.h"

#include "Abilities/Attributes/TeliAttribute_Growth.h" 



// Sets default values
ATeliCharacter::ATeliCharacter(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer.SetDefaultSubobjectClass<UTeliCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;


	AbilitySystemComponent = CreateDefaultSubobject<UTeliAbilitySystemComponent>(FName(TEXT("AbilitySystemComponent")));


	if (AbilitySystemComponent)
	{
		AbilitySystemComponent->SetIsReplicated(true);
		AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);
	}
}

// Called when the game starts or when spawned
void ATeliCharacter::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority() == true)
	{
		if (AbilitySystemComponent)
		{
			if (DefaultAttributeSet != nullptr)
			{
				const UTeliAttribute_Growth* Attribute = Cast<UTeliAttribute_Growth>(AbilitySystemComponent->AddAttributeSetSubobject(NewObject<UAttributeSet>(this, DefaultAttributeSet)));
				//Attribute->SetEvent(FValueChange::BindUObject(this, &ATeliCharacter::FeedValueChange));
				
			}

			for (const TSubclassOf<UGameplayAbility>& Ability : Abilities)
			{
				AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec(Ability, 1, -1, this));
			}
		}
	}
}

// Called every frame
void ATeliCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void ATeliCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	if (IsValid(PlayerInputComponent))
	{
		PlayerInputComponent->BindAction(FName(TEXT("UserItem")), IE_Pressed, this, &ATeliCharacter::OnPressedUsedItemKey);
		PlayerInputComponent->BindAction(FName(TEXT("UserItem")), IE_Released, this, &ATeliCharacter::OnReleassedUsedItemKey);
	}

}

void ATeliCharacter::PossessedBy(AController* NowController)
{
	//check(NowController);


}

UAbilitySystemComponent* ATeliCharacter::GetAbilitySystemComponent() const
{
	return Cast<UAbilitySystemComponent>(AbilitySystemComponent);
}

void ATeliCharacter::SetDefaultAbilities()
{
	switch (GetCharacterType())
	{
	case ECharacterType::None:
	{
		break;
	}

	case ECharacterType::Player:
	{
		break;
	}

	case ECharacterType::Solder:
	{
		break;
	}

	case ECharacterType::Guardian:
	{
		break;
	}

	case ECharacterType::Doctor:
	{
		break;
	}

	case ECharacterType::Gimmick_Growth:
	{
		//AbilitySystemComponent->GiveAbility(FGameplayAbilitySpec)

		break;
	}

	default:
		break;
	}

}

void ATeliCharacter::OnPressedUsedItemKey()
{
	if (OnUsingItem == true)
	{
		return;
	}

	OnUsingItem = true;

	if (AbilitySystemComponent != nullptr && AbilitySystemComponent->IsValidLowLevel() == true)
	{
		FGameplayTag UseItemTag = FGameplayTag::RequestGameplayTag(FName("Action.Growth"));

		AbilitySystemComponent->TryActivateAbilitiesByTag(FGameplayTagContainer(UseItemTag), true);
	}

}

void ATeliCharacter::OnReleassedUsedItemKey()
{
	OnUsingItem = false;
}

const ECharacterType& ATeliCharacter::GetCharacterType()
{
	return CharacterType;
}



// Test Func
void ATeliCharacter::FeedValueChange(float Value)
{
	
	// Value + 
}
