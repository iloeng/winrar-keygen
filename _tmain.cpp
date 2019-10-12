#ifdef _WIN32
#include <tchar.h>
#include <windows.h>
#ifdef __GNUC__
#define MINGW_HAS_SECURE_API
#include <sec_api/stdio_s.h>
#define _tprintf_s printf_s
#endif
#define HS "hs"
#else
#define PTSTR char*
#define _putts puts
#define _tprintf_s printf
#define TEXT(s) s
#define HS "s"
#endif
#include <stdio.h>
#include <locale.h>
#include "WinRarConfig.hpp"
#include "WinRarKeygen.hpp"
#include <system_error>

void Help() {
    _putts(TEXT("Usage:"));
    _putts(TEXT("        winrar-keygen.exe <your name> <license type>"));
    _putts(TEXT(""));
    _putts(TEXT("Example:"));
    _putts(TEXT(""));
    _putts(TEXT("        winrar-keygen.exe \"Rebecca Morrison\" \"Single PC usage license\""));
    _putts(TEXT("  or:"));
    _putts(TEXT("        winrar-keygen.exe \"Rebecca Morrison\" \"Single PC usage license\" > rarreg.key\n"));
}

void PrintRegisterInfo(const WinRarKeygen<WinRarConfig>::RegisterInfo& Info) {
    _tprintf_s(TEXT("%" HS "\n"), "RAR registration data");
    _tprintf_s(TEXT("%" HS "\n"), Info.UserName.c_str());
    _tprintf_s(TEXT("%" HS "\n"), Info.LicenseType.c_str());
    _tprintf_s(TEXT("UID=%" HS "\n"), Info.UID.c_str());
    for (size_t i = 0; i < Info.HexData.length(); i += 54) {
        _tprintf_s(TEXT("%.54" HS "\n"), Info.HexData.c_str() + i);
    }
}

#ifdef _WIN32
std::string ToACP(PCWSTR lpszUnicodeString) {
    int len;

    len = WideCharToMultiByte(CP_ACP, 0, lpszUnicodeString, -1, NULL, 0, NULL, NULL);
    if (len == 0) {
        auto err = GetLastError();
        throw std::system_error(err, std::system_category());
    }

    std::string Result(len, '\x00');

    len = WideCharToMultiByte(CP_ACP, 0, lpszUnicodeString, -1, Result.data(), static_cast<int>(Result.length()), NULL, NULL);
    if (len == 0) {
        auto err = GetLastError();
        throw std::system_error(err, std::system_category());
    }

    while (Result.back() == '\x00') {
        Result.pop_back();
    }

    return Result;
}
#endif

#ifdef WIN32
int _tmain(int argc, PTSTR argv[]) {
#else
int main(int argc, PTSTR argv[]) {
#endif
    setlocale(LC_ALL, "");
    if (argc == 3) {
        try {
            PrintRegisterInfo(
#if defined(_UNICODE) || defined(UNICODE)
                WinRarKeygen<WinRarConfig>::GenerateRegisterInfo(ToACP(argv[1]).c_str(), ToACP(argv[2]).c_str())
#else
                WinRarKeygen<WinRarConfig>::GenerateRegisterInfo(argv[1], argv[2])
#endif
            );
        } catch (std::exception& e) {
            _tprintf_s(TEXT("%" HS "\n"), e.what());
            return -1;
        }
    } else {
        Help();
    }
    return 0;
}

