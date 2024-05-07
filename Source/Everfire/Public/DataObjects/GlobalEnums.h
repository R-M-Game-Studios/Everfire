// Copyright (C) 2024 Reavers & Marauders (R&M) Game Studios

#pragma once

#include "GlobalEnums.generated.h"

UENUM(BlueprintType)
enum class EPawnAttributes : uint8
{
	EPA_Strength UMETA(DisplayName = "Strength"),
	EPA_Dexterity UMETA(DisplayName = "Dexterity"),
	EPA_Speed UMETA(DisplayName = "Speed"),
	EPA_Vitality UMETA(DisplayName = "Vitality"),
	EPA_Willpower UMETA(DisplayName = "Willpower"),
	EPA_Intelligence UMETA(DisplayName = "Intelligence"),
	EPA_Wisdom UMETA(DisplayName = "Wisdom"),
	EPA_Charisma UMETA(DisplayName = "Charisma"),
	EPA_Luck UMETA(DisplayName = "Luck"),
	EPA_MAX UMETA(DisplayName = "MAX")
};

/** Right now only for testing purpose, before adding the real skills to be used */
UENUM()
enum EPawnSkills : uint8
{
	EPS_Acrobatics,		//Placeholder
	EPS_Fighting,		//Placeholder
	EPS_MAX UMETA(DisplayName = "MAX")
};
