// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "TeliGlobalDefines.h"
#include "TeliCharacter.generated.h"

class UAbilitySystemComponent;
class UTeliAbilitySystemComponent;

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

public:
	//	~ IAbilitySystemInterface 
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const;
	//	~ end IAbilitySystemInterface

	//	ĳ���ͺ� ��밡���� �����Ƽ ����
	virtual void SetDefaultAbilities();
	

	// attributeset�� defaultsubobject�� ������ �ص� �Ǵ� ����??? 
	//	����� �⺻ ��Ʈ����Ʈ�� ����
	//virtual void SetDefaultAttributeSet();
	

	


protected:

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Teli | Attribute")
	//	TSubclassOf<UAttribute>

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category = "Teli Charcter")
	ECharacterType CharacterType;

private:

	UPROPERTY(Transient)
	TObjectPtr<UTeliAbilitySystemComponent> AbilitySystemComponent;
	



};
