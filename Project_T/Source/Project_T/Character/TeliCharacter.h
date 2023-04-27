// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "TeliGlobalDefines.h"
#include "TeliCharacter.generated.h"

class UAbilitySystemComponent;
class UTeliAbilitySystemComponent;

class UAttributeSet;
class UGameplayAbility;


UCLASS()
class PROJECT_T_API ATeliCharacter : public ACharacter , public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ATeliCharacter(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get());
	

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void PossessedBy(AController* NowController) override;


	void OnPressedUsedItemKey();
	void OnReleassedUsedItemKey();

	void MoveFowrad(float Value);
	void MoveLeft(float Value);


	const ECharacterType& GetCharacterType();
	
public:
	//	~ IAbilitySystemInterface 
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	//	~ end IAbilitySystemInterface

	//	캐릭터별 사용가능한 어빌리티 세팅
	virtual void SetDefaultAbilities();
	

	// attributeset은 defaultsubobject로 생성만 해도 되는 이유??? 
	//	사용할 기본 어트리뷰트셋 세팅
	//virtual void SetDefaultAttributeSet();
	
	

	// Test Func
	void FeedValueChange(float Value);

protected:

	
	//UAttributeSet* DefaultAttributeSet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Teli | Attribute")
	TSubclassOf<UAttributeSet> DefaultAttributeSet;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Teli | Attribute")
	TArray<TSubclassOf<UGameplayAbility>> Abilities;

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Teli | Charcter")
	ECharacterType CharacterType;

private:

	UPROPERTY(Transient)
	TObjectPtr<UTeliAbilitySystemComponent> AbilitySystemComponent;




#pragma region Input Action

	//UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	//	class UInputAction* UseItemAction;
#pragma endregion


	bool OnUsingItem;

	FVector DefaultScaled3D;

};
