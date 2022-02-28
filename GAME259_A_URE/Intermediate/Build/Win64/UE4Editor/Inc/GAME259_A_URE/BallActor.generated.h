// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FHitResult;
#ifdef GAME259_A_URE_BallActor_generated_h
#error "BallActor.generated.h already included, missing '#pragma once' in BallActor.h"
#endif
#define GAME259_A_URE_BallActor_generated_h

#define GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_14_DELEGATE \
struct _Script_GAME259_A_URE_eventMessageStatus_Parms \
{ \
	FString FStatus; \
}; \
static inline void FMessageStatus_DelegateWrapper(const FMulticastScriptDelegate& MessageStatus, const FString& FStatus) \
{ \
	_Script_GAME259_A_URE_eventMessageStatus_Parms Parms; \
	Parms.FStatus=FStatus; \
	MessageStatus.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_11_DELEGATE \
struct _Script_GAME259_A_URE_eventMessageDamage_Parms \
{ \
	float FDamage; \
}; \
static inline void FMessageDamage_DelegateWrapper(const FMulticastScriptDelegate& MessageDamage, float FDamage) \
{ \
	_Script_GAME259_A_URE_eventMessageDamage_Parms Parms; \
	Parms.FDamage=FDamage; \
	MessageDamage.ProcessMulticastDelegate<UObject>(&Parms); \
}


#define GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_SPARSE_DATA
#define GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execBeginOverlap); \
	DECLARE_FUNCTION(execDestroyTimerUp);


#define GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execBeginOverlap); \
	DECLARE_FUNCTION(execDestroyTimerUp);


#define GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesABallActor(); \
	friend struct Z_Construct_UClass_ABallActor_Statics; \
public: \
	DECLARE_CLASS(ABallActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GAME259_A_URE"), NO_API) \
	DECLARE_SERIALIZER(ABallActor)


#define GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_INCLASS \
private: \
	static void StaticRegisterNativesABallActor(); \
	friend struct Z_Construct_UClass_ABallActor_Statics; \
public: \
	DECLARE_CLASS(ABallActor, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/GAME259_A_URE"), NO_API) \
	DECLARE_SERIALIZER(ABallActor)


#define GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ABallActor(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ABallActor) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABallActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABallActor); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABallActor(ABallActor&&); \
	NO_API ABallActor(const ABallActor&); \
public:


#define GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ABallActor(ABallActor&&); \
	NO_API ABallActor(const ABallActor&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ABallActor); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ABallActor); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(ABallActor)


#define GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_PRIVATE_PROPERTY_OFFSET
#define GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_16_PROLOG
#define GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_PRIVATE_PROPERTY_OFFSET \
	GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_SPARSE_DATA \
	GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_RPC_WRAPPERS \
	GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_INCLASS \
	GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_PRIVATE_PROPERTY_OFFSET \
	GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_SPARSE_DATA \
	GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_RPC_WRAPPERS_NO_PURE_DECLS \
	GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_INCLASS_NO_PURE_DECLS \
	GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h_19_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> GAME259_A_URE_API UClass* StaticClass<class ABallActor>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID GAME259_A_URE_Source_GAME259_A_URE_Public_BallActor_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
