﻿# Plutoscript Framework

A collection of plugins to boost  **Plutonium IW5** script capabilities. Check [PlutoniumProject](https://forum.plutonium.pw/) forum for more information.

## plutoscript-shared

Static library included in all plugins to provide game data definitions and basic utility.

## plutoscript-callbacks

Killcams are broken due to a bug in Scr_PlayerDamage.

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
def onPlayerDamage(ePlayer, eInflictor, eAttacker, iDamage, iDflags, sMeansOfDeath, sWeapon, vDir, sHitloc)
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
add_callback_player_damage(onPlayerDamage);
add_callback_player_killed(onPlayerKilled);
level.onNotify("connected", onPlayerConnected);
level.onNotify("player_spawned", onPlayerSpawned);
```
## plutoscript-commands

Add support to handle server & client commands.

## plutoscript-snipers

C++ patched Scr_PlayerDamage (sniper only) to bypass killcam bug