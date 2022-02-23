// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GAME259_A_URE/LineTrace.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeLineTrace() {}
// Cross Module References
	GAME259_A_URE_API UClass* Z_Construct_UClass_ULineTrace_NoRegister();
	GAME259_A_URE_API UClass* Z_Construct_UClass_ULineTrace();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_GAME259_A_URE();
// End Cross Module References
	void ULineTrace::StaticRegisterNativesULineTrace()
	{
	}
	UClass* Z_Construct_UClass_ULineTrace_NoRegister()
	{
		return ULineTrace::StaticClass();
	}
	struct Z_Construct_UClass_ULineTrace_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ULineTrace_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_GAME259_A_URE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ULineTrace_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "LineTrace.h" },
		{ "ModuleRelativePath", "LineTrace.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_ULineTrace_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ULineTrace>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ULineTrace_Statics::ClassParams = {
		&ULineTrace::StaticClass,
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
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ULineTrace_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ULineTrace_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ULineTrace()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ULineTrace_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ULineTrace, 1671551086);
	template<> GAME259_A_URE_API UClass* StaticClass<ULineTrace>()
	{
		return ULineTrace::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ULineTrace(Z_Construct_UClass_ULineTrace, &ULineTrace::StaticClass, TEXT("/Script/GAME259_A_URE"), TEXT("ULineTrace"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ULineTrace);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
