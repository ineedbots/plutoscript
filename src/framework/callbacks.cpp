#include "stdinc.hpp"
#include "callbacks.hpp"

chaiscript::ChaiScript* callbacks::ctx_;

utils::hook::detour callbacks::startup_gametype_hook_;
utils::hook::detour callbacks::player_connect_hook_;
utils::hook::detour callbacks::player_disconnect_hook_;
utils::hook::detour callbacks::player_damage_hook_;
utils::hook::detour callbacks::player_killed_hook_;
utils::hook::detour callbacks::client_command_hook_;
utils::hook::detour callbacks::sv_userbot_hook_;

std::vector<startup_gametype_calltype>	callbacks::startup_gametype_callbacks_;
std::vector<player_connect_calltype>	callbacks::player_connect_callbacks_;
std::vector<player_disconnect_calltype>	callbacks::player_disconnect_callbacks_;
std::vector<player_damage_calltype>		callbacks::player_damage_callbacks_;
std::vector<player_killed_calltype>		callbacks::player_killed_callbacks_;
std::vector<player_message_calltype>	callbacks::player_message_callbacks_;

callbacks::botMovements callbacks::g_botai[MAX_CLIENTS];

void callbacks::init()
{
	startup_gametype_hook_	= utils::hook::detour(game::Scr_StartupGameType, startup_gametype_stub, 5);
	player_connect_hook_	= utils::hook::detour(game::Scr_PlayerConnect, player_connect_stub, 5);
	player_disconnect_hook_ = utils::hook::detour(game::Scr_PlayerDisconnect, player_disconnect_stub, 5);
	player_damage_hook_		= utils::hook::detour(game::Scr_PlayerDamage, player_damage_stub, 10);
	player_killed_hook_		= utils::hook::detour(game::Scr_PlayerKilled, player_killed_stub, 10);
	client_command_hook_	= utils::hook::detour(game::ClientCommand, client_command_stub, 6);
	//vm_notify_hook_		= utils::hook::detour(VM_Notify, vm_notify_stub, 6);

	sv_userbot_hook_	= utils::hook::detour(0x5770B0, sv_userbot_stub_, 5);
}

void callbacks::init_bot_vars()
{
	for (int i = 0; i < MAX_CLIENTS; i++)
	{
		callbacks::g_botai[i] = { 0 };

		callbacks::g_botai[i].buttonsDvar = game::Dvar_RegisterInt(utils::string::va("bot%d_buttons", i), 0, 0x80000000, 0x7FFFFFFF, game::DVAR_FLAG_USERCREATED, "");
		callbacks::g_botai[i].movementDvar = game::Dvar_RegisterVec2(utils::string::va("bot%d_movement", i), 0.0f, 0.0f, -127.0f, 127.0f, game::DVAR_FLAG_USERCREATED, "");
		callbacks::g_botai[i].weaponDvar = game::Dvar_RegisterString(utils::string::va("bot%d_weapon", i), "", game::DVAR_FLAG_USERCREATED, "");
		callbacks::g_botai[i].pingDvar = game::Dvar_RegisterInt(utils::string::va("bot%d_ping", i), 0, 0, 1000, game::DVAR_FLAG_USERCREATED, "");
	}
}

void callbacks::sv_userbot_stub(game::client_s* cl)
{
	int cl_num = cl - game::svs_clients;
	
	char forward;
	char right;
	short weapon;
	game::usercmd_s cmd = { 0 };

	if (cl->state < 4)
	{
		game::SV_DropClient(cl, "EXE_DISCONNECTED", 1);
		cl->state = 0;
		return;
	}


	forward = (int)callbacks::g_botai[cl_num].movementDvar->current.vector[0];
	right = (int)callbacks::g_botai[cl_num].movementDvar->current.vector[1];


	const char *weap = callbacks::g_botai[cl_num].weaponDvar->current.string;
	if (!strcmp(weap, ""))
		weapon = 1;
	else
		weapon = game::G_GetWeaponForName(weap);

	
	cmd.serverTime = game::svs_time;

	cmd.weapon = weapon;
	cmd.buttons = callbacks::g_botai[cl_num].buttonsDvar->current.unsignedInt;
	cmd.forwardmove = forward;
	cmd.rightmove = right;

	cl->deltaMessage = cl->outgoingSequence - 1;
	game::SV_ClientThink(cl, &cmd);
}

