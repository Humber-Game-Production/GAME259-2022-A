// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GAME259_A_URE/Public/BallActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeBallActor() {}
// Cross Module References
	GAME259_A_URE_API UFunction* Z_Construct_UDelegateFunction_GAME259_A_URE_MessageStatus__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_GAME259_A_URE();
	GAME259_A_URE_API UFunction* Z_Construct_UDelegateFunction_GAME259_A_URE_MessageDamage__DelegateSignature();
	GAME259_A_URE_API UClass* Z_Construct_UClass_ABallActor_NoRegister();
	GAME259_A_URE_API UClass* Z_Construct_UClass_ABallActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	ENGINE_API UClass* Z_Construct_UClass_UPrimitiveComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FHitResult();
	ENGINE_API UScriptStruct* Z_Construct_UScriptStruct_FTimerHandle();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_USphereComponent_NoRegister();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_GAME259_A_URE_MessageStatus__DelegateSignature_Statics
	{
		struct _Script_GAME259_A_URE_eventMessageStatus_Parms
		{
			FString FStatus;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_FStatus;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UDelegateFunction_GAME259_A_URE_MessageStatus__DelegateSignature_Statics::NewProp_FStatus = { "FStatus", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_GAME259_A_URE_eventMessageStatus_Parms, FStatus), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GAME259_A_URE_MessageStatus__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GAME259_A_URE_MessageStatus__DelegateSignature_Statics::NewProp_FStatus,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_GAME259_A_URE_MessageStatus__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//Dynamic one parameter delegate used for broadcasting the type of status\n" },
		{ "ModuleRelativePath", "Public/BallActor.h" },
		{ "ToolTip", "Dynamic one parameter delegate used for broadcasting the type of status" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_GAME259_A_URE_MessageStatus__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_GAME259_A_URE, nullptr, "MessageStatus__DelegateSignature", nullptr, nullptr, sizeof(_Script_GAME259_A_URE_eventMessageStatus_Parms), Z_Construct_UDelegateFunction_GAME259_A_URE_MessageStatus__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GAME259_A_URE_MessageStatus__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_GAME259_A_URE_MessageStatus__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GAME259_A_URE_MessageStatus__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_GAME259_A_URE_MessageStatus__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_GAME259_A_URE_MessageStatus__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_GAME259_A_URE_MessageDamage__DelegateSignature_Statics
	{
		struct _Script_GAME259_A_URE_eventMessageDamage_Parms
		{
			float FDamage;
		};
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_FDamage;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UDelegateFunction_GAME259_A_URE_MessageDamage__DelegateSignature_Statics::NewProp_FDamage = { "FDamage", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_GAME259_A_URE_eventMessageDamage_Parms, FDamage), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GAME259_A_URE_MessageDamage__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GAME259_A_URE_MessageDamage__DelegateSignature_Statics::NewProp_FDamage,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_GAME259_A_URE_MessageDamage__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//Dynamic one parameter delegate used for broadcasting the amount of time to deal\n" },
		{ "ModuleRelativePath", "Public/BallActor.h" },
		{ "ToolTip", "Dynamic one parameter delegate used for broadcasting the amount of time to deal" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_GAME259_A_URE_MessageDamage__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_GAME259_A_URE, nullptr, "MessageDamage__DelegateSignature", nullptr, nullptr, sizeof(_Script_GAME259_A_URE_eventMessageDamage_Parms), Z_Construct_UDelegateFunction_GAME259_A_URE_MessageDamage__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GAME259_A_URE_MessageDamage__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_GAME259_A_URE_MessageDamage__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GAME259_A_URE_MessageDamage__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_GAME259_A_URE_MessageDamage__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_GAME259_A_URE_MessageDamage__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	DEFINE_FUNCTION(ABallActor::execBeginOverlap)
	{
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OverlappedComponent);
		P_GET_OBJECT(AActor,Z_Param_OtherActor);
		P_GET_OBJECT(UPrimitiveComponent,Z_Param_OtherComp);
		P_GET_PROPERTY(FIntProperty,Z_Param_OtherBodyIndex);
		P_GET_UBOOL(Z_Param_bFromSweep);
		P_GET_STRUCT_REF(FHitResult,Z_Param_Out_SweepResult);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->BeginOverlap(Z_Param_OverlappedComponent,Z_Param_OtherActor,Z_Param_OtherComp,Z_Param_OtherBodyIndex,Z_Param_bFromSweep,Z_Param_Out_SweepResult);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(ABallActor::execDestroyTimerUp)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->DestroyTimerUp();
		P_NATIVE_END;
	}
	void ABallActor::StaticRegisterNativesABallActor()
	{
		UClass* Class = ABallActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "BeginOverlap", &ABallActor::execBeginOverlap },
			{ "DestroyTimerUp", &ABallActor::execDestroyTimerUp },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_ABallActor_BeginOverlap_Statics
	{
		struct BallActor_eventBeginOverlap_Parms
		{
			UPrimitiveComponent* OverlappedComponent;
			AActor* OtherActor;
			UPrimitiveComponent* OtherComp;
			int32 OtherBodyIndex;
			bool bFromSweep;
			FHitResult SweepResult;
		};
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OverlappedComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OverlappedComponent;
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherActor;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_OtherComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_OtherComp;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_OtherBodyIndex;
		static void NewProp_bFromSweep_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bFromSweep;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SweepResult_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_SweepResult;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_OverlappedComponent_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_OverlappedComponent = { "OverlappedComponent", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BallActor_eventBeginOverlap_Parms, OverlappedComponent), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_OverlappedComponent_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_OverlappedComponent_MetaData)) };
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_OtherActor = { "OtherActor", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BallActor_eventBeginOverlap_Parms, OtherActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_OtherComp_MetaData[] = {
		{ "EditInline", "true" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_OtherComp = { "OtherComp", nullptr, (EPropertyFlags)0x0010000000080080, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BallActor_eventBeginOverlap_Parms, OtherComp), Z_Construct_UClass_UPrimitiveComponent_NoRegister, METADATA_PARAMS(Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_OtherComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_OtherComp_MetaData)) };
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_OtherBodyIndex = { "OtherBodyIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BallActor_eventBeginOverlap_Parms, OtherBodyIndex), METADATA_PARAMS(nullptr, 0) };
	void Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_bFromSweep_SetBit(void* Obj)
	{
		((BallActor_eventBeginOverlap_Parms*)Obj)->bFromSweep = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_bFromSweep = { "bFromSweep", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(BallActor_eventBeginOverlap_Parms), &Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_bFromSweep_SetBit, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_SweepResult_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_SweepResult = { "SweepResult", nullptr, (EPropertyFlags)0x0010008008000182, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(BallActor_eventBeginOverlap_Parms, SweepResult), Z_Construct_UScriptStruct_FHitResult, METADATA_PARAMS(Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_SweepResult_MetaData, UE_ARRAY_COUNT(Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_SweepResult_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_OverlappedComponent,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_OtherActor,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_OtherComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_OtherBodyIndex,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_bFromSweep,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::NewProp_SweepResult,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//Overlap function for destroying the actor and broadcasting delegates\n" },
		{ "ModuleRelativePath", "Public/BallActor.h" },
		{ "ToolTip", "Overlap function for destroying the actor and broadcasting delegates" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABallActor, nullptr, "BeginOverlap", nullptr, nullptr, sizeof(BallActor_eventBeginOverlap_Parms), Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00420401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABallActor_BeginOverlap()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABallActor_BeginOverlap_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_ABallActor_DestroyTimerUp_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_ABallActor_DestroyTimerUp_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//Function used by the timer to determine what happens when the destroy timer is up\n" },
		{ "ModuleRelativePath", "Public/BallActor.h" },
		{ "ToolTip", "Function used by the timer to determine what happens when the destroy timer is up" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_ABallActor_DestroyTimerUp_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_ABallActor, nullptr, "DestroyTimerUp", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_ABallActor_DestroyTimerUp_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_ABallActor_DestroyTimerUp_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_ABallActor_DestroyTimerUp()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_ABallActor_DestroyTimerUp_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_ABallActor_NoRegister()
	{
		return ABallActor::StaticClass();
	}
	struct Z_Construct_UClass_ABallActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DamageToDeal_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DamageToDeal;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Status_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Status;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_IsLethal_MetaData[];
#endif
		static void NewProp_IsLethal_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_IsLethal;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HasStatus_MetaData[];
#endif
		static void NewProp_HasStatus_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_HasStatus;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_DestroyTimer_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_DestroyTimer;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Debug_MetaData[];
#endif
		static void NewProp_Debug_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_Debug;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_TimeHandle_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_TimeHandle;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SphereMesh_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SphereMesh;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SphereComp_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_SphereComp;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MessageDamage_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_MessageDamage;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MessageStatus_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_MessageStatus;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ABallActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_GAME259_A_URE,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_ABallActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_ABallActor_BeginOverlap, "BeginOverlap" }, // 1894906120
		{ &Z_Construct_UFunction_ABallActor_DestroyTimerUp, "DestroyTimerUp" }, // 2171873532
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "BallActor.h" },
		{ "ModuleRelativePath", "Public/BallActor.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallActor_Statics::NewProp_DamageToDeal_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "//Stores the amount of damage to deal\n" },
		{ "ModuleRelativePath", "Public/BallActor.h" },
		{ "ToolTip", "Stores the amount of damage to deal" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABallActor_Statics::NewProp_DamageToDeal = { "DamageToDeal", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABallActor, DamageToDeal), METADATA_PARAMS(Z_Construct_UClass_ABallActor_Statics::NewProp_DamageToDeal_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABallActor_Statics::NewProp_DamageToDeal_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallActor_Statics::NewProp_Status_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "//Stores the type of status\n" },
		{ "ModuleRelativePath", "Public/BallActor.h" },
		{ "ToolTip", "Stores the type of status" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UClass_ABallActor_Statics::NewProp_Status = { "Status", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABallActor, Status), METADATA_PARAMS(Z_Construct_UClass_ABallActor_Statics::NewProp_Status_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABallActor_Statics::NewProp_Status_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallActor_Statics::NewProp_IsLethal_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "//Determines if the actor is lethal or not\n" },
		{ "ModuleRelativePath", "Public/BallActor.h" },
		{ "ToolTip", "Determines if the actor is lethal or not" },
	};
#endif
	void Z_Construct_UClass_ABallActor_Statics::NewProp_IsLethal_SetBit(void* Obj)
	{
		((ABallActor*)Obj)->IsLethal = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ABallActor_Statics::NewProp_IsLethal = { "IsLethal", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ABallActor), &Z_Construct_UClass_ABallActor_Statics::NewProp_IsLethal_SetBit, METADATA_PARAMS(Z_Construct_UClass_ABallActor_Statics::NewProp_IsLethal_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABallActor_Statics::NewProp_IsLethal_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallActor_Statics::NewProp_HasStatus_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "//Determines if the actor has a status effect or not\n" },
		{ "ModuleRelativePath", "Public/BallActor.h" },
		{ "ToolTip", "Determines if the actor has a status effect or not" },
	};
#endif
	void Z_Construct_UClass_ABallActor_Statics::NewProp_HasStatus_SetBit(void* Obj)
	{
		((ABallActor*)Obj)->HasStatus = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ABallActor_Statics::NewProp_HasStatus = { "HasStatus", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ABallActor), &Z_Construct_UClass_ABallActor_Statics::NewProp_HasStatus_SetBit, METADATA_PARAMS(Z_Construct_UClass_ABallActor_Statics::NewProp_HasStatus_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABallActor_Statics::NewProp_HasStatus_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallActor_Statics::NewProp_DestroyTimer_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "//Starting time for the destroying the object\n" },
		{ "ModuleRelativePath", "Public/BallActor.h" },
		{ "ToolTip", "Starting time for the destroying the object" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_ABallActor_Statics::NewProp_DestroyTimer = { "DestroyTimer", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABallActor, DestroyTimer), METADATA_PARAMS(Z_Construct_UClass_ABallActor_Statics::NewProp_DestroyTimer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABallActor_Statics::NewProp_DestroyTimer_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallActor_Statics::NewProp_Debug_MetaData[] = {
		{ "Category", "Input" },
		{ "Comment", "//Set whether to enable debug options\n" },
		{ "ModuleRelativePath", "Public/BallActor.h" },
		{ "ToolTip", "Set whether to enable debug options" },
	};
#endif
	void Z_Construct_UClass_ABallActor_Statics::NewProp_Debug_SetBit(void* Obj)
	{
		((ABallActor*)Obj)->Debug = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UClass_ABallActor_Statics::NewProp_Debug = { "Debug", nullptr, (EPropertyFlags)0x0010000000000005, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(ABallActor), &Z_Construct_UClass_ABallActor_Statics::NewProp_Debug_SetBit, METADATA_PARAMS(Z_Construct_UClass_ABallActor_Statics::NewProp_Debug_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABallActor_Statics::NewProp_Debug_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallActor_Statics::NewProp_TimeHandle_MetaData[] = {
		{ "Category", "Timer" },
		{ "Comment", "//The timer handler for the game's time\n" },
		{ "ModuleRelativePath", "Public/BallActor.h" },
		{ "ToolTip", "The timer handler for the game's time" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_ABallActor_Statics::NewProp_TimeHandle = { "TimeHandle", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABallActor, TimeHandle), Z_Construct_UScriptStruct_FTimerHandle, METADATA_PARAMS(Z_Construct_UClass_ABallActor_Statics::NewProp_TimeHandle_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABallActor_Statics::NewProp_TimeHandle_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallActor_Statics::NewProp_SphereMesh_MetaData[] = {
		{ "Category", "Mesh" },
		{ "Comment", "//Stores the mesh component\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BallActor.h" },
		{ "ToolTip", "Stores the mesh component" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABallActor_Statics::NewProp_SphereMesh = { "SphereMesh", nullptr, (EPropertyFlags)0x00100000000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABallActor, SphereMesh), Z_Construct_UClass_UStaticMeshComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABallActor_Statics::NewProp_SphereMesh_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABallActor_Statics::NewProp_SphereMesh_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallActor_Statics::NewProp_SphereComp_MetaData[] = {
		{ "Category", "Sphere" },
		{ "Comment", "//Stores the sphere component\n" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "Public/BallActor.h" },
		{ "ToolTip", "Stores the sphere component" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ABallActor_Statics::NewProp_SphereComp = { "SphereComp", nullptr, (EPropertyFlags)0x00100000000b0009, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABallActor, SphereComp), Z_Construct_UClass_USphereComponent_NoRegister, METADATA_PARAMS(Z_Construct_UClass_ABallActor_Statics::NewProp_SphereComp_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABallActor_Statics::NewProp_SphereComp_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallActor_Statics::NewProp_MessageDamage_MetaData[] = {
		{ "Category", "Dispatcher" },
		{ "Comment", "//Dispatcher for the amount of damage to deal\n" },
		{ "ModuleRelativePath", "Public/BallActor.h" },
		{ "ToolTip", "Dispatcher for the amount of damage to deal" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ABallActor_Statics::NewProp_MessageDamage = { "MessageDamage", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABallActor, MessageDamage), Z_Construct_UDelegateFunction_GAME259_A_URE_MessageDamage__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ABallActor_Statics::NewProp_MessageDamage_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABallActor_Statics::NewProp_MessageDamage_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ABallActor_Statics::NewProp_MessageStatus_MetaData[] = {
		{ "Category", "Dispatcher" },
		{ "Comment", "//Dispatcher for the amount of damage to deal\n" },
		{ "ModuleRelativePath", "Public/BallActor.h" },
		{ "ToolTip", "Dispatcher for the amount of damage to deal" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_ABallActor_Statics::NewProp_MessageStatus = { "MessageStatus", nullptr, (EPropertyFlags)0x0010000010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(ABallActor, MessageStatus), Z_Construct_UDelegateFunction_GAME259_A_URE_MessageStatus__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_ABallActor_Statics::NewProp_MessageStatus_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_ABallActor_Statics::NewProp_MessageStatus_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ABallActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABallActor_Statics::NewProp_DamageToDeal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABallActor_Statics::NewProp_Status,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABallActor_Statics::NewProp_IsLethal,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABallActor_Statics::NewProp_HasStatus,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABallActor_Statics::NewProp_DestroyTimer,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABallActor_Statics::NewProp_Debug,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABallActor_Statics::NewProp_TimeHandle,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABallActor_Statics::NewProp_SphereMesh,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABallActor_Statics::NewProp_SphereComp,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABallActor_Statics::NewProp_MessageDamage,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ABallActor_Statics::NewProp_MessageStatus,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ABallActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ABallActor>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_ABallActor_Statics::ClassParams = {
		&ABallActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_ABallActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_ABallActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_ABallActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_ABallActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_ABallActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_ABallActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(ABallActor, 2686717071);
	template<> GAME259_A_URE_API UClass* StaticClass<ABallActor>()
	{
		return ABallActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_ABallActor(Z_Construct_UClass_ABallActor, &ABallActor::StaticClass, TEXT("/Script/GAME259_A_URE"), TEXT("ABallActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(ABallActor);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
