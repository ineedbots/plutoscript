#pragma once

namespace game
{
	typedef void(__cdecl* Scr_LoadGameType_t)();
	typedef void(__cdecl* Scr_StartupGameType_t)();
	typedef void(__cdecl* Scr_PlayerConnect_t)(entity*);
	typedef void(__cdecl* Scr_PlayerDisconnect_t)(entity*);
	typedef void(__cdecl* Scr_PlayerDamage_t)(entity*, entity*, entity*, int, int, int, int, bool, const float*, hit_location, int);
	typedef void(__cdecl* Scr_PlayerKilled_t)(entity*, entity*, entity*, int, int, int, bool, const float*, hit_location, int, int);

	typedef char* (__cdecl* BG_GetWeaponNameComplete_t)(int weapon, bool isAlternate, char* output, unsigned int maxStringLen);
	extern BG_GetWeaponNameComplete_t BG_GetWeaponNameComplete;

	typedef int(__cdecl* BG_GetWeaponClass_t)(unsigned int weapon, bool isAlternate);
	extern BG_GetWeaponClass_t BG_GetWeaponClass;

	typedef unsigned int(__cdecl* Scr_GetEntityId_t)(int, unsigned int);
	extern Scr_GetEntityId_t Scr_GetEntityId;
}