__declspec(naked) void callbacks::sv_userbot_stub_()
{
	__asm
	{
		push edi
		call callbacks::sv_userbot_stub
		add esp, 4

		retn
	}
}

void callbacks::cleanup()
{
	startup_gametype_callbacks_.clear();
	player_connect_callbacks_.clear();
	player_disconnect_callbacks_.clear();
	player_damage_callbacks_.clear();
	player_killed_callbacks_.clear();
	player_message_callbacks_.clear();
}

void callbacks::context(chaiscript::ChaiScript* ctx)
{
	ctx_ = ctx;
}

void callbacks::add_callback_startup_game(startup_gametype_calltype callback)
{
	startup_gametype_callbacks_.push_back(callback);
}

void callbacks::add_callback_player_connect(player_connect_calltype callback)
{
	player_connect_callbacks_.push_back(callback);
}

void callbacks::add_callback_player_disconnect(player_disconnect_calltype callback)
{
	player_disconnect_callbacks_.push_back(callback);
}

void callbacks::add_callback_player_damage(player_damage_calltype callback)
{
	player_damage_callbacks_.push_back(callback);
}

void callbacks::add_callback_player_killed(player_killed_calltype callback)
{
	player_killed_callbacks_.push_back(callback);
}

void callbacks::add_callback_player_message(player_message_calltype callback)
{
	player_message_callbacks_.push_back(callback);
}

void callbacks::startup_gametype_stub()
{
	for (auto& callback : startup_gametype_callbacks_)
	{
		callback();
	}

	callbacks::init_bot_vars();

	return startup_gametype_hook_.invoke<void>();
}

void callbacks::player_connect_stub(game::gentity_s* self)
{
	auto self_ = ctx_->eval("level.getEntByNum(" + std::to_string(self->state.number) + ")");

	for (auto& callback : player_connect_callbacks_)
	{
		callback(self_);
	}

	return player_connect_hook_.invoke<void>(self);
}

void callbacks::player_disconnect_stub(game::gentity_s* self)
{
	auto self_ = ctx_->eval("level.getEntByNum(" + std::to_string(self->state.number) + ")");

	for (auto& callback : player_disconnect_callbacks_)
	{
		callback(self_);
	}

	return player_disconnect_hook_.invoke<void>(self);
}

void callbacks::player_damage_stub(game::gentity_s* self, game::gentity_s* inflictor, game::gentity_s* attacker, int damage,  int dflags, game::MeansOfDeath meansOfDeath, game::Weapon weapon, bool isAlternate, const float* vPoint, const float* vDir, game::HitLocation hitLoc, int timeOffset)
{
	auto self_ = ctx_->eval("level.getEntByNum(" + std::to_string(self->state.number) + ")");
	
	auto inflictor_ = inflictor != 0 ? ctx_->eval("level.getEntByNum(" + std::to_string(inflictor->state.number) + ")") : chaiscript::Boxed_Value{};
	
	auto attacker_ = attacker != 0 ? ctx_->eval("level.getEntByNum(" + std::to_string(attacker->state.number) + ")") : chaiscript::Boxed_Value{};
		
	auto mod_ = plutoscript::GetMeansOfDeathName(meansOfDeath);
	
	auto weapon_ = plutoscript::GetWeaponName(weapon, isAlternate);

	auto point_ = plutoscript::vector_to_chai(vPoint);

	auto dir_ = plutoscript::vector_to_chai(vDir);

	auto hitloc_ = plutoscript::GetHitLocationName(hitLoc);

	for (auto& callback : player_damage_callbacks_)
	{
		callback(self_, inflictor_, attacker_, damage, dflags, mod_, weapon_, point_, dir_, hitloc_, timeOffset);
	}

	if (damage == 0) return;

	return player_damage_hook_.invoke<void>(self, inflictor, attacker, damage, dflags, meansOfDeath, weapon, isAlternate, vPoint, vDir, hitLoc, timeOffset);
}

