// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TagGame/EnemyAIController.h"
#include "Perception/AIPerceptionTypes.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeEnemyAIController() {}
// Cross Module References
	AIMODULE_API UClass* Z_Construct_UClass_AAIController();
	AIMODULE_API UScriptStruct* Z_Construct_UScriptStruct_FAIStimulus();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	TAGGAME_API UClass* Z_Construct_UClass_AEnemyAIController();
	TAGGAME_API UClass* Z_Construct_UClass_AEnemyAIController_NoRegister();
	UPackage* Z_Construct_UPackage__Script_TagGame();
// End Cross Module References
	DEFINE_FUNCTION(AEnemyAIController::execOnTimerElapsed)
	{
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnTimerElapsed();
		P_NATIVE_END;
	}
	DEFINE_FUNCTION(AEnemyAIController::execOnPerception)
	{
		P_GET_OBJECT(AActor,Z_Param_InActor);
		P_GET_STRUCT(FAIStimulus,Z_Param_InStimulus);
		P_FINISH;
		P_NATIVE_BEGIN;
		P_THIS->OnPerception(Z_Param_InActor,Z_Param_InStimulus);
		P_NATIVE_END;
	}
	void AEnemyAIController::StaticRegisterNativesAEnemyAIController()
	{
		UClass* Class = AEnemyAIController::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "OnPerception", &AEnemyAIController::execOnPerception },
			{ "OnTimerElapsed", &AEnemyAIController::execOnTimerElapsed },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, UE_ARRAY_COUNT(Funcs));
	}
	struct Z_Construct_UFunction_AEnemyAIController_OnPerception_Statics
	{
		struct EnemyAIController_eventOnPerception_Parms
		{
			AActor* InActor;
			FAIStimulus InStimulus;
		};
		static const UECodeGen_Private::FObjectPropertyParams NewProp_InActor;
		static const UECodeGen_Private::FStructPropertyParams NewProp_InStimulus;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UFunction_AEnemyAIController_OnPerception_Statics::NewProp_InActor = { "InActor", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EnemyAIController_eventOnPerception_Parms, InActor), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(0, nullptr) };
	const UECodeGen_Private::FStructPropertyParams Z_Construct_UFunction_AEnemyAIController_OnPerception_Statics::NewProp_InStimulus = { "InStimulus", nullptr, (EPropertyFlags)0x0010000000000080, UECodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(EnemyAIController_eventOnPerception_Parms, InStimulus), Z_Construct_UScriptStruct_FAIStimulus, METADATA_PARAMS(0, nullptr) }; // 1355587946
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AEnemyAIController_OnPerception_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemyAIController_OnPerception_Statics::NewProp_InActor,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AEnemyAIController_OnPerception_Statics::NewProp_InStimulus,
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemyAIController_OnPerception_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "EnemyAIController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemyAIController_OnPerception_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemyAIController, nullptr, "OnPerception", nullptr, nullptr, Z_Construct_UFunction_AEnemyAIController_OnPerception_Statics::PropPointers, UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyAIController_OnPerception_Statics::PropPointers), sizeof(Z_Construct_UFunction_AEnemyAIController_OnPerception_Statics::EnemyAIController_eventOnPerception_Parms), RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyAIController_OnPerception_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEnemyAIController_OnPerception_Statics::Function_MetaDataParams) };
	static_assert(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyAIController_OnPerception_Statics::PropPointers) < 2048);
	static_assert(sizeof(Z_Construct_UFunction_AEnemyAIController_OnPerception_Statics::EnemyAIController_eventOnPerception_Parms) < MAX_uint16);
	UFunction* Z_Construct_UFunction_AEnemyAIController_OnPerception()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEnemyAIController_OnPerception_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	struct Z_Construct_UFunction_AEnemyAIController_OnTimerElapsed_Statics
	{
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UECodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AEnemyAIController_OnTimerElapsed_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "EnemyAIController.h" },
	};
