#pragma once

namespace game
{

static xsk::variable<scr_string_t*> modNames(0x8AB8B8);
static xsk::variable<CmdArgs> cmd_args(0x1C978D0);
static xsk::variable<CmdArgs> sv_cmd_args(0x1CAA998);
static xsk::variable<gentity_s> g_entities(0x1A66E28);

} // namespace game