void callbacks::player_killed_stub(game::gentity_s* self, game::gentity_s* inflictor, game::gentity_s* attacker, int damage, game::MeansOfDeath meansOfDeath, game::Weapon weapon, bool isAlternate, const float* vDir, game::HitLocation hitLoc, int psTimeOffset, int deathAnimDuration)
{
	auto self_ = ctx_->eval("level.getEntByNum(" + std::to_string(self->state.number) + ")");
	
	auto inflictor_ = inflictor != 0 ? ctx_->eval("level.getEntByNum(" + std::to_string(inflictor->state.number) + ")") : chaiscript::Boxed_Value{};
	
	auto attacker_ = attacker != 0 ? ctx_->eval("level.getEntByNum(" + std::to_string(attacker->state.number) + ")") : chaiscript::Boxed_Value{};
	
	auto mod_ = plutoscript::GetMeansOfDeathName(meansOfDeath);
	
	auto weapon_ = plutoscript::GetWeaponName(weapon, isAlternate);

	auto dir_ = plutoscript::vector_to_chai(vDir);

	auto hitloc_ = plutoscript::GetHitLocationName(hitLoc);

	for (auto& callback : player_killed_callbacks_)
	{
		callback(self_, inflictor_, attacker_, damage, mod_, weapon_, dir_, hitloc_, psTimeOffset, deathAnimDuration);
	}
		
	return player_killed_hook_.invoke<void>(self, inflictor, attacker, damage, meansOfDeath, weapon, isAlternate, vDir, hitLoc, psTimeOffset, deathAnimDuration);
}

void callbacks::client_command_stub(int clientNum)
{
	if (player_message_callbacks_.size() <= 0)
	{
		return client_command_hook_.invoke<void>(clientNum);
	}

	char cmd[1024];
	auto hidden = false;

	game::SV_Cmd_ArgvBuffer(0, cmd, 1024);

	if (cmd == "say"s || cmd == "say_team"s)
	{
		auto self = ctx_->eval("level.getEntByNum(" + std::to_string(clientNum) + ")");

		std::string message = std::string(game::ConcatArgs(1));
		message.erase(0, 1);

		for (auto& callback : player_message_callbacks_)
		{
			callback(self, message, hidden);
		}
	}

	if (!hidden)
	{
		return client_command_hook_.invoke<void>(clientNum);
	}
}


//VM_Notify_t VM_Notify_;

/*void VM_Notify_stub(unsigned int notifyListOwnerId, scr_string_t stringValue, VariableValue* top)
{
	const char* string = SL_ConvertToString(stringValue);

	int numArgs = 0;

	if (top->type != 8)
	{
		for (VariableValue* value = top; value->type != 8; value--)
		{
			numArgs++;
		}
	}
	//printf("VM_Notify: id='%s' ArgsNum='%d'\n", string, numArgs);
	return VM_Notify_(notifyListOwnerId, stringValue, top);
}*/

/*
int* clientNum;

void handle_client_command()
{
	printf("handle_client_command \n");
	//printf("client cmd: %s\n", SV_Cmd_Argv(0));
	//if (!Scriptability_ClientCommand(Cmd_Argv_sv(0), *clientNum))
	//{
		//const char* unkCmd = util::string::va("%c \"GAME_UNKNOWNCLIENTCOMMAND\x15%s", 101, SV_Cmd_Argv(0));
		//SV_GameSendServerCommand(*clientNum, SV_CMD_CAN_IGNORE, unkCmd);
	//}
}*/
