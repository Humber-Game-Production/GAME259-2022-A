// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GAME259_A_URE/GameInstance_GAME259_A_URE.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameInstance_GAME259_A_URE() {}
// Cross Module References
	GAME259_A_URE_API UClass* Z_Construct_UClass_UGameInstance_GAME259_A_URE_NoRegister();
	GAME259_A_URE_API UClass* Z_Construct_UClass_UGameInstance_GAME259_A_URE();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
	UPackage* Z_Construct_UPackage__Script_GAME259_A_URE();
// End Cross Module References
	void UGameInstance_GAME259_A_URE::StaticRegisterNativesUGameInstance_GAME259_A_URE()
	{
	}
	UClass* Z_Construct_UClass_UGameInstance_GAME259_A_URE_NoRegister()
	{
		return UGameInstance_GAME259_A_URE::StaticClass();
	}
	struct Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_GAME259_A_URE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "GameInstance_GAME259_A_URE.h" },
		{ "ModuleRelativePath", "GameInstance_GAME259_A_URE.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameInstance_GAME259_A_URE>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::ClassParams = {
		&UGameInstance_GAME259_A_URE::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A8u,
		METADATA_PARAMS(Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UGameInstance_GAME259_A_URE()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UGameInstance_GAME259_A_URE, 4124141028);
	template<> GAME259_A_URE_API UClass* StaticClass<UGameInstance_GAME259_A_URE>()
	{
		return UGameInstance_GAME259_A_URE::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UGameInstance_GAME259_A_URE(Z_Construct_UClass_UGameInstance_GAME259_A_URE, &UGameInstance_GAME259_A_URE::StaticClass, TEXT("/Script/GAME259_A_URE"), TEXT("UGameInstance_GAME259_A_URE"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UGameInstance_GAME259_A_URE);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
