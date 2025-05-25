#pragma once

namespace Hooks::PlayerAttributes {
    float dCalculateBaseDamage(app::PlayerAttributes* __this,
        app::UltimatePlayerController_AttackLevel__Enum attackLevel,
        MethodInfo* method);

    void Install();
}
