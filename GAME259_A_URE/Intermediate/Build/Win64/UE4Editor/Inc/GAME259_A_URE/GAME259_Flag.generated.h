// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef GAME259_A_URE_GAME259_Flag_generated_h
#error "GAME259_Flag.generated.h already included, missing '#pragma once' in GAME259_Flag.h"
#endif
#define GAME259_A_URE_GAME259_Flag_generated_h

#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_SPARSE_DATA
#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_RPC_WRAPPERS
#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_RPC_WRAPPERS_NO_PURE_DECLS
#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGAME259_Flag(); \
	friend struct Z_Construct_UClass_AGAME259_Flag_Statics; \
public: \
	DECLARE_CLASS(AGAME259_Flag, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GAME259_A_URE"), NO_API) \
	DECLARE_SERIALIZER(AGAME259_Flag) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		owningTeam=NETFIELD_REP_START, \
		NETFIELD_REP_END=owningTeam	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_INCLASS \
private: \
	static void StaticRegisterNativesAGAME259_Flag(); \
	friend struct Z_Construct_UClass_AGAME259_Flag_Statics; \
public: \
	DECLARE_CLASS(AGAME259_Flag, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GAME259_A_URE"), NO_API) \
	DECLARE_SERIALIZER(AGAME259_Flag) \
	void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const override; \
	enum class ENetFields_Private : uint16 \
	{ \
		NETFIELD_REP_START=(uint16)((int32)Super::ENetFields_Private::NETFIELD_REP_END + (int32)1), \
		owningTeam=NETFIELD_REP_START, \
		NETFIELD_REP_END=owningTeam	}; \
	NO_API virtual void ValidateGeneratedRepEnums(const TArray<struct FRepRecord>& ClassReps) const override;


#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGAME259_Flag(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGAME259_Flag) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGAME259_Flag); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGAME259_Flag); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGAME259_Flag(AGAME259_Flag&&); \
	NO_API AGAME259_Flag(const AGAME259_Flag&); \
public:


#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGAME259_Flag(AGAME259_Flag&&); \
	NO_API AGAME259_Flag(const AGAME259_Flag&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGAME259_Flag); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGAME259_Flag); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGAME259_Flag)


#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__owningTeam() { return STRUCT_OFFSET(AGAME259_Flag, owningTeam); }


#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_15_PROLOG
#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_PRIVATE_PROPERTY_OFFSET \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_SPARSE_DATA \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_RPC_WRAPPERS \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_INCLASS \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_PRIVATE_PROPERTY_OFFSET \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_SPARSE_DATA \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_RPC_WRAPPERS_NO_PURE_DECLS \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_INCLASS_NO_PURE_DECLS \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h_18_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME259_A_URE_API UClass* StaticClass<class AGAME259_Flag>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GAME259_A_URE_Source_GAME259_A_URE_GAME259_Flag_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
