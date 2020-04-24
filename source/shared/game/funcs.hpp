#pragma once

namespace game
{
	// Dvars

	// Cbuf
	typedef void(__cdecl* Cbuf_AddText_t)(LocalClientNum_t localClientNum, const char* text);
	extern Cbuf_AddText_t Cbuf_AddText;

	// Cmd
	typedef void(__cdecl* Cmd_RegisterNotification_t)(const int clientNum, const char* commandString, const char* notifyString);
	extern Cmd_RegisterNotification_t Cmd_RegisterNotification;

	typedef void(__cdecl* SV_Cmd_ArgvBuffer_t)(int arg, char* buffer, int bufferLength);
	extern SV_Cmd_ArgvBuffer_t SV_Cmd_ArgvBuffer;

	inline int Cmd_Argc()
	{
		return cmd_args->argc[cmd_args->nesting];
	}

	inline const char* Cmd_Argv(int argIndex)
	{
		if (argIndex >= cmd_args->argc[cmd_args->nesting])
		{
			return "";
		}
		return cmd_args->argv[cmd_args->nesting][argIndex];
	}

	inline int SV_Cmd_Argc()
	{
		return sv_cmd_args->argc[sv_cmd_args->nesting];
	}

	inline const char* SV_Cmd_Argv(int argIndex)
	{
		if (argIndex >= sv_cmd_args->argc[sv_cmd_args->nesting])
		{
			return "";
		}
		return sv_cmd_args->argv[sv_cmd_args->nesting][argIndex];
	}

	// Server
	typedef void(__cdecl* SV_GameSendServerCommand_t)(int clientNum, svscmd_type type, const char* text);
	extern SV_GameSendServerCommand_t SV_GameSendServerCommand;

	typedef void(__cdecl* ClientCommand_t)(int clientNum);
	extern ClientCommand_t ClientCommand;

	// Script
	typedef const char* (__cdecl* SL_ConvertToString_t)(scr_string_t stringValue);
	extern SL_ConvertToString_t SL_ConvertToString;
	typedef void(__cdecl* VM_Notify_t)(unsigned int notifyListOwnerId, scr_string_t stringValue, VariableValue* top);
	extern VM_Notify_t VM_Notify;
	typedef void(__cdecl* Scr_AddInt_t)(int value);
	extern Scr_AddInt_t Scr_AddInt;
	typedef void(__cdecl* Scr_AddConstString_t)(scr_string_t value);
	extern Scr_AddConstString_t Scr_AddConstString;
	typedef void(__cdecl* Scr_AddVector_t)(const float* value);
	extern Scr_AddVector_t Scr_AddVector;
	typedef void(__cdecl* Scr_AddUndefined_t)();
	extern Scr_AddUndefined_t Scr_AddUndefined;
	typedef void(__cdecl* Scr_AddString_t)(const char* value);
	extern Scr_AddString_t Scr_AddString;
	typedef void(__cdecl* Scr_AddEntity_t)(gentity_s* ent);
	extern Scr_AddEntity_t Scr_AddEntity;
	typedef __int16(__cdecl* Scr_ExecEntThread_t)(gentity_s* ent, int handle, unsigned int paramcount);
	extern Scr_ExecEntThread_t Scr_ExecEntThread;
	typedef void(__cdecl* Scr_FreeThread_t)(unsigned __int16 handle);
	extern Scr_FreeThread_t Scr_FreeThread;

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
	typedef void(__cdecl* Scr_PlayerDamage_t)(gentity_s*, gentity_s*, gentity_s*, int, int, MeansOfDeath, Weapon, bool, const float*, const float*, HitLocation, int);
	extern Scr_PlayerDamage_t Scr_PlayerDamage;
	typedef void(__cdecl* Scr_PlayerKilled_t)(gentity_s*, gentity_s*, gentity_s*, int, MeansOfDeath, Weapon, bool, const float*, HitLocation, int, int);
	extern Scr_PlayerKilled_t Scr_PlayerKilled;

	typedef void(__cdecl* PlayerCmd_finishPlayerDamage_t)(scr_entref_t entref);
	extern PlayerCmd_finishPlayerDamage_t PlayerCmd_finishPlayerDamage;

	typedef char* (__cdecl* BG_GetWeaponNameComplete_t)(Weapon weapon, bool isAlternate, char* output, unsigned int maxStringLen);
	extern BG_GetWeaponNameComplete_t BG_GetWeaponNameComplete;
	typedef weapClass_t(__cdecl* BG_GetWeaponClass_t)(Weapon weapon, bool isAlternate);
	extern BG_GetWeaponClass_t BG_GetWeaponClass;
	typedef const char* (__cdecl* BG_GetWeaponClassName_t)(int type);
	extern BG_GetWeaponClassName_t BG_GetWeaponClassName;


	typedef unsigned int(__cdecl* Scr_GetEntityId_t)(int, unsigned int);
	extern Scr_GetEntityId_t Scr_GetEntityId;


	typedef scr_string_t(__cdecl* G_GetHitLocationString_t)(HitLocation hitLoc);
	extern G_GetHitLocationString_t G_GetHitLocationString;
}
