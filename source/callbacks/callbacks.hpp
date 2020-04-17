#pragma once

namespace callbacks
{
	typedef int _entity; // actually need pluto _entity class

	typedef std::function<void()> startup_gametype_calltype;
	typedef std::function<void(const chaiscript::Boxed_Value&)> player_connect_calltype;
	typedef std::function<void(const chaiscript::Boxed_Value&)> player_disconnect_calltype;
	typedef std::function<void(const chaiscript::Boxed_Value&, const chaiscript::Boxed_Value&, const chaiscript::Boxed_Value&, int, int, const std::string&, const std::string&, const chaiscript::Boxed_Value&, const std::string&)> player_damage_calltype;
	typedef std::function<void(const chaiscript::Boxed_Value&, const chaiscript::Boxed_Value&, const chaiscript::Boxed_Value&, int, const std::string&, const chaiscript::Boxed_Value&, const chaiscript::Boxed_Value&, const std::string&)> player_killed_calltype;

	extern void add_callback_startup_game(startup_gametype_calltype callback);
	extern void add_callback_player_connect(player_connect_calltype callback);
	extern void add_callback_player_disconnect(player_disconnect_calltype callback);
	extern void add_callback_player_damage(player_damage_calltype callback);
	extern void add_callback_player_killed(player_killed_calltype callback);

	extern void cleanup();
	extern void set_context(chaiscript::ChaiScript* ctx);
	extern void init();
}
