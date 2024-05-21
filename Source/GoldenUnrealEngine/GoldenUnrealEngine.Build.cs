// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GoldenUnrealEngine : ModuleRules
{
	public GoldenUnrealEngine(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
