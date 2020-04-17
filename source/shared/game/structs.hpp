#pragma once

namespace game
{
	typedef float vector3[3];

	//------------------------ Script

	typedef unsigned __int16 scr_string_t;
	typedef unsigned __int16 scr_thread_t;
	typedef int scr_func_t;


	union scr_entref_t
	{
		unsigned int val;

		struct
		{
			unsigned __int16 entnum;
			unsigned __int16 classnum;
		} raw;
	};

	typedef void(__cdecl* scr_call_t)(int entref);

	struct scr_classStruct_t
	{
		unsigned __int16 id;
		unsigned __int16 entArrayId;
		char charId;
		const char* name;
	};

	enum scriptType_e
	{
		SCRIPT_NONE = 0,
		SCRIPT_OBJECT = 1,
		SCRIPT_STRING = 2,
		SCRIPT_VECTOR = 4,
		SCRIPT_FLOAT = 5,
		SCRIPT_INTEGER = 6,
		SCRIPT_END = 8,
	};


	//------------------------ Entity

	/*struct entity_shared
	{

	};


	struct $39EF277EA8613772F6FC6094760A0E98
	{
		unsigned __int32 weaponIdx : 8;
		unsigned __int32 weaponVariation : 6;
		unsigned __int32 weaponScopes : 3;
		unsigned __int32 weaponUnderBarrels : 2;
		unsigned __int32 weaponOthers : 8;
		unsigned __int32 scopeVariation : 5;
	};

	union Weapon
	{
		$39EF277EA8613772F6FC6094760A0E98 __s0;
		unsigned int data;
	};


	struct LerpEntityStatePlayer
	{
		int movementDir;
		float lerpLean;
		float torsoPitch;
		float waistPitch;
		Weapon offhandWeapon;
		Weapon stowedWeapon;
		int lastSpawnTime;
	};


	union entity_state_lerp_typeU
	{

		LerpEntityStatePlayer player;
	};

	enum trajectory_type_t
	{
		TR_STATIONARY = 0x0,
		TR_INTERPOLATE = 0x1,
		TR_LINEAR = 0x2,
		TR_LINEAR_STOP = 0x3,
		TR_SINE = 0x4,
		TR_GRAVITY = 0x5,
		TR_LOW_GRAVITY = 0x6,
		TR_ACCELERATE = 0x7,
		TR_DECELERATE = 0x8,
		TR_PHYSICS = 0x9,
		TR_ANIMATED_MOVER = 0xA,
		TR_FIRST_RAGDOLL = 0xB,
		TR_RAGDOLL = 0xB,
		TR_RAGDOLL_GRAVITY = 0xC,
		TR_RAGDOLL_INTERPOLATE = 0xD,
		TR_LAST_RAGDOLL = 0xD,
		NUM_TRTYPES = 0xE,
	};

	struct trajectory_t
	{
		trajectory_type_t	trType;
		int					trTime;
		int					trDuration;
		float				trBase[3];
		float				trDelta[3];
	};

	struct entity_state_lerp
	{
		int eFlags;
		trajectory_t pos;
		trajectory_t apos;
		entity_state_lerp_typeU u;
	};*/

	struct entity_state
	{
		int					number;
		int					type;
		//entity_state_lerp	lerp;
	};

	struct entity
	{
		entity_state		state;
		//entity_shared		shared;
	}; // 0x1F8


	enum hit_location
	{
		HITLOC_NONE = 0x0,
		HITLOC_HELMET = 0x1,
		HITLOC_HEAD = 0x2,
		HITLOC_NECK = 0x3,
		HITLOC_TORSO_UPR = 0x4,
		HITLOC_TORSO_LWR = 0x5,
		HITLOC_R_ARM_UPR = 0x6,
		HITLOC_L_ARM_UPR = 0x7,
		HITLOC_R_ARM_LWR = 0x8,
		HITLOC_L_ARM_LWR = 0x9,
		HITLOC_R_HAND = 0xA,
		HITLOC_L_HAND = 0xB,
		HITLOC_R_LEG_UPR = 0xC,
		HITLOC_L_LEG_UPR = 0xD,
		HITLOC_R_LEG_LWR = 0xE,
		HITLOC_L_LEG_LWR = 0xF,
		HITLOC_R_FOOT = 0x10,
		HITLOC_L_FOOT = 0x11,
		HITLOC_GUN = 0x12,
		HITLOC_NUM = 0x13,
	};

	//------------------------ Weapons

	enum weapClass_t
	{
		WEAPCLASS_RIFLE = 0x0,
		WEAPCLASS_SNIPER = 0x1,
		WEAPCLASS_MG = 0x2,
		WEAPCLASS_SMG = 0x3,
		WEAPCLASS_SPREAD = 0x4,
		WEAPCLASS_PISTOL = 0x5,
		WEAPCLASS_GRENADE = 0x6,
		WEAPCLASS_ROCKETLAUNCHER = 0x7,
		WEAPCLASS_TURRET = 0x8,
		WEAPCLASS_THROWINGKNIFE = 0x9,
		WEAPCLASS_NON_PLAYER = 0xA,
		WEAPCLASS_ITEM = 0xB,
		WEAPCLASS_NUM = 0xC,
	};


	//------------------------ Cmd
	enum LocalClientNum_t
	{
		LOCAL_CLIENT_INVALID = 0xFFFFFFFF,
		LOCAL_CLIENT_0 = 0x0,
		LOCAL_CLIENT_LAST = 0x0,
		LOCAL_CLIENT_COUNT = 0x1,
	};

	struct CmdArgs
	{
		int nesting;
		LocalClientNum_t localClientNum[8];
		int controllerIndex[8];
		int argc[8];
		const char** argv[8];
	};

	struct CmdArgsPrivate
	{
		char textPool[8192];
		const char* argvPool[512];
		int usedTextPool[8];
		int totalUsedArgvPool;
		int totalUsedTextPool;
	};

	struct cmd_function_t
	{
		cmd_function_t* next;
		const char* name;
		const char* autoCompleteDir;
		const char* autoCompleteExt;
		void(__cdecl* function)();
		int flags;
	};


	//------------------------ Dvars
	union DvarValue
	{
		bool enabled;
		int integer;
		unsigned int unsignedInt;
		float value;
		float vector[4];
		const char* string;
		char color[4];
	};

	struct EnumLimits
	{
		int stringCount;
		const char** strings;
	};

	struct IntegerLimits
	{
		int min;
		int max;
	};

	struct FloatLimits
	{
		float min;
		float max;
	};

	union DvarLimits
	{
		EnumLimits enumeration;
		IntegerLimits integer;
		FloatLimits value;
		FloatLimits vector;
	};

	struct dvar_t
	{
		const char* name;
		unsigned int flags;
		char type;
		bool modified;
		DvarValue current;
		DvarValue latched;
		DvarValue reset;
		DvarLimits domain;
		bool(__cdecl* domainFunc)(dvar_t*, DvarValue);
		dvar_t* hashNext;
	};

}
