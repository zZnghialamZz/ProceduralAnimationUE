// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class ProceduralAnimEditorTarget : TargetRules
{
	public ProceduralAnimEditorTarget( TargetInfo Target) : base(Target)
	{
		Name = "ProceduralAnimEditor";
		
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_1;
		ExtraModuleNames.AddRange(new [] { "ProceduralAnim", "ProceduralAnimEditor" });
	}
}
