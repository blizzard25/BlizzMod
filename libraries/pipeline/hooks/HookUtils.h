#pragma once

#include <Windows.h>

namespace HookUtils {
    bool HookFunction(PVOID* ppPointer, PVOID pDetour, const char* functionName);
    bool UnhookFunction(PVOID* ppPointer, PVOID pDetour, const char* functionName);
}
