#include "pch-il2cpp.h"

#include <Windows.h>
#include "detours/detours.h"
#include "InitHooks.h"
#include <iostream>
#include "DirectX.h"
#include "pipeline/settings.h"
#include <helpers.h>

#include "il2cpp-appdata.h" // For function hooks
using namespace app;

// === Function Hook Definitions ===

float dCalculateBaseDamage(PlayerAttributes* __this, UltimatePlayerController_AttackLevel__Enum attackLevel, MethodInfo* method) {
    float result = PlayerAttributes_CalculateBaseDamage(__this, attackLevel, method);
    std::cout << "[HOOK] PlayerAttributes_CalculateBaseDamage result: " << result << std::endl;
    return result;
}

float dCalculateCritChance(PlayerAttributes* __this, float oppChallengeRating, MethodInfo* method) {
    float result = PlayerAttributes_CalculateCritChance(__this, oppChallengeRating, method);
    std::cout << "[HOOK] PlayerAttributes_CalculateCritChance result: " << result << std::endl;
    return 1.0f;
}

float dget_CritRating(PlayerAttributes* __this, MethodInfo* method) {
    float result = PlayerAttributes_get_CritRating(__this, method);
    std::cout << "[HOOK] PlayerAttributes_get_CritRating result: " << result << std::endl;
    return result;
}

// only output on sp3 but still needs verification
Vector3 dUltimatePlayerController_GetPosition(UltimatePlayerController* __this, MethodInfo* method) {
    Vector3 result = UltimatePlayerController_GetPosition(__this, method);
    std::cout << "[HOOK] UltimatePlayerController_GetPosition result: (" << result.x << ", " << result.y << ", " << result.z << ")" << std::endl;
    return result;
}

void dInit(PlayerAttributes* __this, BCGAttributeData* attributeData, BCGAttributeData* baseAttributeData, BCGBlueprintBase* blueprint, TeamData* team, MethodInfo* method) {
    PlayerAttributes_Init(__this, attributeData, baseAttributeData, blueprint, team, method);
    std::cout << "[HOOK] PlayerAttributes_Init called" << std::endl;
}

StatAttribute* dGetStatAttribute(PlayerAttributes* __this, String* attributeName, MethodInfo* method) {
    StatAttribute* result = PlayerAttributes_GetStatAttribute(__this, attributeName, method);

    std::string attrName = "<null>";
    if (attributeName && attributeName->fields._stringLength > 0) {
        attrName = il2cppi_to_string(attributeName); // Converts Il2CppString* to std::string
    }

    std::cout << "[HOOK] PlayerAttributes_GetStatAttribute called for attribute: " << attrName << std::endl;
    return result;
}


float dget_Armor(PlayerAttributes* __this, MethodInfo* method) {
    float result = PlayerAttributes_get_Armor(__this, method);
    std::cout << "[HOOK] PlayerAttributes_get_Armor result: " << result << std::endl;
    return result;
}

bool dDamageResolver_CanPerfectBlock(PlayerAttributes* __this, MethodInfo* method) {
    bool result = PlayerAttributes_DamageResolver_CanPerfectBlock(__this, method);
    std::cout << "[HOOK] PlayerAttributes_DamageResolver_CanPerfectBlock result: " << std::boolalpha << result << std::endl;
    return result;
}

// === Additional "Calculate" Hooks ===

float dCalculateCritResistChance(PlayerAttributes* __this, float oppChallengeRating, MethodInfo* method) {
    float result = PlayerAttributes_CalculateCritResistChance(__this, oppChallengeRating, method);
    std::cout << "[HOOK] CalculateCritResistChance result: " << result << std::endl;
    return result;
}

float dCalculateDamageInflicted(PlayerAttributes* __this, UltimatePlayerController_AttackLevel__Enum attackLevel, float damagePercentage, bool isCriticalHit, float opponentChallengeRating, MethodInfo* method) {
    float result = PlayerAttributes_CalculateDamageInflicted(__this, attackLevel, damagePercentage, isCriticalHit, opponentChallengeRating, method);
    std::cout << "[HOOK] CalculateDamageInflicted result: " << result << std::endl;
    return result;
}

float dDamageResolver_CalculateDamageReceived(PlayerAttributes* __this, float damage, CharacterDB_MetaData_DamageType__Enum damageType, bool blocked, bool isCrit, PlayerAttributes* opponentAttributes, bool applyResistances, bool applyArmor, bool bypassPositiveDamageReduction, String* source, HitResult* hitResult, bool* isPerfectBlock, Buff_1* sourceBuff, MethodInfo* method) {
    float result = PlayerAttributes_DamageResolver_CalculateDamageReceived(__this, damage, damageType, blocked, isCrit, opponentAttributes, applyResistances, applyArmor, bypassPositiveDamageReduction, source, hitResult, isPerfectBlock, sourceBuff, method);
    std::cout << "[HOOK] DamageResolver_CalculateDamageReceived result: " << result << std::endl;
    return result;
}

float dDamageResolver_CalculatePositiveDamageReductionPercentage(PlayerAttributes* __this, float armorRating, float totalDamageReductionRating, PlayerAttributes* opponentAttributes, MethodInfo* method) {
    float result = PlayerAttributes_DamageResolver_CalculatePositiveDamageReductionPercentage(__this, armorRating, totalDamageReductionRating, opponentAttributes, method);
    std::cout << "[HOOK] PositiveDamageReductionPercentage result: " << result << std::endl;
    return result;
}

float dDamageResolver_CalculateNegativeDamageReductionPercentage(PlayerAttributes* __this, float totalDamageReductionRating, MethodInfo* method) {
    float result = PlayerAttributes_DamageResolver_CalculateNegativeDamageReductionPercentage(__this, totalDamageReductionRating, method);
    std::cout << "[HOOK] NegativeDamageReductionPercentage result: " << result << std::endl;
    return result;
}

float dDamageResolver_CalculateTotalResistanceRating(PlayerAttributes* __this, CharacterDB_MetaData_DamageType__Enum damageType, MethodInfo* method) {
    float result = PlayerAttributes_DamageResolver_CalculateTotalResistanceRating(__this, damageType, method);
    std::cout << "[HOOK] TotalResistanceRating result: " << result << std::endl;
    return result;
}

float dDamageResolver_CalculateTotalArmorRating(PlayerAttributes* __this, MethodInfo* method) {
    float result = PlayerAttributes_DamageResolver_CalculateTotalArmorRating(__this, method);
    std::cout << "[HOOK] TotalArmorRating result: " << result << std::endl;
    return result;
}

