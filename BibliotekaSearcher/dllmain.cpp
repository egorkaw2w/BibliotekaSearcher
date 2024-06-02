
#include "pch.h"

#include <iostream>

using namespace std;

extern "C" __declspec(dllexport) bool FindCharacters(const char* inputString, const char* charactersToFind) {
    string str = inputString;
    string chars = charactersToFind;

    for (char c : chars) {
        if (str.find(c) == string::npos) {
            return false;
        }
    }

    return true;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

