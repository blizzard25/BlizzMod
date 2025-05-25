#include "pch-il2cpp.h"
#include "HookUtils.h"
#include <iostream>
#include "detours/detours.h"

namespace HookUtils {
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
}
