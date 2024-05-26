// Fill out your copyright notice in the Description page of Project Settings.


#include "AC_WeaponComponent.h"
#include "Containers/Array.h"

#include "Engine/SkeletalMeshSocket.h"
#include <Kismet/GameplayStatics.h>
#include <PDA_WeaponDataClass.h>
#include "NiagaraComponent.h"
#include <DrawDebugHelpers.h>
#include "Engine/DecalActor.h"
#include "Components/DecalComponent.h"
#include "Engine/DamageEvents.h"

// Sets default values for this component's properties
UAC_WeaponComponent::UAC_WeaponComponent()
{
	MuzzleFlashComponent = CreateDefaultSubobject<UNiagaraComponent>("MuzzleFlashComponent");

	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = false;
}

void UAC_WeaponComponent::OnComponentCreated()
{
	Super::OnComponentCreated();

	// Set replication only if we're not running in the editor
	SetIsReplicated(true);
}


// Called when the game starts
void UAC_WeaponComponent::BeginPlay()
{
	Super::BeginPlay();
	
	// ...
}






void UAC_WeaponComponent::SetUpComponent(UStaticMeshComponent* MeshComponent, UNiagaraComponent* VFXComponent, UPrimaryDataAsset* NewWeaponData)
{
	
	WeaponMeshComponent = MeshComponent;
	MuzzleFlashComponent = VFXComponent;

	if(IsValid(NewWeaponData))
	{
		WeaponData = Cast<UPDA_WeaponDataClass>(NewWeaponData);

		FAttachmentTransformRules AttachmentParameter = FAttachmentTransformRules(EAttachmentRule::SnapToTarget, EAttachmentRule::SnapToTarget, EAttachmentRule::KeepRelative, false);
		MuzzleFlashComponent->AttachToComponent(WeaponMeshComponent, AttachmentParameter, WeaponData->MuzzleSocketName);

	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("New Weapon Data Is Not Valid"));
	}
}

void UAC_WeaponComponent::ShootByTracing()
{

	if(WeaponMeshComponent)
	{
		FVector StartPoint = WeaponMeshComponent->GetSocketLocation(WeaponData->MuzzleSocketName);


		FHitResult HitResult = FHitResult();
		FCollisionQueryParams Params;
		Params.AddIgnoredActor(GetOwner());


		//if (GetWorld()->LineTraceSingleByObjectType(HitResult, StartPoint, StartPoint + WeaponMeshComponent->GetForwardVector() * WeaponData->FireRange, FCollisionObjectQueryParams::AllObjects, Params))
		//{
		//	DrawDebugLine(GetWorld(), StartPoint, StartPoint + HitResult.ImpactPoint, FColor::Red, false, 10.0f, 0, 1);

		//	const FDamageEvent& DamageEvent = FDamageEvent::FDamageEvent();
		//	HitResult.GetActor()->TakeDamage(WeaponData->Damage, DamageEvent, GetOwner()->GetInstigatorController(), GetOwner());

		//	//ADecalActor* Decal = GetWorld()->SpawnActor<ADecalActor>(HitResult.ImpactPoint, HitResult.ImpactNormal.Rotation());
		//	//if (Decal)
		//	//{
		//	//	UE_LOG(LogTemp, Warning, TEXT("Decal Create with success"));
		//	//	FAttachmentTransformRules AttachmentRules = FAttachmentTransformRules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepRelative, true);

		//	//	//Decal->SetActorScale3D(FVector(1, 1, 1));
		//	//	Decal->SetDecalMaterial(WeaponData->BulletHoleMaterial);
		//	//	Decal->SetLifeSpan(7.5f);
		//	//	Decal->GetDecal()->DecalSize = FVector(6.4f, 6.4f, 6.4f);
		//	//	//Decal->AttachToComponent(HitResult.GetComponent(), AttachmentRules);

		//	//}
		//}
		//else
		//{
		//	DrawDebugLine(GetWorld(), StartPoint, StartPoint + WeaponMeshComponent->GetForwardVector() * WeaponData->FireRange, FColor::Red, false, 10.0f, 0, 1);
		//}

		if (GetWorld()->LineTraceSingleByChannel(HitResult, StartPoint, StartPoint + WeaponMeshComponent->GetForwardVector() * WeaponData->FireRange, ECollisionChannel::ECC_PhysicsBody, Params))
		{
			DrawDebugLine(GetWorld(), StartPoint, HitResult.ImpactPoint, FColor::Red, false, 10.0f, 0, 1);
			//UE_LOG(LogTemp, Warning, TEXT("Actor Hit Name: %s"), *HitResult.GetActor()->GetDebugName(HitResult.GetActor()));


			/*const FDamageEvent& DamageEvent = FDamageEvent::FDamageEvent();
			HitResult.GetActor()->TakeDamage(WeaponData->Damage, DamageEvent, GetOwner()->GetInstigatorController(), GetOwner());*/

			ApplyDamage(HitResult.GetActor(), WeaponData->Damage);



			//ADecalActor* Decal = GetWorld()->SpawnActor<ADecalActor>(HitResult.ImpactPoint, HitResult.ImpactNormal.Rotation());
			//if (Decal)
			//{
			//	UE_LOG(LogTemp, Warning, TEXT("Decal Create with success"));
			//	FAttachmentTransformRules AttachmentRules = FAttachmentTransformRules(EAttachmentRule::KeepWorld, EAttachmentRule::KeepWorld, EAttachmentRule::KeepRelative, true);

			//	//Decal->SetActorScale3D(FVector(1, 1, 1));
			//	Decal->SetDecalMaterial(WeaponData->BulletHoleMaterial);
			//	Decal->SetLifeSpan(7.5f);
			//	Decal->GetDecal()->DecalSize = FVector(6.4f, 6.4f, 6.4f);
			//	//Decal->AttachToComponent(HitResult.GetComponent(), AttachmentRules);

			//}
		}
		else
		{
			DrawDebugLine(GetWorld(), StartPoint, StartPoint + WeaponMeshComponent->GetForwardVector() * WeaponData->FireRange, FColor::Red, false, 10.0f, 0, 1);
		}

		ShootEffects();

		

	}else
	{
		UE_LOG(LogTemp, Warning, TEXT("WeaponMeshComponent  Not Found "));
	}

}

void UAC_WeaponComponent::ApplyDamage(AActor* Actor, float Damage)
{
	const FDamageEvent& DamageEvent = FDamageEvent::FDamageEvent();
	Actor->TakeDamage(Damage, DamageEvent, GetOwner()->GetInstigatorController(), GetOwner());
}

bool UAC_WeaponComponent::IsMagazineFull()
{
	if (AmmoInClip == WeaponData->ClipSize) return true;
	else
	{
		return false;
	}
}


void UAC_WeaponComponent::ShootEffects()
{
	//PrintEvent();

	if(WeaponData->MuzzleFlashEffect != nullptr)
	{
		MuzzleFlashComponent->ResetSystem();
		MuzzleFlashComponent->SetAsset(WeaponData->MuzzleFlashEffect);
		MuzzleFlashComponent->Activate(true);
	}
	

	if(WeaponData->ShootSounds.Num() > 0)
	{
		int32 Index = FMath::RandRange(0, WeaponData->ShootSounds.Num() - 1);
		UGameplayStatics::PlaySoundAtLocation(this, WeaponData->ShootSounds[Index], WeaponMeshComponent->GetComponentLocation());
	}
	
}