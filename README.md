# Plutoscript Framework

A collection of plugins to boost  **Plutonium IW5** script capabilities. Check [PlutoniumProject](https://forum.plutonium.pw/) forum for more information.

## plutoscript-shared

Static library included in all plugins to provide game data definitions and basic utility.

## plutoscript-callbacks

Update:
- Killcams working

Known Bugs:
- Dont use entity fields at Scr_PlayerDamage, spaming entity field calls in a short period of time makes chai crash.

chaiscript code:
``` cpp
def onStartupGameType()
{

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
def onPlayerConnected(args)
{
	var ePlayer = args[0];
}

/*
Params:
	ePlayer: 	entity
	return: 	void
*/
def onPlayerSpawned(args)
{
	var ePlayer = args[0];
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
	ePlayer:		entity
	eInflictor: 	entity
	eAttacker:		entity
	iDamage:		integer
	iDflags:		integer
	sMeansOfDeath:	string
	sWeapon:		string
	vPoint:			vector
	vDir:			vector
	sHitloc:		string
	iTimeOffset:	integer
	return:			void
*/
def onPlayerDamage(ePlayer, eInflictor, eAttacker, iDamage, iDflags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitloc, iTimeOffset)
{

}

/*
Params:
	ePlayer:		entity
	eInflictor: 	entity
	eAttacker:		entity
	iDamage:		integer
	sMeansOfDeath:	string
	sWeapon:		string
	vDir:			vector
	sHitloc:		string
	iTimeOffset:	integer
	iDeathAnimDuration: integer
	return:			void
*/
def onPlayerKilled(ePlayer, eInflictor, eAttacker, iDamage, sMeansOfDeath, sWeapon, vDir, sHitloc, iTimeOffset, iDeathAnimDuration)
{

}

add_callback_startup_game(onStartupGameType);
add_callback_player_connect(onPlayerConnect);
add_callback_player_disconnect(onPlayerDisconnect);
add_callback_player_damage(onPlayerDamage);
add_callback_player_killed(onPlayerKilled);
level.onNotify("connected", onPlayerConnected);
level.onNotify("player_spawned", onPlayerSpawned);
```
## plutoscript-commands

Add support to handle server & client commands.

## plutoscript-snipers

C++ plugin for TS servers.
