#include "pch-il2cpp.h"
#include "pipeline/gui/tabs/SettingsTAB.h"
#include <imgui/imgui.h>
#include "pipeline/gui/GUITheme.h" 
#include "pipeline/settings.h"
#include "main.h"
#include <iostream>

void SettingsTAB::Render()
{
    if (ImGui::BeginTabItem("Settings")) {

        ImGui::Spacing();

        ImGui::TextColored(ImVec4(1.0f, 1.0f, 0.0f, 1.0f), "Version: 1.0.0");
        ImGui::Spacing();

        ImGui::PushTextWrapPos(ImGui::GetCursorPos().x + 550.0f);
        ImGui::Text("BlizzMod Menu");
        ImGui::Text("Discord: Blizzard25");
        ImGui::Text("Github: Blizzard25");
        ImGui::PopTextWrapPos();
        ImGui::Spacing();
        ImGui::Separator();
        ImGui::Spacing();

        ImGui::Checkbox("Show Unity Logs", &settings.bEnableUnityLogs); // Test checkbox
        ImGui::Spacing();

        if (ImGui::Button("Unhook"))
        {
            SetEvent(hUnloadEvent);
        }

        if (ImGui::Button("Repository"))
        {
            app::Application_OpenURL(reinterpret_cast<app::String*>(il2cpp_string_new("https://github.com/blizzard25/BlizzMod")), nullptr);
        }

        ImGui::EndTabItem();
    }
}
