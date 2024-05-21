// Fill out your copyright notice in the Description page of Project Settings.


#include "EquippableActorClass.h"
#include "Engine/SkeletalMeshSocket.h"
#include <Kismet/GameplayStatics.h>
#include "NiagaraComponent.h"
#include "Components/ArrowComponent.h"

AEquippableActorClass::AEquippableActorClass()
{
    PrimaryActorTick.bCanEverTick = false;
    bReplicates = true;
    NetUpdateFrequency = 100.0f;

    ArrowComponent = CreateDefaultSubobject<UArrowComponent>("ArrowComponent");
    EquippableMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>("EquippableMeshComponent");
    EquippableMeshComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

    RootComponent = EquippableMeshComponent;

    VFXComponent = CreateDefaultSubobject<UNiagaraComponent>("VFXComponent");
    MuzzleActorComponent = CreateDefaultSubobject<UChildActorComponent>("MuzzleActorComponent");
}


// Called when the game starts or when spawned
void AEquippableActorClass::BeginPlay()
{
	Super::BeginPlay();
	
}

void AEquippableActorClass::Client_Reliable_SetUpEquippableActor_Implementation(FName ItemID, AActor* PawnActor)
{
    SetUpBlueprintEvent(ItemID, PawnActor, true);
}


void AEquippableActorClass::NetMulticast_Reliable_SetUpEquippableActor_Implementation(FName ItemID, AActor* PawnActor)
{
    SetUpBlueprintEvent(ItemID, PawnActor, false);
}