#include "stdinc.hpp"
#include "callbacks.hpp"
#include "chat.hpp"
#include "commands.hpp"

DLL_EXPORT void on_initialize_context(const char* script, chaiscript::ChaiScript* chai)
{
    callbacks::set_chai(chai);
    callbacks::cleanup();
    chai->add(chaiscript::fun(callbacks::add_callback_startup_game), "add_callback_startup_game");
    chai->add(chaiscript::fun(callbacks::add_callback_player_connect), "add_callback_player_connect");
    chai->add(chaiscript::fun(callbacks::add_callback_player_disconnect), "add_callback_player_disconnect");
    chai->add(chaiscript::fun(callbacks::add_callback_player_damage), "add_callback_player_damage");
    chai->add(chaiscript::fun(callbacks::add_callback_player_killed), "add_callback_player_killed");

    chai->add(chaiscript::user_type<plutoscript::Vec3>(), "Vec3");
    chai->add(chaiscript::constructor<plutoscript::Vec3()>(), "Vec3");
    chai->add(chaiscript::constructor<plutoscript::Vec3(const float[3])>(), "Vec3");
    chai->add(chaiscript::constructor<plutoscript::Vec3(const float, const float, const float)>(), "Vec3");
    chai->add(chaiscript::constructor<plutoscript::Vec3(const plutoscript::Vec3&)>(), "Vec3");
    chai->add(chaiscript::fun(&plutoscript::Vec3::x), "x");
    chai->add(chaiscript::fun(&plutoscript::Vec3::y), "y");
    chai->add(chaiscript::fun(&plutoscript::Vec3::z), "z");
    chai->add(chaiscript::fun(&plutoscript::Vec3::operator std::string), "to_string");

    // chat
    chai->add(chaiscript::fun(chat::raw_say_all), "chat_raw_say_all");
    chai->add(chaiscript::fun([](const std::string& name, const std::string& message)
        { return chat::say_all(name, message); }), "chat_say_all");
    chai->add(chaiscript::fun([](const std::string& message)
        { return chat::say_all(message); }), "chat_say_all");
    chai->add(chaiscript::fun(chat::raw_say_to), "chat_raw_say_to");
    chai->add(chaiscript::fun([](int entnum, const std::string& name, const std::string& message)
        { return chat::say_to(entnum, name, message); }), "chat_say_to");
    chai->add(chaiscript::fun([](int entnum, const std::string& message)
        { return chat::say_to(entnum, message); }), "chat_say_to");

    // cmd
    chai->add(chaiscript::fun(commands::execute_command), "cmd_execute");
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
        callbacks::init();
        chat::init();
        commands::init();
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
