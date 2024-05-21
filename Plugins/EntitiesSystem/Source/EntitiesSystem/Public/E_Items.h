#pragma once

UENUM(BlueprintType)
enum class EItemType : uint8 {
    DEFAULT       UMETA(DisplayName = "Default"),
    WEAPON        UMETA(DisplayName = "Weapon"),
    TOOL        UMETA(DisplayName = "Tool"),
    CONSUMMABLE        UMETA(DisplayName = "Consummable"),
    RESSOURCE        UMETA(DisplayName = "Ressource"),
};