// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GAME259_A_URE/GAME259_A_UREGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGAME259_A_UREGameMode() {}
// Cross Module References
	GAME259_A_URE_API UClass* Z_Construct_UClass_AGAME259_A_UREGameMode_NoRegister();
	GAME259_A_URE_API UClass* Z_Construct_UClass_AGAME259_A_UREGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_GAME259_A_URE();
// End Cross Module References
	void AGAME259_A_UREGameMode::StaticRegisterNativesAGAME259_A_UREGameMode()
	{
	}
	UClass* Z_Construct_UClass_AGAME259_A_UREGameMode_NoRegister()
	{
		return AGAME259_A_UREGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AGAME259_A_UREGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGAME259_A_UREGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_GAME259_A_URE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGAME259_A_UREGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "GAME259_A_UREGameMode.h" },
		{ "ModuleRelativePath", "GAME259_A_UREGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGAME259_A_UREGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGAME259_A_UREGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGAME259_A_UREGameMode_Statics::ClassParams = {
		&AGAME259_A_UREGameMode::StaticClass,
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
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AGAME259_A_UREGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGAME259_A_UREGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGAME259_A_UREGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGAME259_A_UREGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGAME259_A_UREGameMode, 2060001692);
	template<> GAME259_A_URE_API UClass* StaticClass<AGAME259_A_UREGameMode>()
	{
		return AGAME259_A_UREGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGAME259_A_UREGameMode(Z_Construct_UClass_AGAME259_A_UREGameMode, &AGAME259_A_UREGameMode::StaticClass, TEXT("/Script/GAME259_A_URE"), TEXT("AGAME259_A_UREGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGAME259_A_UREGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
