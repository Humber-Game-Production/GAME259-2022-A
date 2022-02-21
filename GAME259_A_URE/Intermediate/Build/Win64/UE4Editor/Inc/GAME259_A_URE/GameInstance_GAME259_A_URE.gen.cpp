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
	GAME259_A_URE_API UFunction* Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_GAME259_A_URE();
	GAME259_A_URE_API UFunction* Z_Construct_UDelegateFunction_GAME259_A_URE_ServerDel__DelegateSignature();
	GAME259_A_URE_API UScriptStruct* Z_Construct_UScriptStruct_FServerInfo();
	GAME259_A_URE_API UClass* Z_Construct_UClass_UGameInstance_GAME259_A_URE_NoRegister();
	GAME259_A_URE_API UClass* Z_Construct_UClass_UGameInstance_GAME259_A_URE();
	ENGINE_API UClass* Z_Construct_UClass_UGameInstance();
// End Cross Module References
	struct Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature_Statics
	{
		struct _Script_GAME259_A_URE_eventServerSearchingDel_Parms
		{
			bool SearchingForServer;
		};
		static void NewProp_SearchingForServer_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_SearchingForServer;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	void Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature_Statics::NewProp_SearchingForServer_SetBit(void* Obj)
	{
		((_Script_GAME259_A_URE_eventServerSearchingDel_Parms*)Obj)->SearchingForServer = 1;
	}
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature_Statics::NewProp_SearchingForServer = { "SearchingForServer", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, RF_Public|RF_Transient|RF_MarkAsNative, 1, sizeof(bool), sizeof(_Script_GAME259_A_URE_eventServerSearchingDel_Parms), &Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature_Statics::NewProp_SearchingForServer_SetBit, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature_Statics::NewProp_SearchingForServer,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "Comment", "// Checks if \"Refresh Server\" is active\n" },
		{ "ModuleRelativePath", "GameInstance_GAME259_A_URE.h" },
		{ "ToolTip", "Checks if \"Refresh Server\" is active" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_GAME259_A_URE, nullptr, "ServerSearchingDel__DelegateSignature", nullptr, nullptr, sizeof(_Script_GAME259_A_URE_eventServerSearchingDel_Parms), Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UDelegateFunction_GAME259_A_URE_ServerDel__DelegateSignature_Statics
	{
		struct _Script_GAME259_A_URE_eventServerDel_Parms
		{
			FServerInfo ServerListDel;
		};
		static const UE4CodeGen_Private::FStructPropertyParams NewProp_ServerListDel;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UDelegateFunction_GAME259_A_URE_ServerDel__DelegateSignature_Statics::NewProp_ServerListDel = { "ServerListDel", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(_Script_GAME259_A_URE_eventServerDel_Parms, ServerListDel), Z_Construct_UScriptStruct_FServerInfo, METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UDelegateFunction_GAME259_A_URE_ServerDel__DelegateSignature_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UDelegateFunction_GAME259_A_URE_ServerDel__DelegateSignature_Statics::NewProp_ServerListDel,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UDelegateFunction_GAME259_A_URE_ServerDel__DelegateSignature_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GameInstance_GAME259_A_URE.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UDelegateFunction_GAME259_A_URE_ServerDel__DelegateSignature_Statics::FuncParams = { (UObject*(*)())Z_Construct_UPackage__Script_GAME259_A_URE, nullptr, "ServerDel__DelegateSignature", nullptr, nullptr, sizeof(_Script_GAME259_A_URE_eventServerDel_Parms), Z_Construct_UDelegateFunction_GAME259_A_URE_ServerDel__DelegateSignature_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GAME259_A_URE_ServerDel__DelegateSignature_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00130000, 0, 0, METADATA_PARAMS(Z_Construct_UDelegateFunction_GAME259_A_URE_ServerDel__DelegateSignature_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UDelegateFunction_GAME259_A_URE_ServerDel__DelegateSignature_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UDelegateFunction_GAME259_A_URE_ServerDel__DelegateSignature()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UDelegateFunction_GAME259_A_URE_ServerDel__DelegateSignature_Statics::FuncParams);
		}
		return ReturnFunction;
	}
class UScriptStruct* FServerInfo::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern GAME259_A_URE_API uint32 Get_Z_Construct_UScriptStruct_FServerInfo_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FServerInfo, Z_Construct_UPackage__Script_GAME259_A_URE(), TEXT("ServerInfo"), sizeof(FServerInfo), Get_Z_Construct_UScriptStruct_FServerInfo_Hash());
	}
	return Singleton;
}
template<> GAME259_A_URE_API UScriptStruct* StaticStruct<FServerInfo>()
{
	return FServerInfo::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FServerInfo(FServerInfo::StaticStruct, TEXT("/Script/GAME259_A_URE"), TEXT("ServerInfo"), false, nullptr, nullptr);
static struct FScriptStruct_GAME259_A_URE_StaticRegisterNativesFServerInfo
{
	FScriptStruct_GAME259_A_URE_StaticRegisterNativesFServerInfo()
	{
		UScriptStruct::DeferCppStructOps<FServerInfo>(FName(TEXT("ServerInfo")));
	}
} ScriptStruct_GAME259_A_URE_StaticRegisterNativesFServerInfo;
	struct Z_Construct_UScriptStruct_FServerInfo_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ServerName_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ServerName;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_CurrentPlayers_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_CurrentPlayers;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MaxPlayers_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_MaxPlayers;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ServerArrayIndex_MetaData[];
#endif
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ServerArrayIndex;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FServerInfo_Statics::Struct_MetaDataParams[] = {
		{ "BlueprintType", "true" },
		{ "Comment", "// Allows for visible servers on scroll box of Lobby UI\n" },
		{ "ModuleRelativePath", "GameInstance_GAME259_A_URE.h" },
		{ "ToolTip", "Allows for visible servers on scroll box of Lobby UI" },
	};
#endif
	void* Z_Construct_UScriptStruct_FServerInfo_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FServerInfo>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_ServerName_MetaData[] = {
		{ "Category", "ServerInfo" },
		{ "ModuleRelativePath", "GameInstance_GAME259_A_URE.h" },
	};
#endif
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_ServerName = { "ServerName", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FServerInfo, ServerName), METADATA_PARAMS(Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_ServerName_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_ServerName_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_CurrentPlayers_MetaData[] = {
		{ "Category", "ServerInfo" },
		{ "ModuleRelativePath", "GameInstance_GAME259_A_URE.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_CurrentPlayers = { "CurrentPlayers", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FServerInfo, CurrentPlayers), METADATA_PARAMS(Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_CurrentPlayers_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_CurrentPlayers_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_MaxPlayers_MetaData[] = {
		{ "Category", "ServerInfo" },
		{ "ModuleRelativePath", "GameInstance_GAME259_A_URE.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_MaxPlayers = { "MaxPlayers", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FServerInfo, MaxPlayers), METADATA_PARAMS(Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_MaxPlayers_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_MaxPlayers_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_ServerArrayIndex_MetaData[] = {
		{ "Category", "ServerInfo" },
		{ "ModuleRelativePath", "GameInstance_GAME259_A_URE.h" },
	};
#endif
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_ServerArrayIndex = { "ServerArrayIndex", nullptr, (EPropertyFlags)0x0010000000000014, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FServerInfo, ServerArrayIndex), METADATA_PARAMS(Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_ServerArrayIndex_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_ServerArrayIndex_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FServerInfo_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_ServerName,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_CurrentPlayers,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_MaxPlayers,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FServerInfo_Statics::NewProp_ServerArrayIndex,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FServerInfo_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_GAME259_A_URE,
		nullptr,
		&NewStructOps,
		"ServerInfo",
		sizeof(FServerInfo),
		alignof(FServerInfo),
		Z_Construct_UScriptStruct_FServerInfo_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerInfo_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FServerInfo_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FServerInfo_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FServerInfo()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FServerInfo_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_GAME259_A_URE();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("ServerInfo"), sizeof(FServerInfo), Get_Z_Construct_UScriptStruct_FServerInfo_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FServerInfo_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FServerInfo_Hash() { return 1566708626U; }
	DEFINE_FUNCTION(UGameInstance_GAME259_A_URE::execJoinServer)
	{
		P_GET_PROPERTY(FIntProperty,Z_Param_ArrayIndex);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->JoinServer(Z_Param_ArrayIndex);
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameInstance_GAME259_A_URE::execFindServers)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->FindServers();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(UGameInstance_GAME259_A_URE::execCreateServer)
	{
		P_GET_PROPERTY(FStrProperty,Z_Param_ServerName);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->CreateServer(Z_Param_ServerName);
		P_NATIVE_END;
	}
	void UGameInstance_GAME259_A_URE::StaticRegisterNativesUGameInstance_GAME259_A_URE()
	{
		UClass* Class = UGameInstance_GAME259_A_URE::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "CreateServer", &UGameInstance_GAME259_A_URE::execCreateServer },
			{ "FindServers", &UGameInstance_GAME259_A_URE::execFindServers },
			{ "JoinServer", &UGameInstance_GAME259_A_URE::execJoinServer },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_UGameInstance_GAME259_A_URE_CreateServer_Statics
	{
		struct GameInstance_GAME259_A_URE_eventCreateServer_Parms
		{
			FString ServerName;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ServerName;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_UGameInstance_GAME259_A_URE_CreateServer_Statics::NewProp_ServerName = { "ServerName", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GameInstance_GAME259_A_URE_eventCreateServer_Parms, ServerName), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameInstance_GAME259_A_URE_CreateServer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameInstance_GAME259_A_URE_CreateServer_Statics::NewProp_ServerName,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameInstance_GAME259_A_URE_CreateServer_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GameInstance_GAME259_A_URE.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameInstance_GAME259_A_URE_CreateServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameInstance_GAME259_A_URE, nullptr, "CreateServer", nullptr, nullptr, sizeof(GameInstance_GAME259_A_URE_eventCreateServer_Parms), Z_Construct_UFunction_UGameInstance_GAME259_A_URE_CreateServer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameInstance_GAME259_A_URE_CreateServer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameInstance_GAME259_A_URE_CreateServer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameInstance_GAME259_A_URE_CreateServer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameInstance_GAME259_A_URE_CreateServer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameInstance_GAME259_A_URE_CreateServer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameInstance_GAME259_A_URE_FindServers_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameInstance_GAME259_A_URE_FindServers_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GameInstance_GAME259_A_URE.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameInstance_GAME259_A_URE_FindServers_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameInstance_GAME259_A_URE, nullptr, "FindServers", nullptr, nullptr, 0, nullptr, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameInstance_GAME259_A_URE_FindServers_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameInstance_GAME259_A_URE_FindServers_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameInstance_GAME259_A_URE_FindServers()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameInstance_GAME259_A_URE_FindServers_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_UGameInstance_GAME259_A_URE_JoinServer_Statics
	{
		struct GameInstance_GAME259_A_URE_eventJoinServer_Parms
		{
			int32 ArrayIndex;
		};
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_ArrayIndex;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_UGameInstance_GAME259_A_URE_JoinServer_Statics::NewProp_ArrayIndex = { "ArrayIndex", nullptr, (EPropertyFlags)0x0010000000000080, UE4CodeGen_Private::EPropertyGenFlags::Int, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(GameInstance_GAME259_A_URE_eventJoinServer_Parms, ArrayIndex), METADATA_PARAMS(nullptr, 0) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_UGameInstance_GAME259_A_URE_JoinServer_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_UGameInstance_GAME259_A_URE_JoinServer_Statics::NewProp_ArrayIndex,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_UGameInstance_GAME259_A_URE_JoinServer_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "GameInstance_GAME259_A_URE.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_UGameInstance_GAME259_A_URE_JoinServer_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_UGameInstance_GAME259_A_URE, nullptr, "JoinServer", nullptr, nullptr, sizeof(GameInstance_GAME259_A_URE_eventJoinServer_Parms), Z_Construct_UFunction_UGameInstance_GAME259_A_URE_JoinServer_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameInstance_GAME259_A_URE_JoinServer_Statics::PropPointers), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x04080401, 0, 0, METADATA_PARAMS(Z_Construct_UFunction_UGameInstance_GAME259_A_URE_JoinServer_Statics::Function_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UFunction_UGameInstance_GAME259_A_URE_JoinServer_Statics::Function_MetaDataParams)) };
	UFunction* Z_Construct_UFunction_UGameInstance_GAME259_A_URE_JoinServer()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_UGameInstance_GAME259_A_URE_JoinServer_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UGameInstance_GAME259_A_URE_NoRegister()
	{
		return UGameInstance_GAME259_A_URE::StaticClass();
	}
	struct Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ServerListDel_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_ServerListDel;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SearchingForServer_MetaData[];
#endif
		static const UE4CodeGen_Private::FMulticastDelegatePropertyParams NewProp_SearchingForServer;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_UGameInstance,
		(UObject* (*)())Z_Construct_UPackage__Script_GAME259_A_URE,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_UGameInstance_GAME259_A_URE_CreateServer, "CreateServer" }, // 3087549677
		{ &Z_Construct_UFunction_UGameInstance_GAME259_A_URE_FindServers, "FindServers" }, // 3404798686
		{ &Z_Construct_UFunction_UGameInstance_GAME259_A_URE_JoinServer, "JoinServer" }, // 2139906533
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "GameInstance_GAME259_A_URE.h" },
		{ "ModuleRelativePath", "GameInstance_GAME259_A_URE.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::NewProp_ServerListDel_MetaData[] = {
		{ "ModuleRelativePath", "GameInstance_GAME259_A_URE.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::NewProp_ServerListDel = { "ServerListDel", nullptr, (EPropertyFlags)0x0020080010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameInstance_GAME259_A_URE, ServerListDel), Z_Construct_UDelegateFunction_GAME259_A_URE_ServerDel__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::NewProp_ServerListDel_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::NewProp_ServerListDel_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::NewProp_SearchingForServer_MetaData[] = {
		{ "ModuleRelativePath", "GameInstance_GAME259_A_URE.h" },
	};
#endif
	const UE4CodeGen_Private::FMulticastDelegatePropertyParams Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::NewProp_SearchingForServer = { "SearchingForServer", nullptr, (EPropertyFlags)0x0020080010080000, UE4CodeGen_Private::EPropertyGenFlags::InlineMulticastDelegate, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(UGameInstance_GAME259_A_URE, SearchingForServer), Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature, METADATA_PARAMS(Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::NewProp_SearchingForServer_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::NewProp_SearchingForServer_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::NewProp_ServerListDel,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::NewProp_SearchingForServer,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<UGameInstance_GAME259_A_URE>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::ClassParams = {
		&UGameInstance_GAME259_A_URE::StaticClass,
		nullptr,
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics::PropPointers),
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
	IMPLEMENT_CLASS(UGameInstance_GAME259_A_URE, 2283556039);
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
