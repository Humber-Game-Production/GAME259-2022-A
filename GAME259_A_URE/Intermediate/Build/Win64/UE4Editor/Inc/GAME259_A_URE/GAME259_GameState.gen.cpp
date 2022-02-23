// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GAME259_A_URE/GAME259_GameState.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGAME259_GameState() {}
// Cross Module References
	GAME259_A_URE_API UClass* Z_Construct_UClass_AGAME259_GameState_NoRegister();
	GAME259_A_URE_API UClass* Z_Construct_UClass_AGAME259_GameState();
	ENGINE_API UClass* Z_Construct_UClass_AGameStateBase();
	UPackage* Z_Construct_UPackage__Script_GAME259_A_URE();
// End Cross Module References
	void AGAME259_GameState::StaticRegisterNativesAGAME259_GameState()
	{
	}
	UClass* Z_Construct_UClass_AGAME259_GameState_NoRegister()
	{
		return AGAME259_GameState::StaticClass();
	}
	struct Z_Construct_UClass_AGAME259_GameState_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGAME259_GameState_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameStateBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GAME259_A_URE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGAME259_GameState_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "GAME259_GameState.h" },
		{ "ModuleRelativePath", "GAME259_GameState.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGAME259_GameState_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGAME259_GameState>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGAME259_GameState_Statics::ClassParams = {
		&AGAME259_GameState::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGAME259_GameState_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGAME259_GameState_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGAME259_GameState()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGAME259_GameState_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGAME259_GameState, 573152849);
	template<> GAME259_A_URE_API UClass* StaticClass<AGAME259_GameState>()
	{
		return AGAME259_GameState::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGAME259_GameState(Z_Construct_UClass_AGAME259_GameState, &AGAME259_GameState::StaticClass, TEXT("/Script/GAME259_A_URE"), TEXT("AGAME259_GameState"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGAME259_GameState);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
