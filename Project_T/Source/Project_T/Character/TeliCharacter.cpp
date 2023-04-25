// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TeliCharacter.h"
#include "Character/TeliCharacterMovementComponent.h"

#include "Components/CapsuleComponent.h"

#include "Abilities/TeliAbilitySystemComponent.h"

#include "AttributeSet.h"
#include "Abilities/Attributes/TeliAttribute_Growth.h"



// Sets default values
ATeliCharacter::ATeliCharacter(const FObjectInitializer& ObjectInitializer)
	:Super(ObjectInitializer.SetDefaultSubobjectClass<UTeliCharacterMovementComponent>(ACharacter::CharacterMovementComponentName))
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CollisionChecker = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CollisionChecker"));
	CollisionChecker->SetupAttachment(RootComponent);
	CollisionChecker->SetCapsuleSize(SensingDistance, SensingDistance);


	AbilitySystemComponent = CreateDefaultSubobject<UTeliAbilitySystemComponent>(FName(TEXT("AbilitySystemComponent")));
	
	// Growth Attribute
	DefaultAttributeSet = Cast<UAttributeSet>(CreateDefaultSubobject<UTeliAttribute_Growth>(FName(TEXT("GrowthAttributeSet"))));

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
		PlayerInputComponent->BindAction(FName(TEXT("")), EInputEvent::IE_Pressed, this, &ATeliCharacter::OnPressedUsedItemKey);
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
	
}

void ATeliCharacter::OnPressedUsedItemKey()
{

	// 1. Inventory에 아이템이 있는지?
	// Temp 아이템 무한으로 진행 .

	// 2. target이 근처에 있는지?
	
	FHitResult HitResult;
	TObjectPtr<UWorld> World = GetWorld();
	if (!IsValid(World))
	{
		return;
	}

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	

#pragma region  Test Only

	// @TODO: Collision Checker로 변경하기
	FVector StartLoc = GetActorLocation();
	FVector EndLoc = StartLoc + (GetActorForwardVector() * 500.0f);
	World->LineTraceSingleByChannel(HitResult, StartLoc, EndLoc, ECC_Visibility, QueryParams);

	if (HitResult.GetActor() == nullptr || HitResult.GetActor()->IsValidLowLevel() == false)
	{
		return;
	}
#pragma endregion

	
	TWeakObjectPtr<ATeliCharacter> TargetChar = Cast<ATeliCharacter>(HitResult.GetActor());
	if (!IsValid(TargetChar.Get()))
	{
		return;
	}

	if (TargetChar->GetCharacterType() != ECharacterType::Gimmick_Growth)
	{
		return;
	}

	// 3. 성장시키기 어빌리티 실행 
	
	// 포로 밥
	if (AbilitySystemComponent != nullptr && AbilitySystemComponent->IsValidLowLevel() == true)
	{
		FGameplayTag UseItemTag = FGameplayTag::RequestGameplayTag(FName("Action.Growth"));
		
		AbilitySystemComponent->TryActivateAbilitiesByTag(FGameplayTagContainer(UseItemTag), true);
	}
}

void ATeliCharacter::OnReleassedUsedItemKey()
{
	
}

const ECharacterType& ATeliCharacter::GetCharacterType()
{
	return CharacterType;
}