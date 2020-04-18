#include "stdinc.hpp"
#include "callbacks.hpp"

namespace callbacks
{
	chaiscript::ChaiScript* chai;

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

	Scr_StartupGameType_t Scr_StartupGameType_;

	void Scr_StartupGameType_stub()
	{
		for (auto& callback : startup_game_callbacks)
		{
			callback();
		}

		return Scr_StartupGameType_();
	}

	Scr_PlayerConnect_t Scr_PlayerConnect_;

	void Scr_PlayerConnect_stub(gentity_s* self)
	{
		chaiscript::Boxed_Value self_ = chai->eval("level.getEntByNum(" + std::to_string(self->state.number) + ")");

		for (auto& callback : player_connect_callbacks)
		{
			callback(self_);
		}

		return Scr_PlayerConnect_(self);
	}

	Scr_PlayerDisconnect_t Scr_PlayerDisconnect_;

	void Scr_PlayerDisconnect_stub(gentity_s* self)
	{
		chaiscript::Boxed_Value self_ = chai->eval("level.getEntByNum(" + std::to_string(self->state.number) + ")");

		for (auto& callback : player_disconnect_callbacks)
		{
			callback(self_);
		}

		return Scr_PlayerDisconnect_(self);
	}

	Scr_PlayerDamage_t Scr_PlayerDamage_;

	void Scr_PlayerDamage_stub(gentity_s* self, gentity_s* inflictor, gentity_s* attacker, int damage,  int dflags, MeansOfDeath meansOfDeath, Weapon weapon, bool isAlternate, const float* vDir, HitLocation hitLoc, int timeOffset)
	{
		chaiscript::Boxed_Value self_ = chaiscript::var(self->state.number);
		chaiscript::Boxed_Value inflictor_ = inflictor != 0 ? chai->eval("level.getEntByNum(" + std::to_string(inflictor->state.number) + ")") : chaiscript::Boxed_Value{};
		chaiscript::Boxed_Value attacker_ = attacker != 0 ? chai->eval("level.getEntByNum(" + std::to_string(attacker->state.number) + ")") : chaiscript::Boxed_Value{};
		
		std::string mod_ = plutoscript::GetMeansOfDeathName(meansOfDeath);
		std::string weapon_ = plutoscript::GetWeaponName(weapon, isAlternate);

		chaiscript::Boxed_Value dir_;
		std::vector<chaiscript::Boxed_Value> values;
		if (vDir)
		{
			values.push_back(chaiscript::var(vDir[0]));
			values.push_back(chaiscript::var(vDir[1]));
			values.push_back(chaiscript::var(vDir[2]));
			dir_ = chaiscript::var(values);
		}
		else
		{
			dir_ = chaiscript::Boxed_Value{};
		}

		std::string hitloc_ = plutoscript::GetHitLocationName(hitLoc);

		for (auto& callback : player_damage_callbacks)
		{
			callback(self_, inflictor_, attacker_, damage, dflags, mod_, weapon_, dir_, hitloc_);
		}

		if (damage == 0) return;

		return Scr_PlayerDamage_(self, inflictor, attacker, damage, dflags, meansOfDeath, weapon, isAlternate, vDir, hitLoc, timeOffset);
	}

	Scr_PlayerKilled_t Scr_PlayerKilled_;

	void Scr_PlayerKilled_stub(gentity_s* self, gentity_s* inflictor, gentity_s* attacker, int damage, MeansOfDeath meansOfDeath, Weapon weapon, bool isAlternate, const float* vDir, HitLocation hitLoc, int psTimeOffset, int deathAnimDuration)
	{
		chaiscript::Boxed_Value self_ = self != 0 ? chai->eval("level.getEntByNum(" + std::to_string(self->state.number) + ")") : chaiscript::Boxed_Value{};
		chaiscript::Boxed_Value inflictor_ = inflictor != 0 ? chai->eval("level.getEntByNum(" + std::to_string(inflictor->state.number) + ")") : chaiscript::Boxed_Value{};
		chaiscript::Boxed_Value attacker_ = attacker != 0 ? chai->eval("level.getEntByNum(" + std::to_string(attacker->state.number) + ")") : chaiscript::Boxed_Value{};
		std::string mod_ = plutoscript::GetMeansOfDeathName(meansOfDeath);
		std::string weapon_ = plutoscript::GetWeaponName(weapon, isAlternate);

		chaiscript::Boxed_Value dir_;
		std::vector<chaiscript::Boxed_Value> values;
		if (vDir)
		{
			values.push_back(chaiscript::var(vDir[0]));
			values.push_back(chaiscript::var(vDir[1]));
			values.push_back(chaiscript::var(vDir[2]));
			dir_ = chaiscript::var(values);
		}
		else
		{
			dir_ = chaiscript::Boxed_Value{};
		}

		std::string hitloc_ = plutoscript::GetHitLocationName(hitLoc);

		for (auto& callback : player_killed_callbacks)
		{
			callback(self_, inflictor_, attacker_, damage, mod_, weapon_, dir_, hitloc_);
		}
		
		return Scr_PlayerKilled_(self, inflictor, attacker, damage, meansOfDeath, weapon, isAlternate, vDir, hitLoc, psTimeOffset, deathAnimDuration);
	}

	void set_chai(chaiscript::ChaiScript* c)
	{
		chai = c;
	}

	void cleanup()
	{
		startup_game_callbacks.clear();
		player_connect_callbacks.clear();
		player_disconnect_callbacks.clear();
		player_damage_callbacks.clear();
		player_killed_callbacks.clear();
	}

	void init()
	{
		Scr_StartupGameType_ =	util::hook::detour(Scr_StartupGameType, Scr_StartupGameType_stub, 5);
		Scr_PlayerConnect_ =	util::hook::detour(Scr_PlayerConnect, Scr_PlayerConnect_stub, 5);
		Scr_PlayerDisconnect_ = util::hook::detour(Scr_PlayerDisconnect, Scr_PlayerDisconnect_stub, 5);
		Scr_PlayerDamage_ =		util::hook::detour(Scr_PlayerDamage, Scr_PlayerDamage_stub, 10);
		Scr_PlayerKilled_ =		util::hook::detour(Scr_PlayerKilled, Scr_PlayerKilled_stub, 10);
	}
}
