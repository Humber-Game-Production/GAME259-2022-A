// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GAME259_A_URE/MyGAME259_A_URECharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyGAME259_A_URECharacter() {}
// Cross Module References
	GAME259_A_URE_API UClass* Z_Construct_UClass_AMyGAME259_A_URECharacter_NoRegister();
	GAME259_A_URE_API UClass* Z_Construct_UClass_AMyGAME259_A_URECharacter();
	GAME259_A_URE_API UClass* Z_Construct_UClass_AGAME259_A_URECharacter();
	UPackage* Z_Construct_UPackage__Script_GAME259_A_URE();
// End Cross Module References
	void AMyGAME259_A_URECharacter::StaticRegisterNativesAMyGAME259_A_URECharacter()
	{
	}
	UClass* Z_Construct_UClass_AMyGAME259_A_URECharacter_NoRegister()
	{
		return AMyGAME259_A_URECharacter::StaticClass();
	}
	struct Z_Construct_UClass_AMyGAME259_A_URECharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyGAME259_A_URECharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGAME259_A_URECharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_GAME259_A_URE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyGAME259_A_URECharacter_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MyGAME259_A_URECharacter.h" },
		{ "ModuleRelativePath", "MyGAME259_A_URECharacter.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyGAME259_A_URECharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyGAME259_A_URECharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyGAME259_A_URECharacter_Statics::ClassParams = {
		&AMyGAME259_A_URECharacter::StaticClass,
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
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyGAME259_A_URECharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyGAME259_A_URECharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyGAME259_A_URECharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyGAME259_A_URECharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyGAME259_A_URECharacter, 1338958524);
	template<> GAME259_A_URE_API UClass* StaticClass<AMyGAME259_A_URECharacter>()
	{
		return AMyGAME259_A_URECharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyGAME259_A_URECharacter(Z_Construct_UClass_AMyGAME259_A_URECharacter, &AMyGAME259_A_URECharacter::StaticClass, TEXT("/Script/GAME259_A_URE"), TEXT("AMyGAME259_A_URECharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyGAME259_A_URECharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
