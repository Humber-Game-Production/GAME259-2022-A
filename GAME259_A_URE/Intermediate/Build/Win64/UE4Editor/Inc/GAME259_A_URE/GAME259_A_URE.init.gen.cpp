// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGAME259_A_URE_init() {}
	GAME259_A_URE_API UFunction* Z_Construct_UDelegateFunction_GAME259_A_URE_ServerDel__DelegateSignature();
	GAME259_A_URE_API UFunction* Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_GAME259_A_URE()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_GAME259_A_URE_ServerDel__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_GAME259_A_URE_ServerSearchingDel__DelegateSignature,
			};
			static const UE4CodeGen_Private::FPackageParams PackageParams = {
				"/Script/GAME259_A_URE",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x07F51481,
				0x80A83C5D,
				METADATA_PARAMS(nullptr, 0)
			};
			UE4CodeGen_Private::ConstructUPackage(ReturnPackage, PackageParams);
		}
		return ReturnPackage;
	}
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
