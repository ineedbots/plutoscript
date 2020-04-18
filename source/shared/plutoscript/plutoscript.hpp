#pragma once

using namespace game;

namespace plutoscript
{
	std::string GetMeansOfDeathName(MeansOfDeath mod);
	std::string GetHitLocationName(HitLocation hitloc);
	std::string GetWeaponName(Weapon weapon, int isAlternate);
}