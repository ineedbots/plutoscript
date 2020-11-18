#include "stdinc.hpp"
#include "framework/callbacks.hpp"
#include "framework/chat.hpp"
#include "framework/commands.hpp"

void init()
{
    callbacks::init();
}

void exit()
{

}

DLL_EXPORT void on_initialize_context(const char* script, chaiscript::ChaiScript* chai)
{
    callbacks::cleanup();
    callbacks::context(chai);

    chai->add(chaiscript::fun(callbacks::add_callback_startup_game), "add_callback_startup_game");
    chai->add(chaiscript::fun(callbacks::add_callback_player_connect), "add_callback_player_connect");
    chai->add(chaiscript::fun(callbacks::add_callback_player_disconnect), "add_callback_player_disconnect");
    chai->add(chaiscript::fun(callbacks::add_callback_player_damage), "add_callback_player_damage");
    chai->add(chaiscript::fun(callbacks::add_callback_player_killed), "add_callback_player_killed");
    chai->add(chaiscript::fun(callbacks::add_callback_player_message), "add_callback_player_message");

    chai->add(chaiscript::user_type<plutoscript::Vec3>(), "Vec3");
    chai->add(chaiscript::constructor<plutoscript::Vec3()>(), "Vec3");
    chai->add(chaiscript::constructor<plutoscript::Vec3(const float[3])>(), "Vec3");
    chai->add(chaiscript::constructor<plutoscript::Vec3(const float, const float, const float)>(), "Vec3");
    chai->add(chaiscript::constructor<plutoscript::Vec3(const plutoscript::Vec3&)>(), "Vec3");
    chai->add(chaiscript::fun(&plutoscript::Vec3::x), "x");
    chai->add(chaiscript::fun(&plutoscript::Vec3::y), "y");
    chai->add(chaiscript::fun(&plutoscript::Vec3::z), "z");
    chai->add(chaiscript::fun(&plutoscript::Vec3::operator std::string), "to_string");

    chai->eval("def _entity::tell(message) { if (gsc.isPlayer(this) == 1) { chat_say_to(this.getEntityNumber(), message) } }");
    chai->eval("def _entity::tellraw(message) { if (gsc.isPlayer(this) == 1) { chat_raw_say_to(this.getEntityNumber(), message) } }");

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

DLL_EXPORT void on_script_loaded(const char* script, chaiscript::ChaiScript* chai) { }

DLL_EXPORT void on_script_unloaded(const char* script, chaiscript::ChaiScript* chai) { }

BOOL APIENTRY DllMain(HMODULE hModule, DWORD  ul_reason_for_call, LPVOID lpReserved)
{
    if (ul_reason_for_call == DLL_PROCESS_ATTACH)
    {
        init();
    }
    else if (ul_reason_for_call == DLL_PROCESS_DETACH)
    {
        exit();
    }

    return TRUE;
}
