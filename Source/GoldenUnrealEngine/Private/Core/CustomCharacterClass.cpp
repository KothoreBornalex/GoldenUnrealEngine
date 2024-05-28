// Fill out your copyright notice in the Description page of Project Settings.


#include "Core/CustomCharacterClass.h"
//#include "GoldenUnrealEngineProjectile.h"
#include "AC_EntitiesComponent.h"
#include "AC_StatsComponent.h"
#include "PDA_StatsClass.h"

#include "Animation/AnimInstance.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/SkeletalMeshComponent.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "InputActionValue.h"
#include "Engine/LocalPlayer.h"
#include "GameFramework/SpringArmComponent.h"


//////////////////////////////////////////////////////////////////////////
// AGoldenUnrealEngineCharacter

ACustomCharacterClass::ACustomCharacterClass()
{


	//// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(55.f, 96.0f);

	//CameraSpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraSpringArm"));
	//CameraSpringArm->SetupAttachment(GetCapsuleComponent());
	//CameraSpringArm->SetRelativeLocation(FVector(-10.f, 0.f, 60.f)); // Position the camera

	//// Create a CameraComponent	
	//FirstPersonCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("FirstPersonCamera"));
	//FirstPersonCameraComponent->SetupAttachment(CameraSpringArm);
	//FirstPersonCameraComponent->bUsePawnControlRotation = true;

	//// Create a mesh component that will be used when being viewed from a '1st person' view (when controlling this pawn)
	//Mesh1P = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("CharacterMesh1P"));
	//Mesh1P->SetOnlyOwnerSee(true);
	//Mesh1P->SetupAttachment(FirstPersonCameraComponent);
	//Mesh1P->bCastDynamicShadow = false;
	//Mesh1P->CastShadow = false;
	////Mesh1P->SetRelativeRotation(FRotator(0.9f, -19.19f, 5.2f));
	//Mesh1P->SetRelativeLocation(FVector(-30.f, 0.f, -150.f));




	EntitiesComponent = CreateDefaultSubobject<UAC_EntitiesComponent>("Entities Component");
	StatsComponent = CreateDefaultSubobject<UAC_StatsComponent>("Stats Component");
}




void ACustomCharacterClass::BeginPlay()
{
	// Call the base class  
	Super::BeginPlay();

}

void ACustomCharacterClass::PossessedBy(AController* NewController)
{
	
}
