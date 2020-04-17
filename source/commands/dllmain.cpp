#include "stdinc.hpp"
#include "commands.hpp"

DLL_EXPORT void on_initialize_context(const char* script, chaiscript::ChaiScript* chai)
{

}

DLL_EXPORT void on_script_loaded(const char* script, chaiscript::ChaiScript* chai)
{

}

DLL_EXPORT void on_script_unloaded(const char* script, chaiscript::ChaiScript* chai)
{

}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
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
