// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GAME259_A_URE/Public/BallIceActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBallIceActor() {}
// Cross Module References
	GAME259_A_URE_API UClass* Z_Construct_UClass_ABallIceActor_NoRegister();
	GAME259_A_URE_API UClass* Z_Construct_UClass_ABallIceActor();
	GAME259_A_URE_API UClass* Z_Construct_UClass_ABallActor();
	UPackage* Z_Construct_UPackage__Script_GAME259_A_URE();
// End Cross Module References
	void ABallIceActor::StaticRegisterNativesABallIceActor()
	{
	}
	UClass* Z_Construct_UClass_ABallIceActor_NoRegister()
	{
		return ABallIceActor::StaticClass();
	}
	struct Z_Construct_UClass_ABallIceActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABallIceActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ABallActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GAME259_A_URE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallIceActor_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "BallIceActor.h" },
		{ "ModuleRelativePath", "Public/BallIceActor.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABallIceActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABallIceActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABallIceActor_Statics::ClassParams = {
		&ABallIceActor::StaticClass,
		"Engine",
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
		METADATA_PARAMS(Z_Construct_UClass_ABallIceActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABallIceActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABallIceActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABallIceActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABallIceActor, 1383803001);
	template<> GAME259_A_URE_API UClass* StaticClass<ABallIceActor>()
	{
		return ABallIceActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABallIceActor(Z_Construct_UClass_ABallIceActor, &ABallIceActor::StaticClass, TEXT("/Script/GAME259_A_URE"), TEXT("ABallIceActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABallIceActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
