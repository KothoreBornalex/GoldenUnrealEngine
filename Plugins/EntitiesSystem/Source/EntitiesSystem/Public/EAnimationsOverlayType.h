// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EAnimationsOverlayType.generated.h"

UENUM(BlueprintType)
enum class EAnimationsOverlayType : uint8 {
    DEFAULT       UMETA(DisplayName = "Default"),
    RIFLE       UMETA(DisplayName = "Rifle"),
    PISTOL_ONE_HANDED       UMETA(DisplayName = "Pistol One Handed"),
    PISTOL_TWO_HANDED       UMETA(DisplayName = "Pistol Two Handed"),
    BINOCULARS        UMETA(DisplayName = "Binoculars"),
    BOX        UMETA(DisplayName = "Box"),
    BARREL        UMETA(DisplayName = "Barrel"),
};