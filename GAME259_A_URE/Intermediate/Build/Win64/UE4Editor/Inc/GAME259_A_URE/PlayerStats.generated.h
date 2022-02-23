// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME259_A_URE_PlayerStats_generated_h
#error "PlayerStats.generated.h already included, missing '#pragma once' in PlayerStats.h"
#endif
#define GAME259_A_URE_PlayerStats_generated_h

#define GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_SPARSE_DATA
#define GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_RPC_WRAPPERS \
	virtual bool ServerLowerHealth_Validate(float ); \
	virtual void ServerLowerHealth_Implementation(float value); \
 \
	DECLARE_FUNCTION(execServerLowerHealth);


#define GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execServerLowerHealth);


#define GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_EVENT_PARMS \
	struct PlayerStatsComponent_eventServerLowerHealth_Parms \
	{ \
		float value; \
	};


#define GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_CALLBACK_WRAPPERS
#define GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUPlayerStatsComponent(); \
	friend struct Z_Construct_UClass_UPlayerStatsComponent_Statics; \
public: \
	DECLARE_CLASS(UPlayerStatsComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GAME259_A_URE"), NO_API) \
	DECLARE_SERIALIZER(UPlayerStatsComponent) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Health=NETFIELD_REP_START, \
		NETFIELD_REP_END=Health	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_INCLASS \
private: \
	static void StaticRegisterNativesUPlayerStatsComponent(); \
	friend struct Z_Construct_UClass_UPlayerStatsComponent_Statics; \
public: \
	DECLARE_CLASS(UPlayerStatsComponent, UActorComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GAME259_A_URE"), NO_API) \
	DECLARE_SERIALIZER(UPlayerStatsComponent) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		Health=NETFIELD_REP_START, \
		NETFIELD_REP_END=Health	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UPlayerStatsComponent(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UPlayerStatsComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPlayerStatsComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPlayerStatsComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPlayerStatsComponent(UPlayerStatsComponent&&); \
	NO_API UPlayerStatsComponent(const UPlayerStatsComponent&); \
public:


#define GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UPlayerStatsComponent(UPlayerStatsComponent&&); \
	NO_API UPlayerStatsComponent(const UPlayerStatsComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UPlayerStatsComponent); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UPlayerStatsComponent); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(UPlayerStatsComponent)


#define GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__Health() { return STRUCT_OFFSET(UPlayerStatsComponent, Health); }


#define GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_8_PROLOG \
	GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_EVENT_PARMS


#define GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_PRIVATE_PROPERTY_OFFSET \
	GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_SPARSE_DATA \
	GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_RPC_WRAPPERS \
	GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_CALLBACK_WRAPPERS \
	GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_INCLASS \
	GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_PRIVATE_PROPERTY_OFFSET \
	GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_SPARSE_DATA \
	GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_RPC_WRAPPERS_NO_PURE_DECLS \
	GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_CALLBACK_WRAPPERS \
	GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_INCLASS_NO_PURE_DECLS \
	GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h_11_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME259_A_URE_API UClass* StaticClass<class UPlayerStatsComponent>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GAME259_A_URE_Source_GAME259_A_URE_PlayerStats_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
