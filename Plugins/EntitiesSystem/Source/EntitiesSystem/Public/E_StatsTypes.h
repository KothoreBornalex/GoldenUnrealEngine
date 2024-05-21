// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

UENUM(BlueprintType)
enum class EStatsTypes : uint8 {
    DEFAULT       UMETA(DisplayName = "Default"),
    HEALTH        UMETA(DisplayName = "Health"),
    ARMOR        UMETA(DisplayName = "Armor"),
    STAMINA        UMETA(DisplayName = "Stamina"),
};