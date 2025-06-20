#include "pch-il2cpp.h"

#include "version.h"
#include <thread>
#include <chrono>
#include "main.h"
#include <filesystem>

HMODULE version_dll;

#define WRAPPER_GENFUNC(name) \
    FARPROC o##name; \
    void _##name() \
    { \
        if (o##name) \
            ((void(*)())o##name)(); \
    }

WRAPPER_GENFUNC(GetFileVersionInfoA)
WRAPPER_GENFUNC(GetFileVersionInfoByHandle)
WRAPPER_GENFUNC(GetFileVersionInfoExW)
WRAPPER_GENFUNC(GetFileVersionInfoExA)
WRAPPER_GENFUNC(GetFileVersionInfoSizeA)
WRAPPER_GENFUNC(GetFileVersionInfoSizeExA)
WRAPPER_GENFUNC(GetFileVersionInfoSizeExW)
WRAPPER_GENFUNC(GetFileVersionInfoSizeW)
WRAPPER_GENFUNC(GetFileVersionInfoW)
WRAPPER_GENFUNC(VerFindFileA)
WRAPPER_GENFUNC(VerFindFileW)
WRAPPER_GENFUNC(VerInstallFileA)
WRAPPER_GENFUNC(VerInstallFileW)
WRAPPER_GENFUNC(VerLanguageNameA)
WRAPPER_GENFUNC(VerLanguageNameW)
WRAPPER_GENFUNC(VerQueryValueA)
WRAPPER_GENFUNC(VerQueryValueW)

#define WRAPPER_FUNC(name) o##name = GetProcAddress(version_dll, ###name);

void load_version() {
 char systemPath[MAX_PATH];
 GetSystemDirectoryA(systemPath, MAX_PATH);
 strcat_s(systemPath, "\\version.dll");
 version_dll = LoadLibraryA(systemPath);

 if (!version_dll) {
  std::string message = "Unable to load " + std::string(systemPath);
  MessageBoxA(NULL, message.c_str(), "Title", MB_OK | MB_ICONERROR | MB_SYSTEMMODAL);
 }

 if (!version_dll) return;

 WRAPPER_FUNC(GetFileVersionInfoA);
 WRAPPER_FUNC(GetFileVersionInfoByHandle);
 WRAPPER_FUNC(GetFileVersionInfoExW);
 WRAPPER_FUNC(GetFileVersionInfoExA);
 WRAPPER_FUNC(GetFileVersionInfoSizeA);
 WRAPPER_FUNC(GetFileVersionInfoSizeExW);
 WRAPPER_FUNC(GetFileVersionInfoSizeExA);
 WRAPPER_FUNC(GetFileVersionInfoSizeW);
 WRAPPER_FUNC(GetFileVersionInfoW);
 WRAPPER_FUNC(VerFindFileA);
 WRAPPER_FUNC(VerFindFileW);
 WRAPPER_FUNC(VerInstallFileA);
 WRAPPER_FUNC(VerInstallFileW);
 WRAPPER_FUNC(VerLanguageNameA);
 WRAPPER_FUNC(VerLanguageNameW);
 WRAPPER_FUNC(VerQueryValueA);
 WRAPPER_FUNC(VerQueryValueW);
}

std::filesystem::path getApplicationPath() {
 TCHAR buff[MAX_PATH];
 GetModuleFileName(NULL, buff, MAX_PATH);
 return std::filesystem::path(buff);
}

DWORD WINAPI Load(LPVOID lpParam) {
 auto applicationPath = getApplicationPath();

 load_version();
 if (!version_dll)
  return 0;

 std::this_thread::sleep_for(std::chrono::seconds(5));
 Run(lpParam);

 return 0;
}
