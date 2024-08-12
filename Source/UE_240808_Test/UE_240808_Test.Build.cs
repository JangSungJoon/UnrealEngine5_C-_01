// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE_240808_Test : ModuleRules
{
	public UE_240808_Test(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput" });
	}
}
