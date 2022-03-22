// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GAME259_A_URE : ModuleRules
{
	public GAME259_A_URE(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" , "OnlineSubsystem", "OnlineSubsystemSteam"});
	}
}
