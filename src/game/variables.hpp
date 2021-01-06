#pragma once

namespace game
{

static utils::variable<scr_string_t*> modNames(0x8AB8B8);
static utils::variable<CmdArgs> cmd_args(0x1C978D0);
static utils::variable<CmdArgs> sv_cmd_args(0x1CAA998);
static utils::variable<gentity_s> g_entities(0x1A66E28);

static utils::variable<client_s> svs_clients(0x4B5CF90);
static utils::variable<int> svs_maxclients(0x4B5CF8C);
static utils::variable<int> svs_time(0x4B5CF80);

} // namespace game
