#include "stdinc.hpp"

namespace plutoscript
{
	std::string GetMeansOfDeathName(game::MeansOfDeath mod)
	{
		switch (mod)
		{
			case game::MOD_UNKNOWN: return "MOD_UNKNOWN";
			case game::MOD_PISTOL_BULLET: return "MOD_PISTOL_BULLET";
			case game::MOD_RIFLE_BULLET: return "MOD_RIFLE_BULLET";
			case game::MOD_EXPLOSIVE_BULLET: return "MOD_EXPLOSIVE_BULLET";
			case game::MOD_GRENADE: return "MOD_GRENADE";
			case game::MOD_GRENADE_SPLASH: return "MOD_GRENADE_SPLASH";
			case game::MOD_PROJECTILE: return "MOD_PROJECTILE";
			case game::MOD_PROJECTILE_SPLASH: return "MOD_PROJECTILE_SPLASH";
			case game::MOD_MELEE: return "MOD_MELEE";
			case game::MOD_HEAD_SHOT: return "MOD_HEAD_SHOT";
			case game::MOD_CRUSH: return "MOD_CRUSH";
			case game::MOD_FALLING: return "MOD_FALLING";
			case game::MOD_SUICIDE: return "MOD_SUICIDE";
			case game::MOD_TRIGGER_HURT: return "MOD_TRIGGER_HURT";
			case game::MOD_EXPLOSIVE: return "MOD_EXPLOSIVE";
			case game::MOD_IMPACT: return "MOD_IMPACT";
			default: return "badMOD";
		}
	}

	std::string GetHitLocationName(game::HitLocation hitloc)
	{
		switch (hitloc)
		{
			case game::HITLOC_NONE: return "none";
			case game::HITLOC_HELMET: return "helmet";
			case game::HITLOC_HEAD: return "head";
			case game::HITLOC_NECK: return "neck";
			case game::HITLOC_TORSO_UPR: return "torso_upper";
			case game::HITLOC_TORSO_LWR: return "torso_lower";
			case game::HITLOC_R_ARM_UPR: return "right_arm_upper";
			case game::HITLOC_L_ARM_UPR: return "left_arm_upper";
			case game::HITLOC_R_ARM_LWR: return "right_arm_lower";
			case game::HITLOC_L_ARM_LWR: return "left_arm_lower";
			case game::HITLOC_R_HAND: return "right_hand";
			case game::HITLOC_L_HAND: return "left_hand";
			case game::HITLOC_R_LEG_UPR: return "right_leg_upper";
			case game::HITLOC_L_LEG_UPR: return "left_leg_upper";
			case game::HITLOC_R_LEG_LWR: return "right_leg_lower";
			case game::HITLOC_L_LEG_LWR: return "left_leg_lower";
			case game::HITLOC_R_FOOT: return "right_foot";
			case game::HITLOC_L_FOOT: return "left_foot";
			case game::HITLOC_GUN: return "shield";
			default: return "";
		}
	}

	std::string GetWeaponName(game::Weapon weapon, int isAlternate)
	{
		char wep_name[1024];
		if (isAlternate)
		{
			wep_name[0] = 'a'; wep_name[1] = 'l'; wep_name[2] = 't'; wep_name[3] = '_';
			return game::BG_GetWeaponNameComplete(weapon, 0, &wep_name[4], 1020);
		}
		else
		{
			return game::BG_GetWeaponNameComplete(weapon, 0, wep_name, 1024);
		}
	}
}
