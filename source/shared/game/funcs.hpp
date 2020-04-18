#pragma once

namespace game
{
	typedef void(__cdecl* Scr_LoadLevel_t)();
	extern Scr_LoadLevel_t Scr_LoadLevel;
	typedef void(__cdecl* Scr_LoadGameType_t)();
	extern Scr_LoadGameType_t Scr_LoadGameType;
	typedef void(__cdecl* Scr_StartupGameType_t)();
	extern Scr_StartupGameType_t Scr_StartupGameType;
	typedef void(__cdecl* Scr_PlayerConnect_t)(gentity_s*);
	extern Scr_PlayerConnect_t Scr_PlayerConnect;
	typedef void(__cdecl* Scr_PlayerDisconnect_t)(gentity_s*);
	extern Scr_PlayerDisconnect_t Scr_PlayerDisconnect;
	typedef void(__cdecl* Scr_PlayerDamage_t)(gentity_s*, gentity_s*, gentity_s*, int, int, MeansOfDeath, Weapon, bool, const float*, HitLocation, int);
	extern Scr_PlayerDamage_t Scr_PlayerDamage;
	typedef void(__cdecl* Scr_PlayerKilled_t)(gentity_s*, gentity_s*, gentity_s*, int, MeansOfDeath, Weapon, bool, const float*, HitLocation, int, int);
	extern Scr_PlayerKilled_t Scr_PlayerKilled;

	typedef char* (__cdecl* BG_GetWeaponNameComplete_t)(Weapon weapon, bool isAlternate, char* output, unsigned int maxStringLen);
	extern BG_GetWeaponNameComplete_t BG_GetWeaponNameComplete;
	typedef weapClass_t(__cdecl* BG_GetWeaponClass_t)(Weapon weapon, bool isAlternate);
	extern BG_GetWeaponClass_t BG_GetWeaponClass;
	typedef const char* (__cdecl* BG_GetWeaponClassName_t)(int type);
	extern BG_GetWeaponClassName_t BG_GetWeaponClassName;


	typedef unsigned int(__cdecl* Scr_GetEntityId_t)(int, unsigned int);
	extern Scr_GetEntityId_t Scr_GetEntityId;
}