// Seems to be the damage received from secondary sources like bleed, needs testing
float dDamageResolver_CalculateDamageReceived_1(PlayerAttributes* __this, float damage, CharacterDB_MetaData_DamageType__Enum damageType, bool blocked, bool isCrit, PlayerAttributes* opponentAttributes, bool applyResistances, bool applyArmor, bool bypassPositiveDamageReduction, String* source, HitResult* hitResult, Buff_1* sourceBuff, MethodInfo* method) {
    float result = PlayerAttributes_DamageResolver_CalculateDamageReceived_1(__this, damage, damageType, blocked, isCrit, opponentAttributes, applyResistances, applyArmor, bypassPositiveDamageReduction, source, hitResult, sourceBuff, method);
    std::cout << "[HOOK] DamageReceived_1 result: " << result << std::endl;
    return result;
}

float dCalculateNegativeArmorRatingDamageReductionPercentage(PlayerAttributes* __this, float armorRating, MethodInfo* method) {
    float result = PlayerAttributes_CalculateNegativeArmorRatingDamageReductionPercentage(__this, armorRating, method);
    std::cout << "[HOOK] NegativeArmorRatingReduction result: " << result << std::endl;
    return result;
}

float dCalculateCritDamage(PlayerAttributes* __this, float critDamage, float opponentChallengeRating, float critMod, MethodInfo* method) {
    float result = PlayerAttributes_CalculateCritDamage(__this, critDamage, opponentChallengeRating, critMod, method);
    std::cout << "[HOOK] CalculateCritDamage result: " << result << std::endl;
    return result;
}

float dCalculateArmorPenetrationPercentage(PlayerAttributes* __this, float armorPenetrationRating, float playerChallengeRating, MethodInfo* method) {
    float result = PlayerAttributes_CalculateArmorPenetrationPercentage(__this, armorPenetrationRating, playerChallengeRating, method);
    std::cout << "[HOOK] ArmorPenetration result: " << result << std::endl;
    return result;
}

float dCalculateBlockProficiencyPercentage(PlayerAttributes* __this, float blockProficiency, float oppChallengeRating, float blockProficiencyMod, MethodInfo* method) {
    float result = PlayerAttributes_CalculateBlockProficiencyPercentage(__this, blockProficiency, oppChallengeRating, blockProficiencyMod, method);
    std::cout << "[HOOK] BlockProficiency result: " << result << std::endl;
    return result;
}

float dCalculateBaseManaGain(PlayerAttributes* __this, UltimatePlayerController_AttackLevel__Enum attackLevel, MethodInfo* method) {
    float result = PlayerAttributes_CalculateBaseManaGain(__this, attackLevel, method);
    std::cout << "[HOOK] BaseManaGain result: " << result << std::endl;
    return result;
}

float dCalculateBaseSupportManaGain(PlayerAttributes* __this, UltimatePlayerController_AttackLevel__Enum attackLevel, MethodInfo* method) {
    float result = PlayerAttributes_CalculateBaseSupportManaGain(__this, attackLevel, method);
    std::cout << "[HOOK] BaseSupportManaGain result: " << result << std::endl;
    return result;
}


// === Ultimate Player Controller ==
void dUltimatePlayerController_OnBattleFightStart(UltimatePlayerController* __this, bool initAI, String* aiProfile, bool aiAllowLevel3, MethodInfo* method) {
    std::cout << "[HOOK] UltimatePlayerController_OnBattleFightStart called" << std::endl;
    std::cout << "  initAI: " << (initAI ? "true" : "false") << std::endl;
    std::cout << "  aiProfile: " << il2cppi_to_string(aiProfile) << std::endl;
    std::cout << "  aiAllowLevel3: " << (aiAllowLevel3 ? "true" : "false") << std::endl;

    UltimatePlayerController_OnBattleFightStart(__this, initAI, aiProfile, aiAllowLevel3, method);
}

