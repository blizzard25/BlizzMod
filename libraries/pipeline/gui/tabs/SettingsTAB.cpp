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
        ImGui::Text("Il2CppInspectorPro by Jadis0x");
        ImGui::Text("Discord: Jadis0x");
        ImGui::Text("Github: Jadis0x");
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

        if (ImGui::Button("Donate"))
        {
            app::Application_OpenURL(reinterpret_cast<app::String*>(il2cpp_string_new("https://www.buymeacoffee.com/jadis0x")), nullptr);
        }

        ImGui::EndTabItem();
    }
}
