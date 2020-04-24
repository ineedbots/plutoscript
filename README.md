# Plutoscript Framework

A collection of plugins to boost  **Plutonium IW5** script capabilities. Check [PlutoniumProject](https://forum.plutonium.pw/) forum for more information.

## Install
Download the files from [https://github.com/xensik/plutoscript/releases](https://github.com/xensik/plutoscript/releases)  
Place _**plutoscript-framework.dll**_ in _'plutoniumfolder'/storage/iw5/plugins_

___
## Usage

### GSC Callbacks

Enables use of gsc thread calls.

> Known Bugs:
>- Dont use entity fields at Scr_PlayerDamage, spaming entity field calls in a short period of time makes chai crash.

chaiscript:
``` cpp
def onStartupGameType()
{

}

add_callback_startup_game(onStartupGameType);
```
``` cpp
/* Params
	ePlayer: 	entity
	return: 	void
*/
def onPlayerConnect(ePlayer)
{

}

add_callback_player_connect(onPlayerConnect);
```
``` cpp
/* Params
	args: 		vector
	return: 	void
*/
def onPlayerConnected(args)
{
	var ePlayer = args[0];
	
}

level.onNotify("connected", onPlayerConnected);
```
``` cpp
/* Params
	args: 		vector
	return: 	void
*/
def onPlayerSpawned(args)
{
	var ePlayer = args[0];
}

level.onNotify("player_spawned", onPlayerSpawned);
```
``` cpp
/* Params
	ePlayer: 	entity
	return: 	void
*/
def onPlayerDisconnect(ePlayer)
{

}

add_callback_player_disconnect(onPlayerDisconnect);
```
``` cpp
/* Params
	ePlayer:		entity
	eInflictor: 		entity
	eAttacker:		entity
	iDamage:		integer
	iDflags:		integer
	sMeansOfDeath:		string
	sWeapon:		string
	vPoint:			vector
	vDir:			vector
	sHitloc:		string
	iTimeOffset:		integer
	return:			void
*/
def onPlayerDamage(ePlayer, eInflictor, eAttacker, iDamage, iDflags, sMeansOfDeath, sWeapon, vPoint, vDir, sHitloc, iTimeOffset)
{

}

add_callback_player_damage(onPlayerDamage);
```
``` cpp
/* Params
	ePlayer:		entity
	eInflictor: 		entity
	eAttacker:		entity
	iDamage:		integer
	sMeansOfDeath:		string
	sWeapon:		string
	vDir:			vector
	sHitloc:		string
	iTimeOffset:		integer
	iDeathAnimDuration: 	integer
	return:			void
*/
def onPlayerKilled(ePlayer, eInflictor, eAttacker, iDamage, sMeansOfDeath, sWeapon, vDir, sHitloc, iTimeOffset, iDeathAnimDuration)
{

}

add_callback_player_killed(onPlayerKilled);
```

____
### Chat Messages

Adds support to write messages from the server.

chaiscript:
```cpp
chat_raw_say_all("hello from chai");
```
**output:** ``hello from chai``
```cpp
chat_say_all("hello boyz");
```
**output:** ``console: hello boyz``
```cpp
chat_say_all("myserver", "hello boyz");
```
**output:** ``myserver: hello boyz``
```cpp
chat_raw_say_to(player.getEntNum(), "welcome");
```
**output** (only displayed to player)**:** ``welcome`` 
```cpp
chat_say_to(player.getEntNum(), "hello bro");
```
**output** (only displayed to player)**:** ``console: hello bro``
```cpp
chat_say_to(player.getEntNum(), "myserver", "ban warning (1/3)");
```
**output** (only displayed to player)**:** ``myserver: ban warning (1/3)`` 

Support for using entities directly will be added in the future (``chat_say_to(player, "hi");``)

____
### Commands
Handle server and client commands

chaiscript:
Execute server command:
```cpp
cmd_execute("map_restart");
```

Handlers comming soon™



## Info

``iDamage`` & ``iDFlags`` values are passed by reference, you can edit them to modify GSC behavior.

Means of Death names:
```cpp
MOD_UNKNOWN
MOD_PISTOL_BULLET
MOD_RIFLE_BULLET
MOD_EXPLOSIVE_BULLET
MOD_GRENADE
MOD_GRENADE_SPLASH
MOD_PROJECTILE
MOD_PROJECTILE_SPLASH
MOD_MELEE
MOD_HEAD_SHOT
MOD_CRUSH
MOD_FALLING
MOD_SUICIDE
MOD_TRIGGER_HURT
MOD_EXPLOSIVE
MOD_IMPACT
```
Hit Location names: 
```cpp
none
helmet
head
neck
torso_upper
torso_lower
right_arm_upper
left_arm_upper
right_arm_lower
left_arm_lower
right_hand
left_hand
right_leg_upper
left_leg_upper
right_leg_lower
left_leg_lower
right_foot
left_foot
shield
```
