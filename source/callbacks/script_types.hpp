
namespace plutoscript
{
	struct Vec3
	{
		float x;
		float y;
		float z;

		Vec3() : x(0.0f), y(0.0f), z(0.0f) { }
		Vec3(const float f[3]): x(f[0]), y(f[1]), z(f[2]) { }
		Vec3(const float fx, const float fy, const float fz) : x(fx), y(fy), z(fz) { }
		Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) { }

		operator std::string() const
		{
			return ("(" + std::to_string(this->x) + "," + std::to_string(this->y) + "," + std::to_string(this->z) + ")");
		}
	};


	enum MeansOfDeath
	{
		MOD_UNKNOWN,
		MOD_PISTOL_BULLET,
		MOD_RIFLE_BULLET,
		MOD_EXPLOSIVE_BULLET,
		MOD_GRENADE,
		MOD_GRENADE_SPLASH,
		MOD_PROJECTILE,
		MOD_PROJECTILE_SPLASH,
		MOD_MELEE,
		MOD_HEAD_SHOT,
		MOD_CRUSH,
		MOD_FALLING,
		MOD_SUICIDE,
		MOD_TRIGGER_HURT,
		MOD_EXPLOSIVE,
		MOD_IMPACT
	};

	enum HitLocation
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
}