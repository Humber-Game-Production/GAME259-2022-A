// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "GAME259_A_URE/PlayerStats.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodePlayerStats() {}
// Cross Module References
	GAME259_A_URE_API UClass* Z_Construct_UClass_UPlayerStatsComponent_NoRegister();
	GAME259_A_URE_API UClass* Z_Construct_UClass_UPlayerStatsComponent();
	ENGINE_API UClass* Z_Construct_UClass_UActorComponent();
	UPackage* Z_Construct_UPackage__Script_GAME259_A_URE();
// End Cross Module References
	DEFINE_FUNCTION(UPlayerStatsComponent::execServerLowerHealth)
	{
		P_GET_PROPERTY(FFloatProperty,Z_Param_value);
		P_FINISH;
		P_NATIVE_BEGIN;
		if (!P_THIS->ServerLowerHealth_Validate(Z_Param_value))
		{
			RPC_ValidateFailed(TEXT("ServerLowerHealth_Validate"));
			return;
		}
		P_THIS->ServerLowerHealth_Implementation(Z_Param_value);
		P_NATIVE_END;
	}
	static FName NAME_UPlayerStatsComponent_ServerLowerHealth = FName(TEXT("ServerLowerHealth"));
	void UPlayerStatsComponent::ServerLowerHealth(float value)
	{
		PlayerStatsComponent_eventServerLowerHealth_Parms Parms;
		Parms.value=value;
		ProcessEvent(FindFunctionChecked(NAME_UPlayerStatsComponent_ServerLowerHealth),&Parms);
	}
	void UPlayerStatsComponent::StaticRegisterNativesUPlayerStatsComponent()
	{
		UClass* Class = UPlayerStatsComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "ServerLowerHealth", &UPlayerStatsComponent::execServerLowerHealth },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UPlayerStatsComponent_ServerLowerHealth_Statics
	{
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_value;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UFunction_UPlayerStatsComponent_ServerLowerHealth_Statics::NewProp_value = { "value", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(PlayerStatsComponent_eventServerLowerHealth_Parms, value), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UPlayerStatsComponent_ServerLowerHealth_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UPlayerStatsComponent_ServerLowerHealth_Statics::NewProp_value,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UPlayerStatsComponent_ServerLowerHealth_Statics::Function_MetaDataParams[] = {
		{ "Comment", "//UFUNCTION(Server, Reliable, WithValidation)\n//    void ServerLowerStamina(float value);\n//bool ServerLowerStamina_Validate(float value);\n//void ServerLowerStamina_Implementation(float value);\n" },
		{ "ModuleRelativePath", "PlayerStats.h" },
		{ "ToolTip", "UFUNCTION(Server, Reliable, WithValidation)\n    void ServerLowerStamina(float value);\nbool ServerLowerStamina_Validate(float value);\nvoid ServerLowerStamina_Implementation(float value);" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UPlayerStatsComponent_ServerLowerHealth_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UPlayerStatsComponent, nullptr, "ServerLowerHealth", nullptr, nullptr, sizeof(PlayerStatsComponent_eventServerLowerHealth_Parms), Z_Construct_UFunction_UPlayerStatsComponent_ServerLowerHealth_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayerStatsComponent_ServerLowerHealth_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x80280CC0, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UPlayerStatsComponent_ServerLowerHealth_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UPlayerStatsComponent_ServerLowerHealth_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UPlayerStatsComponent_ServerLowerHealth()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UPlayerStatsComponent_ServerLowerHealth_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UPlayerStatsComponent_NoRegister()
	{
		return UPlayerStatsComponent::StaticClass();
	}
	struct Z_Construct_UClass_UPlayerStatsComponent_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Health_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Health;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UPlayerStatsComponent_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UActorComponent,
		(UObject* (*)())Z_Construct_UPackage__Script_GAME259_A_URE,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UPlayerStatsComponent_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UPlayerStatsComponent_ServerLowerHealth, "ServerLowerHealth" }, // 2217484916
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerStatsComponent_Statics::Class_MetaDataParams[] = {
		{ "BlueprintSpawnableComponent", "" },
		{ "ClassGroupNames", "Custom" },
		{ "IncludePath", "PlayerStats.h" },
		{ "ModuleRelativePath", "PlayerStats.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UPlayerStatsComponent_Statics::NewProp_Health_MetaData[] = {
		{ "Comment", "//UPROPERTY(EditAnywhere, Category = \"PlayerStats\")\n//float ThirstDecrementValue;\n//\n//UPROPERTY(Replicated)\n//float Stamina;\n" },
		{ "ModuleRelativePath", "PlayerStats.h" },
		{ "ToolTip", "UPROPERTY(EditAnywhere, Category = \"PlayerStats\")\nfloat ThirstDecrementValue;\n\nUPROPERTY(Replicated)\nfloat Stamina;" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UClass_UPlayerStatsComponent_Statics::NewProp_Health = { "Health", nullptr, (EPropertyFlags)0x0020080000000020, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UPlayerStatsComponent, Health), METADATA_PARAMS(Z_Construct_UClass_UPlayerStatsComponent_Statics::NewProp_Health_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerStatsComponent_Statics::NewProp_Health_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UPlayerStatsComponent_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UPlayerStatsComponent_Statics::NewProp_Health,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UPlayerStatsComponent_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UPlayerStatsComponent>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UPlayerStatsComponent_Statics::ClassParams = {
		&UPlayerStatsComponent::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UPlayerStatsComponent_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerStatsComponent_Statics::PropPointers),
		0,
		0x00B000A4u,
		METADATA_PARAMS(Z_Construct_UClass_UPlayerStatsComponent_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_UPlayerStatsComponent_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_UPlayerStatsComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_UPlayerStatsComponent_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UPlayerStatsComponent, 1300131123);
	template<> GAME259_A_URE_API UClass* StaticClass<UPlayerStatsComponent>()
	{
		return UPlayerStatsComponent::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_UPlayerStatsComponent(Z_Construct_UClass_UPlayerStatsComponent, &UPlayerStatsComponent::StaticClass, TEXT("/Script/GAME259_A_URE"), TEXT("UPlayerStatsComponent"), false, nullptr, nullptr, nullptr);

	void UPlayerStatsComponent::ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const
	{
		static const FName Name_Health(TEXT("Health"));

		const bool bIsValid = true
			&& Name_Health == ClassReps[(int32)ENetFields_Private::Health].Property->GetFName();

		checkf(bIsValid, TEXT("UHT Generated Rep Indices do not match runtime populated Rep Indices for properties in UPlayerStatsComponent"));
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(UPlayerStatsComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
