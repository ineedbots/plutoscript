#include "../stdinc.hpp"
#include "structs.hpp"
#include "vars.hpp"

namespace game
{
	scr_string_t* modNames = *(scr_string_t**)(0x8AB8B8);
	__int16* playerdmg_thread_handle = reinterpret_cast<__int16*>(0x1C86A30);

	CmdArgs* cmd_args = reinterpret_cast<CmdArgs*>(0x1C978D0);
	CmdArgs* sv_cmd_args = reinterpret_cast<CmdArgs*>(0x1CAA998);

	gentity_s* g_entities = reinterpret_cast<gentity_s*>(0x1A66E28);
}
