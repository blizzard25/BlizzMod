#include "pch-il2cpp.h"
#include "PlayerAttributesHooks.h"
#include "il2cpp-appdata.h"
#include "pipeline/hooks/HookUtils.h"

#include <iostream>

using namespace app;

namespace Hooks::PlayerAttributes {

    // Force resolution of the DO_APP_FUNC symbol
    volatile auto _force_link_CalculateBaseDamage = PlayerAttributes_CalculateBaseDamage;

    float dCalculateBaseDamage(app::PlayerAttributes* __this,
        app::UltimatePlayerController_AttackLevel__Enum attackLevel,
        MethodInfo* method) {
        float result = PlayerAttributes_CalculateBaseDamage(__this, attackLevel, method);
        std::cout << "[HOOK] CalculateBaseDamage result: " << result << std::endl;
        return result;
    }

    void Install() {
        std::cout << "[INFO] Installing PlayerAttributes hooks..." << std::endl;

        if (!PlayerAttributes_CalculateBaseDamage) {
            std::cout << "[ERROR]: PlayerAttributes_CalculateBaseDamage is null!" << std::endl;
            return;
        }

        if (!HookUtils::HookFunction(reinterpret_cast<PVOID*>(&PlayerAttributes_CalculateBaseDamage),
            dCalculateBaseDamage,
            "CalculateBaseDamage")) {
            std::cout << "[ERROR] Failed to hook CalculateBaseDamage." << std::endl;
        }
    }
}
