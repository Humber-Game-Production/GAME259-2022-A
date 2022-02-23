// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GAME259_A_URE/GAME259_A_URECharacter.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGAME259_A_URECharacter() {}
// Cross Module References
	GAME259_A_URE_API UClass* Z_Construct_UClass_AGAME259_A_URECharacter_NoRegister();
	GAME259_A_URE_API UClass* Z_Construct_UClass_AGAME259_A_URECharacter();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
	UPackage* Z_Construct_UPackage__Script_GAME259_A_URE();
	ENGINE_API UClass* Z_Construct_UClass_USpringArmComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UCameraComponent_NoRegister();
// End Cross Module References
	DEFINE_FUNCTION(AGAME259_A_URECharacter::execMultiDie)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->MultiDie_Validate())
		{
			RPC_ValidateFailed(TEXT("MultiDie_Validate"));
			return;
		}
		P_THIS->MultiDie_Implementation();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AGAME259_A_URECharacter::execServerAttack)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->ServerAttack_Validate())
		{
			RPC_ValidateFailed(TEXT("ServerAttack_Validate"));
			return;
		}
		P_THIS->ServerAttack_Implementation();
		P_NATIVE_END;
	}
	static FName NAME_AGAME259_A_URECharacter_MultiDie = FName(TEXT("MultiDie"));
	void AGAME259_A_URECharacter::MultiDie()
	{
		ProcessEvent(FindFunctionChecked(NAME_AGAME259_A_URECharacter_MultiDie),NULL);
	}
	static FName NAME_AGAME259_A_URECharacter_ServerAttack = FName(TEXT("ServerAttack"));
	void AGAME259_A_URECharacter::ServerAttack()
	{
		ProcessEvent(FindFunctionChecked(NAME_AGAME259_A_URECharacter_ServerAttack),NULL);
	}
	void AGAME259_A_URECharacter::StaticRegisterNativesAGAME259_A_URECharacter()
	{
		UClass* Class = AGAME259_A_URECharacter::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "MultiDie", &AGAME259_A_URECharacter::execMultiDie },
			{ "ServerAttack", &AGAME259_A_URECharacter::execServerAttack },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AGAME259_A_URECharacter_MultiDie_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGAME259_A_URECharacter_MultiDie_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GAME259_A_URECharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGAME259_A_URECharacter_MultiDie_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGAME259_A_URECharacter, nullptr, "MultiDie", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80084CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGAME259_A_URECharacter_MultiDie_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AGAME259_A_URECharacter_MultiDie_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGAME259_A_URECharacter_MultiDie()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGAME259_A_URECharacter_MultiDie_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AGAME259_A_URECharacter_ServerAttack_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AGAME259_A_URECharacter_ServerAttack_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GAME259_A_URECharacter.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AGAME259_A_URECharacter_ServerAttack_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AGAME259_A_URECharacter, nullptr, "ServerAttack", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80280CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_AGAME259_A_URECharacter_ServerAttack_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_AGAME259_A_URECharacter_ServerAttack_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_AGAME259_A_URECharacter_ServerAttack()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AGAME259_A_URECharacter_ServerAttack_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AGAME259_A_URECharacter_NoRegister()
	{
		return AGAME259_A_URECharacter::StaticClass();
	}
	struct Z_Construct_UClass_AGAME259_A_URECharacter_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CameraBoom_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_CameraBoom;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FollowCamera_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FollowCamera;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseTurnRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseTurnRate;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_BaseLookUpRate_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_BaseLookUpRate;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGAME259_A_URECharacter_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_GAME259_A_URE,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AGAME259_A_URECharacter_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AGAME259_A_URECharacter_MultiDie, "MultiDie" }, // 3240249142
		{ &Z_Construct_UFunction_AGAME259_A_URECharacter_ServerAttack, "ServerAttack" }, // 196449011
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGAME259_A_URECharacter_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "GAME259_A_URECharacter.h" },
		{ "ModuleRelativePath", "GAME259_A_URECharacter.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_CameraBoom_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Camera boom positioning the camera behind the character */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "GAME259_A_URECharacter.h" },
		{ "ToolTip", "Camera boom positioning the camera behind the character" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_CameraBoom = { "CameraBoom", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGAME259_A_URECharacter, CameraBoom), Z_Construct_UClass_USpringArmComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_CameraBoom_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_CameraBoom_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_FollowCamera_MetaData[] = {
		{ "AllowPrivateAccess", "true" },
		{ "Category", "Camera" },
		{ "Comment", "/** Follow camera */" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "GAME259_A_URECharacter.h" },
		{ "ToolTip", "Follow camera" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_FollowCamera = { "FollowCamera", nullptr, (EPropertyFlags)0x00400000000a001d, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGAME259_A_URECharacter, FollowCamera), Z_Construct_UClass_UCameraComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_FollowCamera_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_FollowCamera_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_BaseTurnRate_MetaData[] = {
		{ "Category", "Camera" },
		{ "Comment", "/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */" },
		{ "ModuleRelativePath", "GAME259_A_URECharacter.h" },
		{ "ToolTip", "Base turn rate, in deg/sec. Other scaling may affect final turn rate." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_BaseTurnRate = { "BaseTurnRate", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGAME259_A_URECharacter, BaseTurnRate), METADATA_PARAMS(Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_BaseTurnRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_BaseTurnRate_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_BaseLookUpRate_MetaData[] = {
		{ "Category", "Camera" },
		{ "Comment", "/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */" },
		{ "ModuleRelativePath", "GAME259_A_URECharacter.h" },
		{ "ToolTip", "Base look up/down rate, in deg/sec. Other scaling may affect final rate." },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_BaseLookUpRate = { "BaseLookUpRate", nullptr, (EPropertyFlags)0x0010000000020015, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGAME259_A_URECharacter, BaseLookUpRate), METADATA_PARAMS(Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_BaseLookUpRate_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_BaseLookUpRate_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGAME259_A_URECharacter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_CameraBoom,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_FollowCamera,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_BaseTurnRate,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGAME259_A_URECharacter_Statics::NewProp_BaseLookUpRate,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGAME259_A_URECharacter_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGAME259_A_URECharacter>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGAME259_A_URECharacter_Statics::ClassParams = {
		&AGAME259_A_URECharacter::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AGAME259_A_URECharacter_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AGAME259_A_URECharacter_Statics::PropPointers),
		0,
		0x008000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AGAME259_A_URECharacter_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGAME259_A_URECharacter_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGAME259_A_URECharacter()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGAME259_A_URECharacter_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGAME259_A_URECharacter, 3769020353);
	template<> GAME259_A_URE_API UClass* StaticClass<AGAME259_A_URECharacter>()
	{
		return AGAME259_A_URECharacter::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGAME259_A_URECharacter(Z_Construct_UClass_AGAME259_A_URECharacter, &AGAME259_A_URECharacter::StaticClass, TEXT("/Script/GAME259_A_URE"), TEXT("AGAME259_A_URECharacter"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGAME259_A_URECharacter);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