#endif
	const UECodeGen_Private::FFunctionParams Z_Construct_UFunction_AEnemyAIController_OnTimerElapsed_Statics::FuncParams = { (UObject*(*)())Z_Construct_UClass_AEnemyAIController, nullptr, "OnTimerElapsed", nullptr, nullptr, nullptr, 0, 0, RF_Public|RF_Transient|RF_MarkAsNative, (EFunctionFlags)0x00020401, 0, 0, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UFunction_AEnemyAIController_OnTimerElapsed_Statics::Function_MetaDataParams), Z_Construct_UFunction_AEnemyAIController_OnTimerElapsed_Statics::Function_MetaDataParams) };
	UFunction* Z_Construct_UFunction_AEnemyAIController_OnTimerElapsed()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UECodeGen_Private::ConstructUFunction(&ReturnFunction, Z_Construct_UFunction_AEnemyAIController_OnTimerElapsed_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(AEnemyAIController);
	UClass* Z_Construct_UClass_AEnemyAIController_NoRegister()
	{
		return AEnemyAIController::StaticClass();
	}
	struct Z_Construct_UClass_AEnemyAIController_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AEnemyAIController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AAIController,
		(UObject* (*)())Z_Construct_UPackage__Script_TagGame,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyAIController_Statics::DependentSingletons) < 16);
	const FClassFunctionLinkInfo Z_Construct_UClass_AEnemyAIController_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AEnemyAIController_OnPerception, "OnPerception" }, // 3875351070
		{ &Z_Construct_UFunction_AEnemyAIController_OnTimerElapsed, "OnTimerElapsed" }, // 1383465600
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyAIController_Statics::FuncInfo) < 2048);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AEnemyAIController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Collision Rendering Transformation" },
		{ "IncludePath", "EnemyAIController.h" },
		{ "ModuleRelativePath", "EnemyAIController.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AEnemyAIController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AEnemyAIController>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_AEnemyAIController_Statics::ClassParams = {
		&AEnemyAIController::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		0,
		0,
		0x009002A4u,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_AEnemyAIController_Statics::Class_MetaDataParams), Z_Construct_UClass_AEnemyAIController_Statics::Class_MetaDataParams)
	};
	UClass* Z_Construct_UClass_AEnemyAIController()
	{
		if (!Z_Registration_Info_UClass_AEnemyAIController.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_AEnemyAIController.OuterSingleton, Z_Construct_UClass_AEnemyAIController_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_AEnemyAIController.OuterSingleton;
	}
	template<> TAGGAME_API UClass* StaticClass<AEnemyAIController>()
	{
		return AEnemyAIController::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(AEnemyAIController);
	AEnemyAIController::~AEnemyAIController() {}
	struct Z_CompiledInDeferFile_FID_Users_giuli_OneDrive_Documenti_GitHub_UE5_3_CPP_AI_TAG_GAME_TagGame_Source_TagGame_EnemyAIController_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_giuli_OneDrive_Documenti_GitHub_UE5_3_CPP_AI_TAG_GAME_TagGame_Source_TagGame_EnemyAIController_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_AEnemyAIController, AEnemyAIController::StaticClass, TEXT("AEnemyAIController"), &Z_Registration_Info_UClass_AEnemyAIController, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(AEnemyAIController), 702244651U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_giuli_OneDrive_Documenti_GitHub_UE5_3_CPP_AI_TAG_GAME_TagGame_Source_TagGame_EnemyAIController_h_3003159517(TEXT("/Script/TagGame"),
		Z_CompiledInDeferFile_FID_Users_giuli_OneDrive_Documenti_GitHub_UE5_3_CPP_AI_TAG_GAME_TagGame_Source_TagGame_EnemyAIController_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_giuli_OneDrive_Documenti_GitHub_UE5_3_CPP_AI_TAG_GAME_TagGame_Source_TagGame_EnemyAIController_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
