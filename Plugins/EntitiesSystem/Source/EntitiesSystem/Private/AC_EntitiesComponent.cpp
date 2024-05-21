// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_EntitiesComponent.h"
#include "PickUpItem.h"
#include <GI_EntitiesGameInstanceClass.h>
#include <Kismet/GameplayStatics.h>

#include "PDA_ItemClass.h"

// Sets default values for this component's properties
UAC_EntitiesComponent::UAC_EntitiesComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;

	// ...
}


// Called when the game starts
void UAC_EntitiesComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}



void UAC_EntitiesComponent::Interacting(APlayerController* PlayerInteracting)
{
	FVector Start = PlayerInteracting->PlayerCameraManager->GetCameraLocation();

	FVector End = Start + PlayerInteracting->PlayerCameraManager->GetCameraRotation().Vector() * 500.0f;

	FHitResult HitResult;
	float SphereRadius = 25.0f; // Adjust the sphere radius as needed
	FCollisionQueryParams Params;
	Params.AddIgnoredActor(GetOwner());
	if (GetWorld()->LineTraceSingleByChannel(HitResult, Start, End, ECC_Visibility, Params))
	{
		//DrawDebugLine(GetWorld(), Start, HitResult.ImpactPoint, FColor::Red, false, 3.0f, 0, 2.0f);

		if (HitResult.GetActor()->Implements<UInteractInterface>())
		{
			IInteractInterface::Execute_Interact(HitResult.GetActor(), PlayerInteracting);
		}
		else if (GetWorld()->SweepSingleByChannel(HitResult, HitResult.ImpactPoint, HitResult.ImpactPoint, FQuat::Identity, ECC_Visibility, FCollisionShape::MakeSphere(SphereRadius), Params))
		{
			//DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, SphereRadius, 32, FColor::Red, false, 3.0f, 0, 2.0f);

			if (HitResult.GetActor()->Implements<UInteractInterface>())
			{
				IInteractInterface::Execute_Interact(HitResult.GetActor(), PlayerInteracting);
			}
		}
	}
	else
	{
		//DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, 3.0f, 0, 2.0f);
	}
}







void UAC_EntitiesComponent::SpawnEntity(F_ItemSlot EntitySlot, int Count)
{

	TObjectPtr<APlayerCameraManager> CameraManager = Cast<APlayerController>(GetOwner()->GetInstigatorController())->PlayerCameraManager;

	FVector ForwardVector = CameraManager->GetCameraRotation().Vector() * 2000.0f;

	FVector StartPoint = CameraManager->GetCameraLocation();
	FVector EndPoint = CameraManager->GetCameraLocation() + ForwardVector;


	FHitResult HitResult;
	FCollisionQueryParams Params;

	//Params.AddIgnoredActor(WeaponMeshComponent);
	if (GetWorld()->LineTraceSingleByChannel(HitResult, StartPoint, EndPoint, ECC_Visibility, Params))
	{
		//DrawDebugLine(GetWorld(), StartPoint, HitResult.ImpactPoint, FColor::Red, false, 3.0f, 0, 2.0f);

		FActorSpawnParameters SpawnParameters;
		SpawnParameters.Owner = GetOwner();
		SpawnParameters.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AdjustIfPossibleButAlwaysSpawn;




		TObjectPtr<UGI_EntitiesGameInstanceClass> EntitiesGameInstance = Cast<UGI_EntitiesGameInstanceClass>(UGameplayStatics::GetGameInstance(GetWorld()));

		UPDA_EntityClass* Entity = EntitiesGameInstance->GetEntityData(EntitySlot);

		if(Entity->PhysicEntityActorClass)
		{
			TObjectPtr<APhysicEntities> EntityActor = Cast<APhysicEntities>(GetWorld()->SpawnActor(Entity->PhysicEntityActorClass, nullptr, nullptr, SpawnParameters));

			EntitySlot.ItemCount = Count;
			EntityActor->Server_Reliable_SetUpPhysicEntity(EntitySlot);

			EntityActor->SetActorLocation(HitResult.ImpactPoint + FVector(0, 0, 10.0f));
		}
		
	}else
	{
		//DrawDebugLine(GetWorld(), StartPoint, EndPoint, FColor::Red, false, 3.0f, 0, 2.0f);

	}
}