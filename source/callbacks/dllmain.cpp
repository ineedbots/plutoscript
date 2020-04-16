#include "stdinc.hpp"
#include "callbacks.hpp"

DLL_EXPORT void on_initialize_context(const char* script, chaiscript::ChaiScript* chai)
{
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

    /*auto m = chaiscript::ModulePtr(new chaiscript::Module());
    
    chaiscript::utility::add_class<callbacks::scr_means_of_death>(*m,
        "MOD",
        {
            { callbacks::MOD_UNKNOWN, "MOD_UNKNOWN" },
            { callbacks::MOD_PISTOL_BULLET, "MOD_PISTOL_BULLET" },
            { callbacks::MOD_RIFLE_BULLET, "MOD_RIFLE_BULLET" },
            { callbacks::MOD_EXPLOSIVE_BULLET, "MOD_EXPLOSIVE_BULLET" },
            { callbacks::MOD_GRENADE, "MOD_GRENADE" },
            { callbacks::MOD_GRENADE_SPLASH, "MOD_GRENADE_SPLASH" },
            { callbacks::MOD_PROJECTILE, "MOD_PROJECTILE" },
            { callbacks::MOD_PROJECTILE_SPLASH, "MOD_PROJECTILE_SPLASH" },
            { callbacks::MOD_MELEE, "MOD_MELEE" },
            { callbacks::MOD_HEAD_SHOT, "MOD_HEAD_SHOT" },
            { callbacks::MOD_CRUSH, "MOD_CRUSH" },
            { callbacks::MOD_FALLING, "MOD_FALLING" },
            { callbacks::MOD_SUICIDE, "MOD_SUICIDE" },
            { callbacks::MOD_TRIGGER_HURT, "MOD_TRIGGER_HURT" },
            { callbacks::MOD_EXPLOSIVE, "MOD_EXPLOSIVE" },
            { callbacks::MOD_IMPACT, "MOD_IMPACT" },
        }
    );

    chai->add(m);*/
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
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}
