#include "stdinc.hpp"
#include "snipers.hpp"

namespace snipers
{
	Scr_PlayerConnect_t Scr_PlayerConnect_;

	void Scr_PlayerConnect_stub(gentity_s* self)
	{
		Cmd_RegisterNotification(self->state.clientNum, "+frag", "grenade_fly"); // ufo
		Cmd_RegisterNotification(self->state.clientNum, "+actionslot1", "save_pos"); // save pos
		Cmd_RegisterNotification(self->state.clientNum, "+actionslot2", "load_pos"); // load pos
		Cmd_RegisterNotification(self->state.clientNum, "+actionslot4", "stop_fly"); // 

		return Scr_PlayerConnect_(self);
	}

	Scr_PlayerDamage_t Scr_PlayerDamage_;

	void Scr_PlayerDamage_stub(gentity_s* self, gentity_s* inflictor, gentity_s* attacker, int damage, int dflags, MeansOfDeath meansOfDeath, Weapon weapon, bool isAlternate, const float* vPoint, const float* vDir, HitLocation hitLoc, int timeOffset)
	{
		weapClass_t weapclass = BG_GetWeaponClass(weapon, isAlternate);

		if (meansOfDeath != MOD_TRIGGER_HURT && meansOfDeath != MOD_SUICIDE && meansOfDeath != MOD_FALLING)
		{
			if (meansOfDeath == MOD_MELEE || weapclass != WEAPCLASS_SNIPER)
			{
				damage = 0;
			}
			else
			{
				damage = 150;
			}
		}

		return Scr_PlayerDamage_(self, inflictor, attacker, damage, dflags, meansOfDeath, weapon, isAlternate, vPoint, vDir, hitLoc, timeOffset);
	}

	void init()
	{
		Scr_PlayerDamage_ =	util::hook::detour(Scr_PlayerDamage, Scr_PlayerDamage_stub, 10);
	}
}
