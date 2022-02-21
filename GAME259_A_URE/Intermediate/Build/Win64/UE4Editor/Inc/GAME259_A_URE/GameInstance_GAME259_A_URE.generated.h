// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FServerInfo;
#ifdef GAME259_A_URE_GameInstance_GAME259_A_URE_generated_h
#error "GameInstance_GAME259_A_URE.generated.h already included, missing '#pragma once' in GameInstance_GAME259_A_URE.h"
#endif
#define GAME259_A_URE_GameInstance_GAME259_A_URE_generated_h

#define GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_15_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FServerInfo_Statics; \
	GAME259_A_URE_API static class UScriptStruct* StaticStruct();


template<> GAME259_A_URE_API UScriptStruct* StaticStruct<struct FServerInfo>();

#define GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_30_DELEGATE \
struct _Script_GAME259_A_URE_eventServerSearchingDel_Parms \
{ \
	bool SearchingForServer; \
}; \
static inline void FServerSearchingDel_DelegateWrapper(const FMulticastScriptDelegate& ServerSearchingDel, bool SearchingForServer) \
{ \
	_Script_GAME259_A_URE_eventServerSearchingDel_Parms Parms; \
	Parms.SearchingForServer=SearchingForServer ? true : false; \
	ServerSearchingDel.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_27_DELEGATE \
struct _Script_GAME259_A_URE_eventServerDel_Parms \
{ \
	FServerInfo ServerListDel; \
}; \
static inline void FServerDel_DelegateWrapper(const FMulticastScriptDelegate& ServerDel, FServerInfo ServerListDel) \
{ \
	_Script_GAME259_A_URE_eventServerDel_Parms Parms; \
	Parms.ServerListDel=ServerListDel; \
	ServerDel.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_SPARSE_DATA
#define GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execJoinServer); \
	DECLARE_FUNCTION(execFindServers); \
	DECLARE_FUNCTION(execCreateServer);


#define GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execJoinServer); \
	DECLARE_FUNCTION(execFindServers); \
	DECLARE_FUNCTION(execCreateServer);


#define GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUGameInstance_GAME259_A_URE(); \
	friend struct Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics; \
public: \
	DECLARE_CLASS(UGameInstance_GAME259_A_URE, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/GAME259_A_URE"), NO_API) \
	DECLARE_SERIALIZER(UGameInstance_GAME259_A_URE)


#define GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_INCLASS \
private: \
	static void StaticRegisterNativesUGameInstance_GAME259_A_URE(); \
	friend struct Z_Construct_UClass_UGameInstance_GAME259_A_URE_Statics; \
public: \
	DECLARE_CLASS(UGameInstance_GAME259_A_URE, UGameInstance, COMPILED_IN_FLAGS(0 | CLASS_Transient), CASTCLASS_None, TEXT("/Script/GAME259_A_URE"), NO_API) \
	DECLARE_SERIALIZER(UGameInstance_GAME259_A_URE)


#define GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UGameInstance_GAME259_A_URE(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UGameInstance_GAME259_A_URE) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameInstance_GAME259_A_URE); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameInstance_GAME259_A_URE); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameInstance_GAME259_A_URE(UGameInstance_GAME259_A_URE&&); \
	NO_API UGameInstance_GAME259_A_URE(const UGameInstance_GAME259_A_URE&); \
public:


#define GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UGameInstance_GAME259_A_URE(UGameInstance_GAME259_A_URE&&); \
	NO_API UGameInstance_GAME259_A_URE(const UGameInstance_GAME259_A_URE&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UGameInstance_GAME259_A_URE); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UGameInstance_GAME259_A_URE); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UGameInstance_GAME259_A_URE)


#define GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__ServerListDel() { return STRUCT_OFFSET(UGameInstance_GAME259_A_URE, ServerListDel); } \
	FORCEINLINE static uint32 __PPO__SearchingForServer() { return STRUCT_OFFSET(UGameInstance_GAME259_A_URE, SearchingForServer); }


#define GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_35_PROLOG
#define GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_PRIVATE_PROPERTY_OFFSET \
	GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_SPARSE_DATA \
	GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_RPC_WRAPPERS \
	GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_INCLASS \
	GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_PRIVATE_PROPERTY_OFFSET \
	GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_SPARSE_DATA \
	GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_RPC_WRAPPERS_NO_PURE_DECLS \
	GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_INCLASS_NO_PURE_DECLS \
	GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h_38_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME259_A_URE_API UClass* StaticClass<class UGameInstance_GAME259_A_URE>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GAME259_A_URE_Source_GAME259_A_URE_GameInstance_GAME259_A_URE_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
