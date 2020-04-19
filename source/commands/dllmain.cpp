#include "stdinc.hpp"
#include "commands.hpp"

DLL_EXPORT void on_initialize_context(const char* script, chaiscript::ChaiScript* chai)
{
    chai->add(chaiscript::fun(commands::execute_command), "execute_command");
    chai->add(chaiscript::fun(commands::raw_say_all), "raw_say_all");
    chai->add(chaiscript::fun([](const std::string& name, const std::string& message)
        { return commands::say_all(name, message); }), "say_all");
    chai->add(chaiscript::fun([](const std::string& message)
        { return commands::say_all(message); }), "say_all");
    chai->add(chaiscript::fun(commands::raw_say_to), "raw_say_to");
    chai->add(chaiscript::fun([](int entnum, const std::string& name, const std::string& message)
        { return commands::say_to(entnum, name, message); }), "say_to");
    chai->add(chaiscript::fun([](int entnum, const std::string& message)
        { return commands::say_to(entnum, message); }), "say_to");

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
        commands::init();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
