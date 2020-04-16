#include "stdinc.hpp"
#include "callbacks.hpp"

namespace callbacks
{
	std::map<int, std::string> mod_names;
	std::map<int, std::string> hitloc_names;

	std::vector<startup_gametype_calltype>	startup_game_callbacks;
	std::vector<player_connect_calltype>	player_connect_callbacks;
	std::vector<player_disconnect_calltype>	player_disconnect_callbacks;
	std::vector<player_damage_calltype>		player_damage_callbacks;
	std::vector<player_killed_calltype>		player_killed_callbacks;

	void add_callback_startup_game(startup_gametype_calltype callback)
	{
		startup_game_callbacks.push_back(callback);
	}

	void add_callback_player_connect(player_connect_calltype callback)
	{
		player_connect_callbacks.push_back(callback);
	}

	void add_callback_player_disconnect(player_disconnect_calltype callback)
	{
		player_disconnect_callbacks.push_back(callback);
	}

	void add_callback_player_damage(player_damage_calltype callback)
	{
		player_damage_callbacks.push_back(callback);
	}

	void add_callback_player_killed(player_killed_calltype callback)
	{
		player_killed_callbacks.push_back(callback);
	}

	void cleanup()
	{
		startup_game_callbacks.clear();
		player_connect_callbacks.clear();
		player_disconnect_callbacks.clear();
		player_damage_callbacks.clear();
		player_killed_callbacks.clear();
	}

	game::Scr_StartupGameType_t Scr_StartupGameType_;

	void Scr_StartupGameType()
	{
		DEBUG_LOG("[plutoscript]: Scr_StartupGameType\n");

		for (auto& callback : startup_game_callbacks)
		{
			callback();
		}

		return Scr_StartupGameType_();
	}

	game::Scr_PlayerConnect_t Scr_PlayerConnect_;

	void Scr_PlayerConnect(game::entity* self)
	{
		DEBUG_LOG("[plutoscript]: Scr_PlayerConnect\n");

		for (auto& callback : player_connect_callbacks)
		{
			callback(self->state.number);
		}

		return Scr_PlayerConnect_(self);
	}

	game::Scr_PlayerDisconnect_t Scr_PlayerDisconnect_;

	void Scr_PlayerDisconnect(game::entity* self)
	{
		DEBUG_LOG("[plutoscript]: Scr_PlayerDisconnect\n");

		for (auto& callback : player_disconnect_callbacks)
		{
			_entity self_ = self->state.number;

			callback(self_);
		}

		return Scr_PlayerDisconnect_(self);
	}

	game::Scr_PlayerDamage_t Scr_PlayerDamage_;

	void Scr_PlayerDamage(game::entity* self, game::entity* inflictor, game::entity* attacker, int damage, int dflags, int meansOfDeath, int weapon, bool isAlternate, const float* vPoint, const float* vDir, game::hit_location hitLoc, int timeOffset)
	{
		DEBUG_LOG("[plutoscript]: Scr_PlayerDamage\n");

		std::string mod = meansOfDeath < 15 ? mod_names[meansOfDeath] : "badMOD";
		char wep_name[1024];
		if (isAlternate)
		{
			wep_name[0] = 'a'; wep_name[1] = 'l'; wep_name[2] = 't'; wep_name[3] = '_';
			game::BG_GetWeaponNameComplete(weapon, 0, &wep_name[4], 1020);
		}
		else
		{
			game::BG_GetWeaponNameComplete(weapon, 0, wep_name, 1024);
		}
		std::string weapon_ = wep_name;

		plutoscript::Vec3 point_(vPoint[0], vPoint[1], vPoint[2]);
		plutoscript::Vec3 dir_(vDir[0], vDir[1], vDir[2]);
		std::string hitloc_ = hitloc_names[hitLoc];

		for (auto& callback : player_damage_callbacks)
		{
			callback(0, 0, 0, damage, dflags, mod, weapon_, point_, dir_, hitloc_);
		}

		return Scr_PlayerDamage_(self, inflictor, attacker, damage, dflags, meansOfDeath, weapon, isAlternate, vPoint, vDir, hitLoc, timeOffset);
	}

	game::Scr_PlayerKilled_t Scr_PlayerKilled_;

	void Scr_PlayerKilled(game::entity* self, game::entity* inflictor, game::entity* attacker, int damage, int meansOfDeath, int weapon, bool isAlternate, const float* vDir, game::hit_location hitLoc, int psTimeOffset, int deathAnimDuration)
	{
		DEBUG_LOG("[plutoscript]: Scr_PlayerKilled\n");

		std::string mod = meansOfDeath < 15 ? mod_names[meansOfDeath] : "badMOD";
		char wep_name[1024];
		if (isAlternate)
		{
			wep_name[0] = 'a'; wep_name[1] = 'l'; wep_name[2] = 't'; wep_name[3] = '_';
			game::BG_GetWeaponNameComplete(weapon, 0, &wep_name[4], 1020);
		}
		else
		{
			game::BG_GetWeaponNameComplete(weapon, 0, wep_name, 1024);
		}
		std::string weapon_ = wep_name;

		plutoscript::Vec3 dir_(vDir[0], vDir[1], vDir[2]);

		std::string hitloc_ = hitloc_names[hitLoc];

		for (auto& callback : player_killed_callbacks)
		{
			callback(0, 0, 0, damage, mod, weapon_, dir_, hitloc_);
		}

		return Scr_PlayerKilled_(self, inflictor, attacker, damage, meansOfDeath, weapon, isAlternate, vDir, hitLoc, psTimeOffset, deathAnimDuration);
	}