void dUltimatePlayerController_add_DamageReceived(UltimatePlayerController* __this, EventHandler_1_DamageReceivedEventArgs_* value, MethodInfo* method) {
    UltimatePlayerController_add_DamageReceived(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_DamageReceived event added" << std::endl;
}

void dUltimatePlayerController_remove_DamageReceived(UltimatePlayerController* __this, EventHandler_1_DamageReceivedEventArgs_* value, MethodInfo* method) {
    UltimatePlayerController_remove_DamageReceived(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_DamageReceived event removed" << std::endl;
}

void dUltimatePlayerController_add_HealReceived(UltimatePlayerController* __this, EventHandler_1_HealReceivedEventArgs_* value, MethodInfo* method) {
    UltimatePlayerController_add_HealReceived(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_HealReceived event added" << std::endl;
}

void dUltimatePlayerController_remove_HealReceived(UltimatePlayerController* __this, EventHandler_1_HealReceivedEventArgs_* value, MethodInfo* method) {
    UltimatePlayerController_remove_HealReceived(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_HealReceived event removed" << std::endl;
}

void dUltimatePlayerController_add_HealthSet(UltimatePlayerController* __this, EventHandler_1_HealthSetEventArgs_* value, MethodInfo* method) {
    UltimatePlayerController_add_HealthSet(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_HealthSet event added" << std::endl;
}

void dUltimatePlayerController_remove_HealthSet(UltimatePlayerController* __this, EventHandler_1_HealthSetEventArgs_* value, MethodInfo* method) {
    UltimatePlayerController_remove_HealthSet(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_HealthSet event removed" << std::endl;
}

void dUltimatePlayerController_add_PlayerDodged(UltimatePlayerController* __this, EventHandler_1_PlayerDodgedEventArgs_* value, MethodInfo* method) {
    UltimatePlayerController_add_PlayerDodged(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_PlayerDodged event added" << std::endl;
}

void dUltimatePlayerController_remove_PlayerDodged(UltimatePlayerController* __this, EventHandler_1_PlayerDodgedEventArgs_* value, MethodInfo* method) {
    UltimatePlayerController_remove_PlayerDodged(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_PlayerDodged event removed" << std::endl;
}

void dUltimatePlayerController_add_PlayerInvulnerable(UltimatePlayerController* __this, EventHandler_1_PlayerInvulnerableEventArgs_* value, MethodInfo* method) {
    UltimatePlayerController_add_PlayerInvulnerable(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_PlayerInvulnerable event added" << std::endl;
}

void dUltimatePlayerController_remove_PlayerInvulnerable(UltimatePlayerController* __this, EventHandler_1_PlayerInvulnerableEventArgs_* value, MethodInfo* method) {
    UltimatePlayerController_remove_PlayerInvulnerable(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_PlayerInvulnerable event removed" << std::endl;
}

void dUltimatePlayerController_add_PlayerBuffAdded(UltimatePlayerController* __this, Action_2_EB_Gameplay_StatMods_Buff_EB_Gameplay_StatMods_BuffResult_* value, MethodInfo* method) {
    UltimatePlayerController_add_PlayerBuffAdded(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_PlayerBuffAdded event added" << std::endl;
}

void dUltimatePlayerController_remove_PlayerBuffAdded(UltimatePlayerController* __this, Action_2_EB_Gameplay_StatMods_Buff_EB_Gameplay_StatMods_BuffResult_* value, MethodInfo* method) {
    UltimatePlayerController_remove_PlayerBuffAdded(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_PlayerBuffAdded event removed" << std::endl;
}

void dUltimatePlayerController_add_PlayerBuffPauseChanged(UltimatePlayerController* __this, Action_1_EB_Gameplay_StatMods_Buff__1* value, MethodInfo* method) {
    UltimatePlayerController_add_PlayerBuffPauseChanged(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_PlayerBuffPauseChanged event added" << std::endl;
}

void dUltimatePlayerController_remove_PlayerBuffPauseChanged(UltimatePlayerController* __this, Action_1_EB_Gameplay_StatMods_Buff__1* value, MethodInfo* method) {
    UltimatePlayerController_remove_PlayerBuffPauseChanged(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_PlayerBuffPauseChanged event removed" << std::endl;
}

void dUltimatePlayerController_add_LateBlockDetected(UltimatePlayerController* __this, Action_1_System_Int32_* value, MethodInfo* method) {
    UltimatePlayerController_add_LateBlockDetected(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_LateBlockDetected event added" << std::endl;
}

void dUltimatePlayerController_remove_LateBlockDetected(UltimatePlayerController* __this, Action_1_System_Int32_* value, MethodInfo* method) {
    UltimatePlayerController_remove_LateBlockDetected(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_LateBlockDetected event removed" << std::endl;
}

void dUltimatePlayerController_add_OnBlockDetected(UltimatePlayerController* __this, Action_1_System_Int32_* value, MethodInfo* method) {
    UltimatePlayerController_add_OnBlockDetected(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_OnBlockDetected event added" << std::endl;
}

void dUltimatePlayerController_remove_OnBlockDetected(UltimatePlayerController* __this, Action_1_System_Int32_* value, MethodInfo* method) {
    UltimatePlayerController_remove_OnBlockDetected(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_OnBlockDetected event removed" << std::endl;
}

void dUltimatePlayerController_add_OnUnblockDetected(UltimatePlayerController* __this, Action_1_System_Int32_* value, MethodInfo* method) {
    UltimatePlayerController_add_OnUnblockDetected(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_OnUnblockDetected event added" << std::endl;
}

void dUltimatePlayerController_remove_OnUnblockDetected(UltimatePlayerController* __this, Action_1_System_Int32_* value, MethodInfo* method) {
    UltimatePlayerController_remove_OnUnblockDetected(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_OnUnblockDetected event removed" << std::endl;
}

void dUltimatePlayerController_add_OnComboChainReset(UltimatePlayerController* __this, Action_1* value, MethodInfo* method) {
    UltimatePlayerController_add_OnComboChainReset(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_OnComboChainReset event added" << std::endl;
}

void dUltimatePlayerController_remove_OnComboChainReset(UltimatePlayerController* __this, Action_1* value, MethodInfo* method) {
    UltimatePlayerController_remove_OnComboChainReset(__this, value, method);
    std::cout << "[HOOK] UltimatePlayerController_OnComboChainReset event removed" << std::endl;
}

void dGetToggleRunTutorialStatMod(UltimatePlayerController* __this, MethodInfo* method) {
    auto result = UltimatePlayerController_get_ToggleRunTutorialStatMod(__this, method);
    std::cout << "[HOOK] UltimatePlayerController_get_ToggleRunTutorialStatMod called" << std::endl;
}

void dGetAttackLevelFromSpecial(UltimatePlayerController* __this, int32_t specialIndex, MethodInfo* method) {
    auto result = UltimatePlayerController_GetAttackLevelFromSpecial(__this, specialIndex, method);
    std::cout << "[HOOK] UltimatePlayerController_GetAttackLevelFromSpecial called | specialIndex: " << specialIndex << std::endl;
}

void dIsBasicAttack(UltimatePlayerController_AttackLevel__Enum attackLevel, MethodInfo* method) {
    auto result = UltimatePlayerController_IsBasicAttack(attackLevel, method);
    std::cout << "[HOOK] UltimatePlayerController_IsBasicAttack called | attackLevel: " << static_cast<int>(attackLevel) << std::endl;
}

void dGetCustomStagePrefab(UltimatePlayerController* __this, String* stageName, MethodInfo* method) {
    auto result = UltimatePlayerController_GetCustomStagePrefab(__this, stageName, method);
    std::cout << "[HOOK] UltimatePlayerController_GetCustomStagePrefab called | stageName: " << il2cppi_to_string(stageName) << std::endl;
}

void dGetTelemetryBuffVariables(UltimatePlayerController* __this, MethodInfo* method) {
    auto result = UltimatePlayerController_get_TelemetryBuffVariables(__this, method);
    std::cout << "[HOOK] UltimatePlayerController_get_TelemetryBuffVariables called" << std::endl;
}

void dGetCurrentFXTriggerState(UltimatePlayerController* __this, MethodInfo* method) {
    auto result = UltimatePlayerController_GetCurrentFXTriggerState(__this, method);
    std::cout << "[HOOK] UltimatePlayerController_GetCurrentFXTriggerState called" << std::endl;
}

void dRestartFXTriggers(UltimatePlayerController* __this, FXTrigger_States__Enum state, bool defaultShouldPlay, MethodInfo* method) {
    UltimatePlayerController_RestartFXTriggers(__this, state, defaultShouldPlay, method);
    std::cout << "[HOOK] UltimatePlayerController_RestartFXTriggers called | state: " << static_cast<int>(state) << ", defaultShouldPlay: " << defaultShouldPlay << std::endl;
}

void dSuspendAllFXTriggers(UltimatePlayerController* __this, FXTrigger_States__Enum state, bool defaultShouldStop, MethodInfo* method) {
    UltimatePlayerController_SuspendAllFXTriggers(__this, state, defaultShouldStop, method);
    std::cout << "[HOOK] UltimatePlayerController_SuspendAllFXTriggers called | state: " << static_cast<int>(state) << ", defaultShouldStop: " << defaultShouldStop << std::endl;
}

void dAwake(UltimatePlayerController* __this, MethodInfo* method) {
    UltimatePlayerController_Awake(__this, method);
    std::cout << "[HOOK] UltimatePlayerController_Awake called" << std::endl;
}

void dApplyFresnelEffect(UltimatePlayerController* __this, Color fresnelColor, MethodInfo* method) {
    UltimatePlayerController_ApplyFresnelEffect(__this, fresnelColor, method);
    std::cout << "[HOOK] UltimatePlayerController_ApplyFresnelEffect called" << std::endl;
}

void dRemoveFresnelEffect(UltimatePlayerController* __this, MethodInfo* method) {
    UltimatePlayerController_RemoveFresnelEffect(__this, method);
    std::cout << "[HOOK] UltimatePlayerController_RemoveFresnelEffect called" << std::endl;
}

void dAddAndRefreshBoneScalar(UltimatePlayerController* __this, MethodInfo* method) {
    auto result = UltimatePlayerController_AddAndRefreshBoneScalar(__this, method);
    std::cout << "[HOOK] UltimatePlayerController_AddAndRefreshBoneScalar called" << std::endl;
}

void dInitializeBoneScalerBasePose(UltimatePlayerController* __this, MethodInfo* method) {
    UltimatePlayerController_InitializeBoneScalerBasePose(__this, method);
    std::cout << "[HOOK] UltimatePlayerController_InitializeBoneScalerBasePose called" << std::endl;
}

void dOnDestroy(UltimatePlayerController* __this, MethodInfo* method) {
    UltimatePlayerController_OnDestroy(__this, method);
    std::cout << "[HOOK] UltimatePlayerController_OnDestroy called" << std::endl;
}

void dAttachToEvents(UltimatePlayerController* __this, MethodInfo* method) {
    UltimatePlayerController_AttachToEvents(__this, method);
    std::cout << "[HOOK] UltimatePlayerController_AttachToEvents called" << std::endl;
}

void dDetachFromEvents(UltimatePlayerController* __this, MethodInfo* method) {
    UltimatePlayerController_DetachFromEvents(__this, method);
    std::cout << "[HOOK] UltimatePlayerController_DetachFromEvents called" << std::endl;
}

void dResetComboTracker(UltimatePlayerController* __this, MethodInfo* method) {
    UltimatePlayerController_ResetComboTracker(__this, method);
    std::cout << "[HOOK] UltimatePlayerController_ResetComboTracker called" << std::endl;
}

void dInitComboMetrics(UltimatePlayerController* __this, MethodInfo* method) {
    UltimatePlayerController_InitComboMetrics(__this, method);
    std::cout << "[HOOK] UltimatePlayerController_InitComboMetrics called" << std::endl;
}

void dStart(UltimatePlayerController* __this, MethodInfo* method) {
    UltimatePlayerController_Start(__this, method);
    std::cout << "[HOOK] UltimatePlayerController_Start called" << std::endl;
}

void dReset(UltimatePlayerController* __this, MethodInfo* method) {
    UltimatePlayerController_Reset(__this, method);
    std::cout << "[HOOK] UltimatePlayerController_Reset called" << std::endl;
}

void dInitPlayer(UltimatePlayerController* __this, bool isPlayer, bool allowLevel3, String* aiProfile, MethodInfo* method) {
    UltimatePlayerController_InitPlayer(__this, isPlayer, allowLevel3, aiProfile, method);
    std::cout << "[HOOK] UltimatePlayerController_InitPlayer called | isPlayer: " << isPlayer << ", allowLevel3: " << allowLevel3 << ", aiProfile: " << il2cppi_to_string(aiProfile) << std::endl;
}

void dInitCharacterScalersID(UltimatePlayerController* __this, int32_t id, MethodInfo* method) {
    UltimatePlayerController_InitCharacterScalersID(__this, id, method);
    std::cout << "[HOOK] UltimatePlayerController_InitCharacterScalersID called | id: " << id << std::endl;
}

void dOnInitPlayer(UltimatePlayerController* __this, bool isPlayer, MethodInfo* method) {
    UltimatePlayerController_OnInitPlayer(__this, isPlayer, method);
    std::cout << "[HOOK] UltimatePlayerController_OnInitPlayer called | isPlayer: " << std::boolalpha << isPlayer << std::endl;
}

void dInitAttributes(UltimatePlayerController* __this, BCGAttributeData* attributeData, BCGAttributeData* baseAttributeData, BCGBlueprintBase* blueprint, TeamData* team, MethodInfo* method) {
    UltimatePlayerController_InitAttributes(__this, attributeData, baseAttributeData, blueprint, team, method);
    std::cout << "[HOOK] UltimatePlayerController_InitAttributes called" << std::endl;
}

void dRegisterStatMods(UltimatePlayerController* __this, BCGAttributeData* attributeData, int32_t signatureLevel, Dictionary_2_System_String_List_1_System_String_* debugStatMods, String* excludeStatMods, bool useDebugMasteries, FightMode_StatModAssignment__Enum assignment, List_1_System_String_* mapMods, List_1_System_String_* draftMods, IReadOnlyList_1_System_String_* preFightMods, IReadOnlyList_1_BCGCrossFightAbilityData_* crossFightMods, IReadOnlyList_1_DynamicStatModDefinition_* dynamicStatModDefinitions, MethodInfo* method) {
    int32_t newSigLevel = 200;
    UltimatePlayerController_RegisterStatMods(__this, attributeData, newSigLevel, debugStatMods, excludeStatMods, useDebugMasteries, assignment, mapMods, draftMods, preFightMods, crossFightMods, dynamicStatModDefinitions, method);
    std::cout << "[HOOK] UltimatePlayerController_RegisterStatMods called | signatureLevel: " << signatureLevel << ", excludeStatMods: " << il2cppi_to_string(excludeStatMods) << ", useDebugMasteries: " << useDebugMasteries << std::endl;
}

void dRegisterGameplayStatmods(UltimatePlayerController* __this, BCGAttributeData* attributeData, MethodInfo* method) {
    UltimatePlayerController_RegisterGameplayStatmods(__this, attributeData, method);
    std::cout << "[HOOK] UltimatePlayerController_RegisterGameplayStatmods called" << std::endl;
}

// === DraftBuffInfoPanel

void LogBuffList(app::List_1_EB_Sparx_Buff_* buffList) {
    if (!buffList || !buffList->fields._items) {
        std::cout << "Buff list is null." << std::endl;
        return;
    }

    int count = buffList->fields._size;
    std::cout << "Buff List Count: " << count << std::endl;

    for (int i = 0; i < count; ++i) {
        app::Buff* buff = buffList->fields._items->vector[i];
        if (!buff) continue;

        auto& f = buff->fields;

        std::cout << "  Buff[" << i << "]" << std::endl;
        std::cout << "    id: " << il2cppi_to_string(f._id_k__BackingField) << std::endl;
        std::cout << "    localizedName: " << il2cppi_to_string(f._localizedName_k__BackingField) << std::endl;
        std::cout << "    localizedDesc: " << il2cppi_to_string(f._localizedDesc_k__BackingField) << std::endl;
        std::cout << "    buffType: " << il2cppi_to_string(f._buffType_k__BackingField) << std::endl;
        std::cout << "    displayValue: " << f._displayValue_k__BackingField << std::endl;
        std::cout << "    duration: " << f._duration_k__BackingField << std::endl;
        std::cout << "    useCount: " << f._useCount_k__BackingField << std::endl;
        std::cout << "    tags: " << il2cppi_to_string(f._tags_k__BackingField) << std::endl;
    }
}



void dSet(DraftBuffInfoPanel* __this, app::List_1_EB_Sparx_Buff_* attackerBuffs, app::List_1_EB_Sparx_Buff_* defenderBuffs, app::Action_1* onComplete, MethodInfo* method) {
    std::cout << "[HOOK] DraftBuffInfoPanel_Set" << std::endl;

    std::cout << "  [Attacker Buffs]" << std::endl;
    LogBuffList(attackerBuffs);

    std::cout << "  [Defender Buffs]" << std::endl;
    LogBuffList(defenderBuffs);

    if (defenderBuffs && defenderBuffs->fields._items && defenderBuffs->fields._size > 0) {
        app::Buff* buff = defenderBuffs->fields._items->vector[0];
        if (buff) {
            std::string id = il2cppi_to_string(buff->fields._id_k__BackingField);
            if (id == "pve_sorcerer_striker_1") {
                buff->fields._localizedName_k__BackingField = (app::String*)il2cpp_string_new("KT Level 1");
                buff->fields._localizedDesc_k__BackingField = (app::String*)il2cpp_string_new("Every 5 seconds the like press count on stream must increment by at least 1 or your champion is knocked out. The timer resets if the like button is hit or a donation is made.");

                std::cout << "[MODIFIED] Buff[0] id matched. localizedName and localizedDesc updated." << std::endl;
            }
        }
    }

    DraftBuffInfoPanel_Set(__this, attackerBuffs, defenderBuffs, onComplete, method);
}


void dSetSplitView(DraftBuffInfoPanel* __this, app::List_1_EB_Sparx_Buff_* attackerBuffs, app::List_1_EB_Sparx_Buff_* defenderBuffs, MethodInfo* method) {
    std::cout << "[HOOK] DraftBuffInfoPanel_SetSplitView" << std::endl;

    std::cout << "  [Attacker Buffs]" << std::endl;
    LogBuffList(attackerBuffs);

    std::cout << "  [Defender Buffs]" << std::endl;
    LogBuffList(defenderBuffs);

    if (defenderBuffs && defenderBuffs->fields._items && defenderBuffs->fields._size > 0) {
        app::Buff* buff = defenderBuffs->fields._items->vector[0];
        if (buff) {
            std::string id = il2cppi_to_string(buff->fields._id_k__BackingField);
            if (id == "pve_sorcerer_striker_1") {
                buff->fields._localizedName_k__BackingField = (app::String*)il2cpp_string_new("KT Level 1");
                buff->fields._localizedDesc_k__BackingField = (app::String*)il2cpp_string_new("Every 5 seconds the like press count on stream must increment by at least 1 or your champion is knocked out. The timer resets if the like button is hit or a donation is made.");
                std::cout << "[MODIFIED] Buff[0] id matched. localizedName and localizedDesc updated." << std::endl;
            }
        }
    }

    DraftBuffInfoPanel_SetSplitView(__this, attackerBuffs, defenderBuffs, method);
}


void dSetCenteredView(DraftBuffInfoPanel* __this, app::List_1_EB_Sparx_Buff_* buffs, bool isAttackerBuffs, MethodInfo* method) {
    std::cout << "[HOOK] DraftBuffInfoPanel_SetCenteredView | isAttackerBuffs: " << std::boolalpha << isAttackerBuffs << std::endl;
    LogBuffList(buffs);

    if (buffs && buffs->fields._items && buffs->fields._size > 0) {
        app::Buff* buff = buffs->fields._items->vector[0];
        if (buff) {
            std::string id = il2cppi_to_string(buff->fields._id_k__BackingField);
            if (id == "pve_sorcerer_striker_1") {
                buff->fields._localizedName_k__BackingField = (app::String*)il2cpp_string_new("KT Level 1");
                buff->fields._localizedDesc_k__BackingField = (app::String*)il2cpp_string_new("Every 5 seconds the like press count on stream must increment by at least 1 or your champion is knocked out. The timer resets if the like button is hit or a donation is made.");
                std::cout << "[MODIFIED] Buff[0] id matched. localizedName and localizedDesc updated." << std::endl;
            }
        }
    }

    DraftBuffInfoPanel_SetCenteredView(__this, buffs, isAttackerBuffs, method);
}




// === Hook Helpers ===

bool HookFunction(PVOID* ppPointer, PVOID pDetour, const char* functionName) {
    if (!*ppPointer) {
        std::cout << "[ERROR]: Target function pointer for " << functionName << " is null!" << std::endl;
        return false;
    }
    if (const auto error = DetourAttach(ppPointer, pDetour); error != NO_ERROR) {
        std::cout << "[ERROR]: Failed to hook " << functionName << ", error " << error << std::endl;
        return false;
    }
    std::cout << "[HOOKED]: " << functionName << std::endl;
    return true;
}

#define HOOKFUNC(n) if (!HookFunction(&(PVOID&)n, d##n, #n)) return;

bool UnhookFunction(PVOID* ppPointer, PVOID pDetour, const char* functionName) {
    if (!*ppPointer) {
        std::cout << "[ERROR]: Target function pointer for " << functionName << " is null (unhook)." << std::endl;
        return false;
    }
    if (const auto error = DetourDetach(ppPointer, pDetour); error != NO_ERROR) {
        std::cout << "[ERROR]: Failed to unhook " << functionName << ", error " << error << std::endl;
        return false;
    }
    std::cout << "[UNHOOKED]: " << functionName << std::endl;
    return true;
}

#define UNHOOKFUNC(n) if (!UnhookFunction(&(PVOID&)n, d##n, #n)) return;

// === Initialization ===

void DetourInitilization() {
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    dx11api d3d11 = dx11api();
    if (!d3d11.presentFunction) {
        std::cout << "[ERROR]: Unable to retrieve IDXGISwapChain::Present method" << std::endl;
        return;
    }

    oPresent = d3d11.presentFunction;
    if (!oPresent) {
        std::cout << "[ERROR]: oPresent is null!" << std::endl;
        return;
    }

    std::cout << "[INFO]: Attempting to hook oPresent at address: " << oPresent << std::endl;

    if (!HookFunction(&(PVOID&)oPresent, dPresent, "D3D_PRESENT_FUNCTION")) {
        DetourTransactionAbort();
        return;
    }

    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateBaseDamage), dCalculateBaseDamage, "PlayerAttributes_CalculateBaseDamage");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateCritChance), dCalculateCritChance, "PlayerAttributes_CalculateCritChance");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_get_CritRating), dget_CritRating, "PlayerAttributes_get_CritRating");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_GetPosition), dUltimatePlayerController_GetPosition, "UltimatePlayerController_GetPosition");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_Init), dInit, "PlayerAttributes_Init");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_GetStatAttribute), dGetStatAttribute, "PlayerAttributes_GetStatAttribute");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_get_Armor), dget_Armor, "PlayerAttributes_get_Armor");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_DamageResolver_CanPerfectBlock), dDamageResolver_CanPerfectBlock, "PlayerAttributes_DamageResolver_CanPerfectBlock");

    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateCritResistChance), dCalculateCritResistChance, "CalculateCritResistChance");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateDamageInflicted), dCalculateDamageInflicted, "CalculateDamageInflicted");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_DamageResolver_CalculateDamageReceived), dDamageResolver_CalculateDamageReceived, "DamageResolver_CalculateDamageReceived");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_DamageResolver_CalculatePositiveDamageReductionPercentage), dDamageResolver_CalculatePositiveDamageReductionPercentage, "PositiveDamageReductionPercentage");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_DamageResolver_CalculateNegativeDamageReductionPercentage), dDamageResolver_CalculateNegativeDamageReductionPercentage, "NegativeDamageReductionPercentage");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_DamageResolver_CalculateTotalResistanceRating), dDamageResolver_CalculateTotalResistanceRating, "TotalResistanceRating");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_DamageResolver_CalculateTotalArmorRating), dDamageResolver_CalculateTotalArmorRating, "TotalArmorRating");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_DamageResolver_CalculateDamageReceived_1), dDamageResolver_CalculateDamageReceived_1, "DamageReceived_1");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateNegativeArmorRatingDamageReductionPercentage), dCalculateNegativeArmorRatingDamageReductionPercentage, "NegativeArmorRatingReduction");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateCritDamage), dCalculateCritDamage, "CalculateCritDamage");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateArmorPenetrationPercentage), dCalculateArmorPenetrationPercentage, "ArmorPenetration");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateBlockProficiencyPercentage), dCalculateBlockProficiencyPercentage, "BlockProficiency");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateBaseManaGain), dCalculateBaseManaGain, "BaseManaGain");
    HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateBaseSupportManaGain), dCalculateBaseSupportManaGain, "BaseSupportManaGain");

    // UltimatePlayerController
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_OnBattleFightStart), dUltimatePlayerController_OnBattleFightStart, "UltimatePlayerController_OnBattleFightStart");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_DamageReceived), dUltimatePlayerController_add_DamageReceived, "UltimatePlayerController_add_DamageReceived");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_DamageReceived), dUltimatePlayerController_remove_DamageReceived, "UltimatePlayerController_remove_DamageReceived");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_HealReceived), dUltimatePlayerController_add_HealReceived, "UltimatePlayerController_add_HealReceived");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_HealReceived), dUltimatePlayerController_remove_HealReceived, "UltimatePlayerController_remove_HealReceived");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_HealthSet), dUltimatePlayerController_add_HealthSet, "UltimatePlayerController_add_HealthSet");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_HealthSet), dUltimatePlayerController_remove_HealthSet, "UltimatePlayerController_remove_HealthSet");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_PlayerDodged), dUltimatePlayerController_add_PlayerDodged, "UltimatePlayerController_add_PlayerDodged");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_PlayerDodged), dUltimatePlayerController_remove_PlayerDodged, "UltimatePlayerController_remove_PlayerDodged");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_PlayerInvulnerable), dUltimatePlayerController_add_PlayerInvulnerable, "UltimatePlayerController_add_PlayerInvulnerable");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_PlayerInvulnerable), dUltimatePlayerController_remove_PlayerInvulnerable, "UltimatePlayerController_remove_PlayerInvulnerable");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_PlayerBuffAdded), dUltimatePlayerController_add_PlayerBuffAdded, "UltimatePlayerController_add_PlayerBuffAdded");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_PlayerBuffAdded), dUltimatePlayerController_remove_PlayerBuffAdded, "UltimatePlayerController_remove_PlayerBuffAdded");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_PlayerBuffPauseChanged), dUltimatePlayerController_add_PlayerBuffPauseChanged, "UltimatePlayerController_add_PlayerBuffPauseChanged");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_PlayerBuffPauseChanged), dUltimatePlayerController_remove_PlayerBuffPauseChanged, "UltimatePlayerController_remove_PlayerBuffPauseChanged");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_LateBlockDetected), dUltimatePlayerController_add_LateBlockDetected, "UltimatePlayerController_add_LateBlockDetected");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_LateBlockDetected), dUltimatePlayerController_remove_LateBlockDetected, "UltimatePlayerController_remove_LateBlockDetected");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_OnBlockDetected), dUltimatePlayerController_add_OnBlockDetected, "UltimatePlayerController_add_OnBlockDetected");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_OnBlockDetected), dUltimatePlayerController_remove_OnBlockDetected, "UltimatePlayerController_remove_OnBlockDetected");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_OnUnblockDetected), dUltimatePlayerController_add_OnUnblockDetected, "UltimatePlayerController_add_OnUnblockDetected");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_OnUnblockDetected), dUltimatePlayerController_remove_OnUnblockDetected, "UltimatePlayerController_remove_OnUnblockDetected");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_OnComboChainReset), dUltimatePlayerController_add_OnComboChainReset, "UltimatePlayerController_add_OnComboChainReset");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_OnComboChainReset), dUltimatePlayerController_remove_OnComboChainReset, "UltimatePlayerController_remove_OnComboChainReset");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_get_ToggleRunTutorialStatMod), dGetToggleRunTutorialStatMod, "UltimatePlayerController_get_ToggleRunTutorialStatMod");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_GetAttackLevelFromSpecial), dGetAttackLevelFromSpecial, "UltimatePlayerController_GetAttackLevelFromSpecial");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_IsBasicAttack), dIsBasicAttack, "UltimatePlayerController_IsBasicAttack");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_GetCustomStagePrefab), dGetCustomStagePrefab, "UltimatePlayerController_GetCustomStagePrefab");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_get_TelemetryBuffVariables), dGetTelemetryBuffVariables, "UltimatePlayerController_get_TelemetryBuffVariables");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_GetCurrentFXTriggerState), dGetCurrentFXTriggerState, "UltimatePlayerController_GetCurrentFXTriggerState");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_RestartFXTriggers), dRestartFXTriggers, "UltimatePlayerController_RestartFXTriggers");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_SuspendAllFXTriggers), dSuspendAllFXTriggers, "UltimatePlayerController_SuspendAllFXTriggers");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_Awake), dAwake, "UltimatePlayerController_Awake");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_ApplyFresnelEffect), dApplyFresnelEffect, "UltimatePlayerController_ApplyFresnelEffect");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_RemoveFresnelEffect), dRemoveFresnelEffect, "UltimatePlayerController_RemoveFresnelEffect");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_AddAndRefreshBoneScalar), dAddAndRefreshBoneScalar, "UltimatePlayerController_AddAndRefreshBoneScalar");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_InitializeBoneScalerBasePose), dInitializeBoneScalerBasePose, "UltimatePlayerController_InitializeBoneScalerBasePose");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_OnDestroy), dOnDestroy, "UltimatePlayerController_OnDestroy");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_AttachToEvents), dAttachToEvents, "UltimatePlayerController_AttachToEvents");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_DetachFromEvents), dDetachFromEvents, "UltimatePlayerController_DetachFromEvents");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_ResetComboTracker), dResetComboTracker, "UltimatePlayerController_ResetComboTracker");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_InitComboMetrics), dInitComboMetrics, "UltimatePlayerController_InitComboMetrics");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_Start), dStart, "UltimatePlayerController_Start");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_Reset), dReset, "UltimatePlayerController_Reset");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_InitPlayer), dInitPlayer, "UltimatePlayerController_InitPlayer");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_InitCharacterScalersID), dInitCharacterScalersID, "UltimatePlayerController_InitCharacterScalersID");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_OnInitPlayer), dOnInitPlayer, "UltimatePlayerController_OnInitPlayer");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_InitAttributes), dInitAttributes, "UltimatePlayerController_InitAttributes");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_RegisterStatMods), dRegisterStatMods, "UltimatePlayerController_RegisterStatMods");
    HookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_RegisterGameplayStatmods), dRegisterGameplayStatmods, "UltimatePlayerController_RegisterGameplayStatmods");

    // DraftBuffInfoPanel
    HookFunction(reinterpret_cast<PVOID*>(&DraftBuffInfoPanel_Set), dSet, "DraftBuffInfoPanel_Set");
    HookFunction(reinterpret_cast<PVOID*>(&DraftBuffInfoPanel_SetCenteredView), dSetCenteredView, "DraftBuffInfoPanel_SetCenteredView");
    HookFunction(reinterpret_cast<PVOID*>(&DraftBuffInfoPanel_SetSplitView), dSetSplitView, "DraftBuffInfoPanel_SetSplitView");

    DetourTransactionCommit();
}

