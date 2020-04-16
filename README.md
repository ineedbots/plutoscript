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

def onPlayerConnect(self)
{
	print("[main.chai] onPlayerConnect(${self})");
}

def onPlayerConnected(self)
{
	print("[main.chai] onPlayerConnected(${self})");
}

def onPlayerSpawned(self)
{
	print("[main.chai] onPlayerSpawned(${self})");
}

def onPlayerDisconnect(self)
{
	print("[main.chai] onPlayerDisconnect(${self})");
}

def onPlayerDamaged(self, inflictor, attacker, damage, dflags, meansOfDeath, weapon, point, dir, hitloc)
{
	print("[main.chai] onPlayerDamaged(e${self}, e${inflictor}, e${attacker}, ${damage}, ${dflags}, ${meansOfDeath}, ${weapon}, ${point}, ${dir}, ${hitloc})");
}

def onPlayerKilled(self, inflictor, attacker, damage, meansOfDeath, weapon, dir, hitloc)
{
	print("[main.chai] onPlayerKilled(e${self}, e${inflictor}, e${attacker}, ${damage}, ${meansOfDeath}, ${weapon}, ${dir}, ${hitloc})");
}

add_callback_startup_game(onStartupGameType);
add_callback_player_connect(onPlayerConnect);
add_callback_player_disconnect(onPlayerDisconnect);
add_callback_player_damage(onPlayerDamaged);
add_callback_player_killed(onPlayerKilled);
```
### more to come ...
