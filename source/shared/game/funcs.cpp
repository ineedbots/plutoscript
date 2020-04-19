#include "../stdinc.hpp"

namespace game
{
	// Dvars

	// Cbuf
	Cbuf_AddText_t Cbuf_AddText = Cbuf_AddText_t(0x545680);

	// Cmd
	Cmd_RegisterNotification_t Cmd_RegisterNotification = Cmd_RegisterNotification_t(0x5461C0);

	// Server
	SV_GameSendServerCommand_t SV_GameSendServerCommand = SV_GameSendServerCommand_t(0x573220);

	// Script
	Scr_AddInt_t Scr_AddInt = Scr_AddInt_t(0x56AA20);
	Scr_AddConstString_t Scr_AddConstString = Scr_AddConstString_t(0x56ACC0);
	Scr_AddVector_t Scr_AddVector = Scr_AddVector_t(0x56AD20);
	Scr_AddUndefined_t Scr_AddUndefined = Scr_AddUndefined_t(0x56AB10);
	Scr_AddString_t Scr_AddString = Scr_AddString_t(0x56AC00);
	Scr_AddEntity_t Scr_AddEntity = Scr_AddEntity_t(0x52B060);
	Scr_ExecEntThread_t Scr_ExecEntThread = Scr_ExecEntThread_t(0x52B170);
	Scr_FreeThread_t Scr_FreeThread = Scr_FreeThread_t(0x569E20);

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


	G_GetHitLocationString_t G_GetHitLocationString = G_GetHitLocationString_t(0x5052A0);
}
