// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PDA_StatsClass.h"

#include "CustomCharacterClass.generated.h"

class UAC_StatsComponent;
class UAC_EntitiesComponent;
class UInputComponent;
class USkeletalMeshComponent;
class UCameraComponent;
class UInputAction;
class UInputMappingContext;
struct FInputActionValue;


UCLASS(BlueprintType)
class GOLDENUNREALENGINE_API ACustomCharacterClass : public ACharacter
{
	GENERATED_BODY()


public:
	ACustomCharacterClass();

	/** Pawn mesh: 1st person view (arms; seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* Mesh1P;

	/** First person camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Entities, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAC_EntitiesComponent> EntitiesComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Entities, meta = (AllowPrivateAccess = "true"))
	TObjectPtr<UAC_StatsComponent> StatsComponent;

protected:
	virtual void BeginPlay();

	virtual void PossessedBy(AController* NewController) override;



public:

	/** Returns Mesh1P subobject **/
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }
	/** Returns FirstPersonCameraComponent subobject **/
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }
};