void DetourUninitialization() {
    DetourTransactionBegin();
    DetourUpdateThread(GetCurrentThread());

    if (DetourDetach(&(PVOID&)oPresent, dPresent) != 0) return;

    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateBaseDamage), dCalculateBaseDamage, "PlayerAttributes_CalculateBaseDamage");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateCritChance), dCalculateCritChance, "PlayerAttributes_CalculateCritChance");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_get_CritRating), dget_CritRating, "PlayerAttributes_get_CritRating");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_GetPosition), dUltimatePlayerController_GetPosition, "UltimatePlayerController_GetPosition");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_Init), dInit, "PlayerAttributes_Init");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_GetStatAttribute), dGetStatAttribute, "PlayerAttributes_GetStatAttribute");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_get_Armor), dget_Armor, "PlayerAttributes_get_Armor");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_DamageResolver_CanPerfectBlock), dDamageResolver_CanPerfectBlock, "PlayerAttributes_DamageResolver_CanPerfectBlock");

    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateCritResistChance), dCalculateCritResistChance, "CalculateCritResistChance");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateDamageInflicted), dCalculateDamageInflicted, "CalculateDamageInflicted");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_DamageResolver_CalculateDamageReceived), dDamageResolver_CalculateDamageReceived, "DamageResolver_CalculateDamageReceived");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_DamageResolver_CalculatePositiveDamageReductionPercentage), dDamageResolver_CalculatePositiveDamageReductionPercentage, "PositiveDamageReductionPercentage");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_DamageResolver_CalculateNegativeDamageReductionPercentage), dDamageResolver_CalculateNegativeDamageReductionPercentage, "NegativeDamageReductionPercentage");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_DamageResolver_CalculateTotalResistanceRating), dDamageResolver_CalculateTotalResistanceRating, "TotalResistanceRating");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_DamageResolver_CalculateTotalArmorRating), dDamageResolver_CalculateTotalArmorRating, "TotalArmorRating");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_DamageResolver_CalculateDamageReceived_1), dDamageResolver_CalculateDamageReceived_1, "DamageReceived_1");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateNegativeArmorRatingDamageReductionPercentage), dCalculateNegativeArmorRatingDamageReductionPercentage, "NegativeArmorRatingReduction");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateCritDamage), dCalculateCritDamage, "CalculateCritDamage");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateArmorPenetrationPercentage), dCalculateArmorPenetrationPercentage, "ArmorPenetration");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateBlockProficiencyPercentage), dCalculateBlockProficiencyPercentage, "BlockProficiency");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateBaseManaGain), dCalculateBaseManaGain, "BaseManaGain");
    UnhookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateBaseSupportManaGain), dCalculateBaseSupportManaGain, "BaseSupportManaGain");

    // UltimatePlayerController
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_OnBattleFightStart), dUltimatePlayerController_OnBattleFightStart, "UltimatePlayerController_OnBattleFightStart");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_DamageReceived), dUltimatePlayerController_add_DamageReceived, "UltimatePlayerController_add_DamageReceived");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_DamageReceived), dUltimatePlayerController_remove_DamageReceived, "UltimatePlayerController_remove_DamageReceived");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_HealReceived), dUltimatePlayerController_add_HealReceived, "UltimatePlayerController_add_HealReceived");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_HealReceived), dUltimatePlayerController_remove_HealReceived, "UltimatePlayerController_remove_HealReceived");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_HealthSet), dUltimatePlayerController_add_HealthSet, "UltimatePlayerController_add_HealthSet");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_HealthSet), dUltimatePlayerController_remove_HealthSet, "UltimatePlayerController_remove_HealthSet");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_PlayerDodged), dUltimatePlayerController_add_PlayerDodged, "UltimatePlayerController_add_PlayerDodged");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_PlayerDodged), dUltimatePlayerController_remove_PlayerDodged, "UltimatePlayerController_remove_PlayerDodged");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_PlayerInvulnerable), dUltimatePlayerController_add_PlayerInvulnerable, "UltimatePlayerController_add_PlayerInvulnerable");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_PlayerInvulnerable), dUltimatePlayerController_remove_PlayerInvulnerable, "UltimatePlayerController_remove_PlayerInvulnerable");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_PlayerBuffAdded), dUltimatePlayerController_add_PlayerBuffAdded, "UltimatePlayerController_add_PlayerBuffAdded");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_PlayerBuffAdded), dUltimatePlayerController_remove_PlayerBuffAdded, "UltimatePlayerController_remove_PlayerBuffAdded");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_PlayerBuffPauseChanged), dUltimatePlayerController_add_PlayerBuffPauseChanged, "UltimatePlayerController_add_PlayerBuffPauseChanged");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_PlayerBuffPauseChanged), dUltimatePlayerController_remove_PlayerBuffPauseChanged, "UltimatePlayerController_remove_PlayerBuffPauseChanged");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_LateBlockDetected), dUltimatePlayerController_add_LateBlockDetected, "UltimatePlayerController_add_LateBlockDetected");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_LateBlockDetected), dUltimatePlayerController_remove_LateBlockDetected, "UltimatePlayerController_remove_LateBlockDetected");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_OnBlockDetected), dUltimatePlayerController_add_OnBlockDetected, "UltimatePlayerController_add_OnBlockDetected");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_OnBlockDetected), dUltimatePlayerController_remove_OnBlockDetected, "UltimatePlayerController_remove_OnBlockDetected");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_OnUnblockDetected), dUltimatePlayerController_add_OnUnblockDetected, "UltimatePlayerController_add_OnUnblockDetected");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_OnUnblockDetected), dUltimatePlayerController_remove_OnUnblockDetected, "UltimatePlayerController_remove_OnUnblockDetected");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_add_OnComboChainReset), dUltimatePlayerController_add_OnComboChainReset, "UltimatePlayerController_add_OnComboChainReset");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_remove_OnComboChainReset), dUltimatePlayerController_remove_OnComboChainReset, "UltimatePlayerController_remove_OnComboChainReset");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_get_ToggleRunTutorialStatMod), dGetToggleRunTutorialStatMod, "UltimatePlayerController_get_ToggleRunTutorialStatMod");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_GetAttackLevelFromSpecial), dGetAttackLevelFromSpecial, "UltimatePlayerController_GetAttackLevelFromSpecial");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_IsBasicAttack), dIsBasicAttack, "UltimatePlayerController_IsBasicAttack");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_GetCustomStagePrefab), dGetCustomStagePrefab, "UltimatePlayerController_GetCustomStagePrefab");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_get_TelemetryBuffVariables), dGetTelemetryBuffVariables, "UltimatePlayerController_get_TelemetryBuffVariables");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_GetCurrentFXTriggerState), dGetCurrentFXTriggerState, "UltimatePlayerController_GetCurrentFXTriggerState");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_RestartFXTriggers), dRestartFXTriggers, "UltimatePlayerController_RestartFXTriggers");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_SuspendAllFXTriggers), dSuspendAllFXTriggers, "UltimatePlayerController_SuspendAllFXTriggers");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_Awake), dAwake, "UltimatePlayerController_Awake");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_ApplyFresnelEffect), dApplyFresnelEffect, "UltimatePlayerController_ApplyFresnelEffect");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_RemoveFresnelEffect), dRemoveFresnelEffect, "UltimatePlayerController_RemoveFresnelEffect");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_AddAndRefreshBoneScalar), dAddAndRefreshBoneScalar, "UltimatePlayerController_AddAndRefreshBoneScalar");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_InitializeBoneScalerBasePose), dInitializeBoneScalerBasePose, "UltimatePlayerController_InitializeBoneScalerBasePose");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_OnDestroy), dOnDestroy, "UltimatePlayerController_OnDestroy");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_AttachToEvents), dAttachToEvents, "UltimatePlayerController_AttachToEvents");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_DetachFromEvents), dDetachFromEvents, "UltimatePlayerController_DetachFromEvents");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_ResetComboTracker), dResetComboTracker, "UltimatePlayerController_ResetComboTracker");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_InitComboMetrics), dInitComboMetrics, "UltimatePlayerController_InitComboMetrics");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_Start), dStart, "UltimatePlayerController_Start");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_Reset), dReset, "UltimatePlayerController_Reset");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_InitPlayer), dInitPlayer, "UltimatePlayerController_InitPlayer");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_InitCharacterScalersID), dInitCharacterScalersID, "UltimatePlayerController_InitCharacterScalersID");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_OnInitPlayer), dOnInitPlayer, "UltimatePlayerController_OnInitPlayer");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_InitAttributes), dInitAttributes, "UltimatePlayerController_InitAttributes");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_RegisterStatMods), dRegisterStatMods, "UltimatePlayerController_RegisterStatMods");
    UnhookFunction(reinterpret_cast<PVOID*>(&UltimatePlayerController_RegisterGameplayStatmods), dRegisterGameplayStatmods, "UltimatePlayerController_RegisterGameplayStatmods");

    // DraftBuffInfoPanel
    UnhookFunction(reinterpret_cast<PVOID*>(&DraftBuffInfoPanel_Set), dSet, "DraftBuffInfoPanel_Set");
    UnhookFunction(reinterpret_cast<PVOID*>(&DraftBuffInfoPanel_SetCenteredView), dSetCenteredView, "DraftBuffInfoPanel_SetCenteredView");
    UnhookFunction(reinterpret_cast<PVOID*>(&DraftBuffInfoPanel_SetSplitView), dSetSplitView, "DraftBuffInfoPanel_SetSplitView");

    if (DetourTransactionCommit() == NO_ERROR) {
        DirectX::Shutdown();
    }
}
