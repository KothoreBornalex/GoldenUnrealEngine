#pragma once

#include "CoreMinimal.h"

#include "EquippableActorClass.generated.h"

class UNiagaraComponent;
class UArrowComponent;

UCLASS()
class WEAPONSSYSTEM_API AEquippableActorClass : public AActor
{
	GENERATED_BODY()

public:
	AEquippableActorClass();

protected:
	virtual void BeginPlay() override;


public:

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TObjectPtr<UStaticMeshComponent> EquippableMeshComponent;

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UNiagaraComponent> VFXComponent;

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UArrowComponent> ArrowComponent;

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UChildActorComponent> MuzzleActorComponent;

	UPROPERTY(BlueprintReadWrite)
	TObjectPtr<UPrimaryDataAsset> EquippableItemData;

	UFUNCTION(Client, Reliable)
	void Client_Reliable_SetUpEquippableActor(FName ItemID, AActor* PawnActor);

	UFUNCTION(NetMulticast, Reliable)
	void NetMulticast_Reliable_SetUpEquippableActor(FName ItemID, AActor* PawnActor);

	UFUNCTION(BlueprintImplementableEvent)
	void SetUpBlueprintEvent(FName ItemID, AActor* PawnActor, bool IsOwner);
};