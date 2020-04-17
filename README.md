# Plutoscript Framework

A collection of plugins to boost  **Plutonium IW5** script capabilities. Check [PlutoniumProject](https://forum.plutonium.pw/) forum for more information.

## plutoscript-shared

Static library included in all plugins to provide game data definitions and basic utility.

**plutoscript types:**
- `Vec3 (struct)`
- `MeansOfDeath (enum)`
- `HitLocation ( enum)`

## plutoscript-callbacks

first approach, some things may not work.

chaiscript code:
``` cpp
def onStartupGameType()
{
	print("[main.chai] onStartupGameType");
}
/*
Params:
	ePlayer: 	entity
	return: 	void
*/
def onPlayerConnect(ePlayer)
{

}
/*
Params:
	ePlayer: 	entity
	return: 	void
*/
def onPlayerConnected(ePlayer)
{

}
/*
Params:
	ePlayer: 	entity
	return: 	void
*/
def onPlayerSpawned(ePlayer)
{

}
/*
Params:
	ePlayer: 	entity
	return: 	void
*/
def onPlayerDisconnect(ePlayer)
{

}
/*
Params:
	ePlayer: 	entity
	eInflictor: 	entity
	eAttacker: 	entity
	iDamage:	integer
	iDflags:	integer
	sMeansOfDeath:	string
	sWeapon:	string
	vDir:		vector
	sHitloc:	string
	return: 	void
*/
def onPlayerDamaged(ePlayer, eInflictor, eAttacker, iDamage, iDflags, sMeansOfDeath, sWeapon, vDir, sHitloc)
{

}
/*
Params:
	ePlayer: 	entity
	eInflictor: 	entity
	eAttacker: 	entity
	iDamage:	integer
	sMeansOfDeath:	string
	sWeapon:	string
	vDir:		vector
	sHitloc:	string
	return: 	void
*/
def onPlayerKilled(ePlayer, eInflictor, eAttacker, iDamage, sMeansOfDeath, sWeapon, vDir, sHitloc)
{

}

add_callback_startup_game(onStartupGameType);
add_callback_player_connect(onPlayerConnect);
add_callback_player_disconnect(onPlayerDisconnect);
add_callback_player_damage(onPlayerDamaged);
add_callback_player_killed(onPlayerKilled);
```
### more to come ...
