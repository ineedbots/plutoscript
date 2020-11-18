#pragma once

namespace plutoscript
{
	std::string GetMeansOfDeathName(game::MeansOfDeath mod);
	std::string GetHitLocationName(game::HitLocation hitloc);
	std::string GetWeaponName(game::Weapon weapon, int isAlternate);
}