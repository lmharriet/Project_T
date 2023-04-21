// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/TeliCharacter.h"
#include "Character/TeliCharacterMovementComponent.h"
#include "Abilities/TeliAbilitySystemComponent.h"

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