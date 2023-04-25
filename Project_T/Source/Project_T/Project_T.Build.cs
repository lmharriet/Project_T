// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class Project_T : ModuleRules
{
	public Project_T(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" , "UMG" , "Slate" });

		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayAbilities","GameplayTags","GameplayTasks"});

		PrivateIncludePaths.AddRange(new string[] { "Project_T" });

    }
}
