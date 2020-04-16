#pragma once

//
#pragma warning(disable: 26812)

// Windows
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// C/C++


// Vendor


// Chaiscirpt
#pragma warning(push)
#pragma warning(disable: 4244)	// possible loss of data
#include "chaiscript/chaiscript.hpp"
#pragma warning(pop)

// Utils
#include "util/memory.hpp"
#include "util/hook.hpp"

// Game
#include "game/structs.hpp"
#include "game/vars.hpp"
#include "game/funcs.hpp"
