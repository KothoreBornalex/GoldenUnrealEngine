#pragma once

UENUM(BlueprintType)
enum class EEntityType : uint8 {
    ITEM       UMETA(DisplayName = "Item"),
    PROPS        UMETA(DisplayName = "Props"),
    NPC        UMETA(DisplayName = "NPC"),
};