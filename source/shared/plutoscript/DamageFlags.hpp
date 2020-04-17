
namespace plutoscript
{
	enum DamageFlags
	{
		DFLAGS_RADIUS = 1,							// damage was indirect
		DFLAGS_NO_ARMOR = 2,						// armor does not protect from this damage
		DFLAGS_NO_KNOCKBACK = 4,					// do not affect velocity, just view angles
		DFLAGS_PENETRATION = 8,						// damage occurred after one or more penetrations
		DFLAGS_STUN = 16,							// non-lethal
		DFLAGS_SHIELD_EXPLOSIVE_IMPACT = 32,		// missile impacted on the front of the victim's shield
		DFLAGS_SHIELD_EXPLOSIVE_IMPACT_HUGE = 64,	//   ...and was from a projectile with "Big Explosion" checked on.
		DFLAGS_SHIELD_EXPLOSIVE_SPLASH = 128,		// explosive splash, somewhat deflected by the victim's shield

		// script-defined:
		DFLAGS_NO_TEAM_PROTECTION = 256,
		DFLAGS_NO_PROTECTION = 512,
		DFLAGS_PASSTHRU = 1024,
	};
}