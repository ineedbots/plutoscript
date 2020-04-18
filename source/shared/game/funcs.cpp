#include "../stdinc.hpp"

namespace game
{
	// Dvars



	// Script
	Scr_LoadLevel_t Scr_LoadLevel = Scr_LoadLevel_t(0x517410);
	Scr_LoadGameType_t Scr_LoadGameType = Scr_LoadGameType_t(0x527AF0);
	Scr_StartupGameType_t Scr_StartupGameType = Scr_StartupGameType_t(0x527B10);
	Scr_PlayerConnect_t Scr_PlayerConnect = Scr_PlayerConnect_t(0x527B30);
	Scr_PlayerDisconnect_t Scr_PlayerDisconnect = Scr_PlayerDisconnect_t(0x527B60);
	Scr_PlayerDamage_t Scr_PlayerDamage = Scr_PlayerDamage_t(0x527B90);
	Scr_PlayerKilled_t Scr_PlayerKilled = Scr_PlayerKilled_t(0x527CF0);
	Scr_GetEntityId_t Scr_GetEntityId = Scr_GetEntityId_t(0x567D80);

	// Weapon
	BG_GetWeaponNameComplete_t  BG_GetWeaponNameComplete = BG_GetWeaponNameComplete_t(0x42F760);
	BG_GetWeaponClass_t BG_GetWeaponClass = BG_GetWeaponClass_t(0x436ED0);
	BG_GetWeaponClassName_t BG_GetWeaponClassName = BG_GetWeaponClassName_t(0x42F160);
}