	void init()
	{
		Scr_StartupGameType_ =	util::hook::detour(0x527B10, Scr_StartupGameType, 5);
		Scr_PlayerConnect_ =	util::hook::detour(0x527B30, Scr_PlayerConnect, 5);
		Scr_PlayerDisconnect_ = util::hook::detour(0x527B60, Scr_PlayerDisconnect, 5);
		Scr_PlayerDamage_ =		util::hook::detour(0x527B90, Scr_PlayerDamage, 10);
		Scr_PlayerKilled_ =		util::hook::detour(0x527CF0, Scr_PlayerKilled, 10);

		mod_names[plutoscript::MOD_UNKNOWN] = "MOD_UNKNOWN";
		mod_names[plutoscript::MOD_PISTOL_BULLET] = "MOD_PISTOL_BULLET";
		mod_names[plutoscript::MOD_RIFLE_BULLET] = "MOD_RIFLE_BULLET";
		mod_names[plutoscript::MOD_EXPLOSIVE_BULLET] = "MOD_EXPLOSIVE_BULLET";
		mod_names[plutoscript::MOD_GRENADE] = "MOD_GRENADE";
		mod_names[plutoscript::MOD_GRENADE_SPLASH] = "MOD_GRENADE_SPLASH";
		mod_names[plutoscript::MOD_PROJECTILE] = "MOD_PROJECTILE";
		mod_names[plutoscript::MOD_PROJECTILE_SPLASH] = "MOD_PROJECTILE_SPLASH";
		mod_names[plutoscript::MOD_MELEE] = "MOD_MELEE";
		mod_names[plutoscript::MOD_HEAD_SHOT] = "MOD_HEAD_SHOT";
		mod_names[plutoscript::MOD_CRUSH] = "MOD_CRUSH";
		mod_names[plutoscript::MOD_FALLING] = "MOD_FALLING";
		mod_names[plutoscript::MOD_SUICIDE] = "MOD_SUICIDE";
		mod_names[plutoscript::MOD_TRIGGER_HURT] = "MOD_TRIGGER_HURT";
		mod_names[plutoscript::MOD_EXPLOSIVE] = "MOD_EXPLOSIVE";
		mod_names[plutoscript::MOD_IMPACT] = "MOD_IMPACT";

		hitloc_names[plutoscript::HITLOC_NONE] = "HITLOC_NONE";
		hitloc_names[plutoscript::HITLOC_HELMET] = "HITLOC_HELMET";
		hitloc_names[plutoscript::HITLOC_HEAD] = "HITLOC_HEAD";
		hitloc_names[plutoscript::HITLOC_NECK] = "HITLOC_NECK";
		hitloc_names[plutoscript::HITLOC_TORSO_UPR] = "HITLOC_TORSO_UPR";
		hitloc_names[plutoscript::HITLOC_TORSO_LWR] = "HITLOC_TORSO_LWR";
		hitloc_names[plutoscript::HITLOC_R_ARM_UPR] = "HITLOC_R_ARM_UPR";
		hitloc_names[plutoscript::HITLOC_L_ARM_UPR] = "HITLOC_L_ARM_UPR";
		hitloc_names[plutoscript::HITLOC_R_ARM_LWR] = "HITLOC_R_ARM_LWR";
		hitloc_names[plutoscript::HITLOC_L_ARM_LWR] = "HITLOC_L_ARM_LWR";
		hitloc_names[plutoscript::HITLOC_R_HAND] = "HITLOC_R_HAND";
		hitloc_names[plutoscript::HITLOC_L_HAND] = "HITLOC_L_HAND";
		hitloc_names[plutoscript::HITLOC_R_LEG_UPR] = "HITLOC_R_LEG_UPR";
		hitloc_names[plutoscript::HITLOC_L_LEG_UPR] = "HITLOC_L_LEG_UPR";
		hitloc_names[plutoscript::HITLOC_R_LEG_LWR] = "HITLOC_R_LEG_LWR";
		hitloc_names[plutoscript::HITLOC_L_LEG_LWR] = "HITLOC_L_LEG_LWR";
		hitloc_names[plutoscript::HITLOC_R_FOOT] = "HITLOC_R_FOOT";
		hitloc_names[plutoscript::HITLOC_L_FOOT] = "HITLOC_L_FOOT";
		hitloc_names[plutoscript::HITLOC_GUN] = "HITLOC_GUN";
		hitloc_names[plutoscript::HITLOC_NUM] = "HITLOC_NUM";
	}
}
