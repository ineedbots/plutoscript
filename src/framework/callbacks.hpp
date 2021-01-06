#pragma once
#include "stdinc.hpp"

using startup_gametype_calltype		= std::function<void()>;
using player_connect_calltype		= std::function<void(const chaiscript::Boxed_Value&)>;
using player_disconnect_calltype	= std::function<void(const chaiscript::Boxed_Value&)>;
using player_damage_calltype		= std::function<void(const chaiscript::Boxed_Value&, const chaiscript::Boxed_Value&, const chaiscript::Boxed_Value&, int&, int&, const std::string&, const std::string&, const chaiscript::Boxed_Value&, const chaiscript::Boxed_Value&, const std::string&, int)>;
using player_killed_calltype		= std::function<void(const chaiscript::Boxed_Value&, const chaiscript::Boxed_Value&, const chaiscript::Boxed_Value&, int, const std::string&, const std::string&, const chaiscript::Boxed_Value&, const std::string&, int, int)>;
using player_message_calltype		= std::function<void(const chaiscript::Boxed_Value&, const std::string&, bool&)>;

class callbacks
{
public:
	static void init();
	static void cleanup();
	static void context(chaiscript::ChaiScript* ctx);
	static void add_callback_startup_game(startup_gametype_calltype callback);
	static void add_callback_player_connect(player_connect_calltype callback);
	static void add_callback_player_disconnect(player_disconnect_calltype callback);
	static void add_callback_player_damage(player_damage_calltype callback);
	static void add_callback_player_killed(player_killed_calltype callback);
	static void add_callback_player_message(player_message_calltype callback);

private:
	static chaiscript::ChaiScript* ctx_;

	static utils::hook::detour startup_gametype_hook_;
	static utils::hook::detour player_connect_hook_;
	static utils::hook::detour player_disconnect_hook_;
	static utils::hook::detour player_damage_hook_;
	static utils::hook::detour player_killed_hook_;
	static utils::hook::detour client_command_hook_;
	static utils::hook::detour sv_userbot_hook_;

	static std::vector<startup_gametype_calltype>	startup_gametype_callbacks_;
	static std::vector<player_connect_calltype>	player_connect_callbacks_;
	static std::vector<player_disconnect_calltype>	player_disconnect_callbacks_;
	static std::vector<player_damage_calltype>	player_damage_callbacks_;
	static std::vector<player_killed_calltype>	player_killed_callbacks_;
	static std::vector<player_message_calltype>	player_message_callbacks_;

	static void startup_gametype_stub();
	static void player_connect_stub(game::gentity_s* self);
	static void player_disconnect_stub(game::gentity_s* self);
	static void player_damage_stub(game::gentity_s* self, game::gentity_s* inflictor, game::gentity_s* attacker, int damage, int dflags, game::MeansOfDeath meansOfDeath, game::Weapon weapon, bool isAlternate, const float* vPoint, const float* vDir, game::HitLocation hitLoc, int timeOffset);
	static void player_killed_stub(game::gentity_s* self, game::gentity_s* inflictor, game::gentity_s* attacker, int damage, game::MeansOfDeath meansOfDeath, game::Weapon weapon, bool isAlternate, const float* vDir, game::HitLocation hitLoc, int psTimeOffset, int deathAnimDuration);
	static void client_command_stub(int clientNum);
	static void sv_userbot_stub_();
	static void sv_userbot_stub(game::client_s*);
};
