// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
struct FDamageEvent;
class AController;
class AActor;
#ifdef GAME259_A_URE_GAME259_A_URECharacter_generated_h
#error "GAME259_A_URECharacter.generated.h already included, missing '#pragma once' in GAME259_A_URECharacter.h"
#endif
#define GAME259_A_URE_GAME259_A_URECharacter_generated_h

#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_SPARSE_DATA
#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execTakeDamage); \
	DECLARE_FUNCTION(execSetCurrentHealth); \
	DECLARE_FUNCTION(execGetCurrentHealth); \
	DECLARE_FUNCTION(execGetMaxHealth);


#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execTakeDamage); \
	DECLARE_FUNCTION(execSetCurrentHealth); \
	DECLARE_FUNCTION(execGetCurrentHealth); \
	DECLARE_FUNCTION(execGetMaxHealth);


#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAGAME259_A_URECharacter(); \
	friend struct Z_Construct_UClass_AGAME259_A_URECharacter_Statics; \
public: \
	DECLARE_CLASS(AGAME259_A_URECharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GAME259_A_URE"), NO_API) \
	DECLARE_SERIALIZER(AGAME259_A_URECharacter)


#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_INCLASS \
private: \
	static void StaticRegisterNativesAGAME259_A_URECharacter(); \
	friend struct Z_Construct_UClass_AGAME259_A_URECharacter_Statics; \
public: \
	DECLARE_CLASS(AGAME259_A_URECharacter, ACharacter, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GAME259_A_URE"), NO_API) \
	DECLARE_SERIALIZER(AGAME259_A_URECharacter)


#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AGAME259_A_URECharacter(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AGAME259_A_URECharacter) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGAME259_A_URECharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGAME259_A_URECharacter); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGAME259_A_URECharacter(AGAME259_A_URECharacter&&); \
	NO_API AGAME259_A_URECharacter(const AGAME259_A_URECharacter&); \
public:


#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AGAME259_A_URECharacter(AGAME259_A_URECharacter&&); \
	NO_API AGAME259_A_URECharacter(const AGAME259_A_URECharacter&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AGAME259_A_URECharacter); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AGAME259_A_URECharacter); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AGAME259_A_URECharacter)


#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CameraBoom() { return STRUCT_OFFSET(AGAME259_A_URECharacter, CameraBoom); } \
	FORCEINLINE static uint32 __PPO__FollowCamera() { return STRUCT_OFFSET(AGAME259_A_URECharacter, FollowCamera); } \
	FORCEINLINE static uint32 __PPO__MaxHealth() { return STRUCT_OFFSET(AGAME259_A_URECharacter, MaxHealth); } \
	FORCEINLINE static uint32 __PPO__CurrentHealth() { return STRUCT_OFFSET(AGAME259_A_URECharacter, CurrentHealth); }


#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_9_PROLOG
#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_SPARSE_DATA \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_RPC_WRAPPERS \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_INCLASS \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_PRIVATE_PROPERTY_OFFSET \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_SPARSE_DATA \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_RPC_WRAPPERS_NO_PURE_DECLS \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_INCLASS_NO_PURE_DECLS \
	GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h_12_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME259_A_URE_API UClass* StaticClass<class AGAME259_A_URECharacter>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GAME259_A_URE_Source_GAME259_A_URE_GAME259_A_URECharacter_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
