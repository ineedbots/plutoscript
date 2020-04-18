#include "../stdinc.hpp"
#include "script.hpp"

namespace plutoscript
{
	std::string GetMeansOfDeathName(MeansOfDeath mod)
	{
		switch (mod)
		{
			case MOD_UNKNOWN: return "MOD_UNKNOWN";
			case MOD_PISTOL_BULLET: return "MOD_PISTOL_BULLET";
			case MOD_RIFLE_BULLET: return "MOD_RIFLE_BULLET";
			case MOD_EXPLOSIVE_BULLET: return "MOD_EXPLOSIVE_BULLET";
			case MOD_GRENADE: return "MOD_GRENADE";
			case MOD_GRENADE_SPLASH: return "MOD_GRENADE_SPLASH";
			case MOD_PROJECTILE: return "MOD_PROJECTILE";
			case MOD_PROJECTILE_SPLASH: return "MOD_PROJECTILE_SPLASH";
			case MOD_MELEE: return "MOD_MELEE";
			case MOD_HEAD_SHOT: return "MOD_HEAD_SHOT";
			case MOD_CRUSH: return "MOD_CRUSH";
			case MOD_FALLING: return "MOD_FALLING";
			case MOD_SUICIDE: return "MOD_SUICIDE";
			case MOD_TRIGGER_HURT: return "MOD_TRIGGER_HURT";
			case MOD_EXPLOSIVE: return "MOD_EXPLOSIVE";
			case MOD_IMPACT: return "MOD_IMPACT";
			default: return "badMOD";
		}
	}

	std::string GetHitLocationName(HitLocation hitloc)
	{
		switch (hitloc)
		{
			case HITLOC_NONE: return "none";
			case HITLOC_HELMET: return "helmet";
			case HITLOC_HEAD: return "head";
			case HITLOC_NECK: return "neck";
			case HITLOC_TORSO_UPR: return "torso_upper";
			case HITLOC_TORSO_LWR: return "torso_lower";
			case HITLOC_R_ARM_UPR: return "right_arm_upper";
			case HITLOC_L_ARM_UPR: return "left_arm_upper";
			case HITLOC_R_ARM_LWR: return "right_arm_lower";
			case HITLOC_L_ARM_LWR: return "left_arm_lower";
			case HITLOC_R_HAND: return "right_hand";
			case HITLOC_L_HAND: return "left_hand";
			case HITLOC_R_LEG_UPR: return "right_leg_upper";
			case HITLOC_L_LEG_UPR: return "left_leg_upper";
			case HITLOC_R_LEG_LWR: return "right_leg_lower";
			case HITLOC_L_LEG_LWR: return "left_leg_lower";
			case HITLOC_R_FOOT: return "right_foot";
			case HITLOC_L_FOOT: return "left_foot";
			case HITLOC_GUN: return "shield";
			default: return "";
		}
	}

	std::string GetWeaponName(Weapon weapon, int isAlternate)
	{
		char wep_name[1024];
		if (isAlternate)
		{
			wep_name[0] = 'a'; wep_name[1] = 'l'; wep_name[2] = 't'; wep_name[3] = '_';
			return BG_GetWeaponNameComplete(weapon, 0, &wep_name[4], 1020);
		}
		else
		{
			return BG_GetWeaponNameComplete(weapon, 0, wep_name, 1024);
		}
	}
}