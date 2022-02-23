// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GAME259_A_URE/GAME259_PlayerSpawnPoint.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGAME259_PlayerSpawnPoint() {}
// Cross Module References
	GAME259_A_URE_API UClass* Z_Construct_UClass_AGAME259_PlayerSpawnPoint_NoRegister();
	GAME259_A_URE_API UClass* Z_Construct_UClass_AGAME259_PlayerSpawnPoint();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_GAME259_A_URE();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
// End Cross Module References
	void AGAME259_PlayerSpawnPoint::StaticRegisterNativesAGAME259_PlayerSpawnPoint()
	{
	}
	UClass* Z_Construct_UClass_AGAME259_PlayerSpawnPoint_NoRegister()
	{
		return AGAME259_PlayerSpawnPoint::StaticClass();
	}
	struct Z_Construct_UClass_AGAME259_PlayerSpawnPoint_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MeshComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MeshComp;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGAME259_PlayerSpawnPoint_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GAME259_A_URE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGAME259_PlayerSpawnPoint_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "GAME259_PlayerSpawnPoint.h" },
		{ "ModuleRelativePath", "GAME259_PlayerSpawnPoint.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGAME259_PlayerSpawnPoint_Statics::NewProp_MeshComp_MetaData[] = {
		{ "Category", "Mesh" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "GAME259_PlayerSpawnPoint.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGAME259_PlayerSpawnPoint_Statics::NewProp_MeshComp = { "MeshComp", nullptr, (EPropertyFlags)0x0020080000080009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGAME259_PlayerSpawnPoint, MeshComp), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGAME259_PlayerSpawnPoint_Statics::NewProp_MeshComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGAME259_PlayerSpawnPoint_Statics::NewProp_MeshComp_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGAME259_PlayerSpawnPoint_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGAME259_PlayerSpawnPoint_Statics::NewProp_MeshComp,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGAME259_PlayerSpawnPoint_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGAME259_PlayerSpawnPoint>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGAME259_PlayerSpawnPoint_Statics::ClassParams = {
		&AGAME259_PlayerSpawnPoint::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGAME259_PlayerSpawnPoint_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGAME259_PlayerSpawnPoint_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGAME259_PlayerSpawnPoint_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGAME259_PlayerSpawnPoint_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGAME259_PlayerSpawnPoint()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGAME259_PlayerSpawnPoint_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGAME259_PlayerSpawnPoint, 3995116162);
	template<> GAME259_A_URE_API UClass* StaticClass<AGAME259_PlayerSpawnPoint>()
	{
		return AGAME259_PlayerSpawnPoint::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGAME259_PlayerSpawnPoint(Z_Construct_UClass_AGAME259_PlayerSpawnPoint, &AGAME259_PlayerSpawnPoint::StaticClass, TEXT("/Script/GAME259_A_URE"), TEXT("AGAME259_PlayerSpawnPoint"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGAME259_PlayerSpawnPoint);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
