// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


UENUM(BlueprintType)
enum class EEquippableAnimMontages : uint8 {
    Default    UMETA(DisplayName = "Default"),
    Shoot       UMETA(DisplayName = "Shoot"),
    Reload        UMETA(DisplayName = "Reload"),
    Use        UMETA(DisplayName = "Use"),
};