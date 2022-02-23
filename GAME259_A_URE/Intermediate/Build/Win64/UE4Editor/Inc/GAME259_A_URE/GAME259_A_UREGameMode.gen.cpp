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
	ENGINE_API UClass* Z_Construct_UClass_AController_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AGAME259_A_UREGameMode::execSpawn)
	{
		P_GET_OBJECT(AController,Z_Param_Controller);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->Spawn(Z_Param_Controller);
		P_NATIVE_END;
	}
	void AGAME259_A_UREGameMode::StaticRegisterNativesAGAME259_A_UREGameMode()
	{
		UClass* Class = AGAME259_A_UREGameMode::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Spawn", &AGAME259_A_UREGameMode::execSpawn },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AGAME259_A_UREGameMode_Spawn_Statics
	{
		struct GAME259_A_UREGameMode_eventSpawn_Parms
		{
			AController* Controller;
		};
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_Controller;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AGAME259_A_UREGameMode_Spawn_Statics::NewProp_Controller = { "Controller", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GAME259_A_UREGameMode_eventSpawn_Parms, Controller), Z_Construct_UClass_AController_NoRegister, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AGAME259_A_UREGameMode_Spawn_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AGAME259_A_UREGameMode_Spawn_Statics::NewProp_Controller,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGAME259_A_UREGameMode_Spawn_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GAME259_A_UREGameMode.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGAME259_A_UREGameMode_Spawn_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGAME259_A_UREGameMode, nullptr, "Spawn", nullptr, nullptr, sizeof(GAME259_A_UREGameMode_eventSpawn_Parms), Z_Construct_UFunction_AGAME259_A_UREGameMode_Spawn_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AGAME259_A_UREGameMode_Spawn_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGAME259_A_UREGameMode_Spawn_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AGAME259_A_UREGameMode_Spawn_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGAME259_A_UREGameMode_Spawn()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGAME259_A_UREGameMode_Spawn_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AGAME259_A_UREGameMode_NoRegister()
	{
		return AGAME259_A_UREGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AGAME259_A_UREGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
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
	const FClassFunctionLinkInfo Z_Construct_UClass_AGAME259_A_UREGameMode_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AGAME259_A_UREGameMode_Spawn, "Spawn" }, // 1722630813
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
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
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
	IMPLEMENT_CLASS(AGAME259_A_UREGameMode, 3537653089);
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
