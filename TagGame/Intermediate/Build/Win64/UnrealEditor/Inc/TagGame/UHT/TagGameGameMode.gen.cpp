// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "TagGame/TagGameGameMode.h"
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeTagGameGameMode() {}
// Cross Module References
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	TAGGAME_API UClass* Z_Construct_UClass_ABall_NoRegister();
	TAGGAME_API UClass* Z_Construct_UClass_ATagGameGameMode();
	TAGGAME_API UClass* Z_Construct_UClass_ATagGameGameMode_NoRegister();
	UPackage* Z_Construct_UPackage__Script_TagGame();
// End Cross Module References
	void ATagGameGameMode::StaticRegisterNativesATagGameGameMode()
	{
	}
	IMPLEMENT_CLASS_NO_AUTO_REGISTRATION(ATagGameGameMode);
	UClass* Z_Construct_UClass_ATagGameGameMode_NoRegister()
	{
		return ATagGameGameMode::StaticClass();
	}
	struct Z_Construct_UClass_ATagGameGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UECodeGen_Private::FObjectPropertyParams NewProp_GameBalls_Inner;
#if WITH_METADATA
		static const UECodeGen_Private::FMetaDataPairParam NewProp_GameBalls_MetaData[];
#endif
		static const UECodeGen_Private::FArrayPropertyParams NewProp_GameBalls;
		static const UECodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UECodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_ATagGameGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_TagGame,
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATagGameGameMode_Statics::DependentSingletons) < 16);
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATagGameGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering HLOD WorldPartition DataLayers Transformation" },
		{ "IncludePath", "TagGameGameMode.h" },
		{ "ModuleRelativePath", "TagGameGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const UECodeGen_Private::FObjectPropertyParams Z_Construct_UClass_ATagGameGameMode_Statics::NewProp_GameBalls_Inner = { "GameBalls", nullptr, (EPropertyFlags)0x0000000000020000, UECodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, 0, Z_Construct_UClass_ABall_NoRegister, METADATA_PARAMS(0, nullptr) };
#if WITH_METADATA
	const UECodeGen_Private::FMetaDataPairParam Z_Construct_UClass_ATagGameGameMode_Statics::NewProp_GameBalls_MetaData[] = {
		{ "Category", "TagGameGameMode" },
		{ "ModuleRelativePath", "TagGameGameMode.h" },
	};
#endif
	const UECodeGen_Private::FArrayPropertyParams Z_Construct_UClass_ATagGameGameMode_Statics::NewProp_GameBalls = { "GameBalls", nullptr, (EPropertyFlags)0x0020080000020015, UECodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, nullptr, nullptr, 1, STRUCT_OFFSET(ATagGameGameMode, GameBalls), EArrayPropertyFlags::None, METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATagGameGameMode_Statics::NewProp_GameBalls_MetaData), Z_Construct_UClass_ATagGameGameMode_Statics::NewProp_GameBalls_MetaData) };
	const UECodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_ATagGameGameMode_Statics::PropPointers[] = {
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATagGameGameMode_Statics::NewProp_GameBalls_Inner,
		(const UECodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_ATagGameGameMode_Statics::NewProp_GameBalls,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_ATagGameGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<ATagGameGameMode>::IsAbstract,
	};
	const UECodeGen_Private::FClassParams Z_Construct_UClass_ATagGameGameMode_Statics::ClassParams = {
		&ATagGameGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_ATagGameGameMode_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_ATagGameGameMode_Statics::PropPointers),
		0,
		0x008802ACu,
		METADATA_PARAMS(UE_ARRAY_COUNT(Z_Construct_UClass_ATagGameGameMode_Statics::Class_MetaDataParams), Z_Construct_UClass_ATagGameGameMode_Statics::Class_MetaDataParams)
	};
	static_assert(UE_ARRAY_COUNT(Z_Construct_UClass_ATagGameGameMode_Statics::PropPointers) < 2048);
	UClass* Z_Construct_UClass_ATagGameGameMode()
	{
		if (!Z_Registration_Info_UClass_ATagGameGameMode.OuterSingleton)
		{
			UECodeGen_Private::ConstructUClass(Z_Registration_Info_UClass_ATagGameGameMode.OuterSingleton, Z_Construct_UClass_ATagGameGameMode_Statics::ClassParams);
		}
		return Z_Registration_Info_UClass_ATagGameGameMode.OuterSingleton;
	}
	template<> TAGGAME_API UClass* StaticClass<ATagGameGameMode>()
	{
		return ATagGameGameMode::StaticClass();
	}
	DEFINE_VTABLE_PTR_HELPER_CTOR(ATagGameGameMode);
	ATagGameGameMode::~ATagGameGameMode() {}
	struct Z_CompiledInDeferFile_FID_Users_giuli_OneDrive_Documenti_GitHub_UE5_3_CPP_AI_TAG_GAME_TagGame_Source_TagGame_TagGameGameMode_h_Statics
	{
		static const FClassRegisterCompiledInInfo ClassInfo[];
	};
	const FClassRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_giuli_OneDrive_Documenti_GitHub_UE5_3_CPP_AI_TAG_GAME_TagGame_Source_TagGame_TagGameGameMode_h_Statics::ClassInfo[] = {
		{ Z_Construct_UClass_ATagGameGameMode, ATagGameGameMode::StaticClass, TEXT("ATagGameGameMode"), &Z_Registration_Info_UClass_ATagGameGameMode, CONSTRUCT_RELOAD_VERSION_INFO(FClassReloadVersionInfo, sizeof(ATagGameGameMode), 1972910454U) },
	};
	static FRegisterCompiledInInfo Z_CompiledInDeferFile_FID_Users_giuli_OneDrive_Documenti_GitHub_UE5_3_CPP_AI_TAG_GAME_TagGame_Source_TagGame_TagGameGameMode_h_3069158089(TEXT("/Script/TagGame"),
		Z_CompiledInDeferFile_FID_Users_giuli_OneDrive_Documenti_GitHub_UE5_3_CPP_AI_TAG_GAME_TagGame_Source_TagGame_TagGameGameMode_h_Statics::ClassInfo, UE_ARRAY_COUNT(Z_CompiledInDeferFile_FID_Users_giuli_OneDrive_Documenti_GitHub_UE5_3_CPP_AI_TAG_GAME_TagGame_Source_TagGame_TagGameGameMode_h_Statics::ClassInfo),
		nullptr, 0,
		nullptr, 0);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
