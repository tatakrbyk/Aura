// Copyright Druid Mechanics

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "CharacterClassInfo.generated.h"

class UGameplayEffect;
class UGameplayAbility;

UENUM(BlueprintType)
enum class ECharacterClass : uint8
{
	Elemantalist,
	Warrior,
	Ranger
};

USTRUCT(BlueprintType)
struct FCharacterClassDefaultInfo
{
	GENERATED_BODY()

	UPROPERTY(EditDefaultsOnly, Category = "Class Defaults")
	TSubclassOf<UGameplayEffect> PrimaryAttributes;

	UPROPERTY(EditDefaultsOnly, Category = "Class Defaults")
	TArray< TSubclassOf<UGameplayAbility>> StartupAbilities;
};

/**
 * 
 */
UCLASS()
class AURA_API UCharacterClassInfo : public UDataAsset
{
	GENERATED_BODY()
public:
	UPROPERTY(EditDefaultsOnly, Category = "Character Class Defaults")
	TMap<ECharacterClass, FCharacterClassDefaultInfo> CharacterClassInformation;

	UPROPERTY(EditDefaultsOnly, Category = "Common Class Defaults")
	TSubclassOf<UGameplayEffect> SecondaryAttibutes;

	UPROPERTY(EditDefaultsOnly, Category = "Common Class Defaults")
	TSubclassOf<UGameplayEffect> VitalAttibutes;

	UPROPERTY(EditDefaultsOnly, Category = "Common Class Defaults")
	TArray<TSubclassOf<UGameplayAbility>> CommonAbilities; // GA_HitReact

	UPROPERTY(EditDefaultsOnly, Category = "Common Class Defaults")
	TObjectPtr<UCurveTable> DamageCalculationCoefficients;

	FCharacterClassDefaultInfo GetClassDefaultInfo(ECharacterClass CharacterClass);

	
};
