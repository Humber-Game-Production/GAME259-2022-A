// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GAME259_A_URE/GAME259_Flag.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGAME259_Flag() {}
// Cross Module References
	GAME259_A_URE_API UClass* Z_Construct_UClass_AGAME259_Flag_NoRegister();
	GAME259_A_URE_API UClass* Z_Construct_UClass_AGAME259_Flag();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_GAME259_A_URE();
// End Cross Module References
	void AGAME259_Flag::StaticRegisterNativesAGAME259_Flag()
	{
	}
	UClass* Z_Construct_UClass_AGAME259_Flag_NoRegister()
	{
		return AGAME259_Flag::StaticClass();
	}
	struct Z_Construct_UClass_AGAME259_Flag_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_owningTeam_MetaData[];
#endif
		static const UE4CodeGen_Private::FUnsizedIntPropertyParams NewProp_owningTeam;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGAME259_Flag_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GAME259_A_URE,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGAME259_Flag_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "GAME259_Flag.h" },
		{ "ModuleRelativePath", "GAME259_Flag.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGAME259_Flag_Statics::NewProp_owningTeam_MetaData[] = {
		{ "Category", "GAME259_Flag" },
		{ "ModuleRelativePath", "GAME259_Flag.h" },
	};
#endif
	const UE4CodeGen_Private::FUnsizedIntPropertyParams Z_Construct_UClass_AGAME259_Flag_Statics::NewProp_owningTeam = { "owningTeam", nullptr, (EPropertyFlags)0x0020080000000021, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGAME259_Flag, owningTeam), METADATA_PARAMS(Z_Construct_UClass_AGAME259_Flag_Statics::NewProp_owningTeam_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGAME259_Flag_Statics::NewProp_owningTeam_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGAME259_Flag_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGAME259_Flag_Statics::NewProp_owningTeam,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGAME259_Flag_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGAME259_Flag>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGAME259_Flag_Statics::ClassParams = {
		&AGAME259_Flag::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGAME259_Flag_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGAME259_Flag_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGAME259_Flag_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGAME259_Flag_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGAME259_Flag()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGAME259_Flag_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGAME259_Flag, 559345695);
	template<> GAME259_A_URE_API UClass* StaticClass<AGAME259_Flag>()
	{
		return AGAME259_Flag::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGAME259_Flag(Z_Construct_UClass_AGAME259_Flag, &AGAME259_Flag::StaticClass, TEXT("/Script/GAME259_A_URE"), TEXT("AGAME259_Flag"), false, nullptr, nullptr, nullptr);

	void AGAME259_Flag::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_owningTeam(TEXT("owningTeam"));

		const bool bIsValid = true
			&& Name_owningTeam == ClassReps[(int32)ENetFields_Private::owningTeam].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in AGAME259_Flag"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGAME259_Flag);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
