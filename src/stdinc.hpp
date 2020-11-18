#pragma once

// Warnings
#pragma warning(disable: 4244)	// possible loss of data
#pragma warning(disable: 26812)

// Windows
#define DLL_EXPORT extern "C" __declspec(dllexport)
#define WIN32_LEAN_AND_MEAN
#include <windows.h>

// C/C++
#include <functional>
#include <mutex>
#include <string>
#include <vector>

using namespace std::literals;

// Utils
#include "utils/pointer.hpp"
#include "utils/memory.hpp"
#include "utils/hook.hpp"
#include "utils/string.hpp"

// Game
#include "game/chaiscript/chaiscript.hpp"
#include "game/structs.hpp"
#include "game/variables.hpp"
#include "game/functions.hpp"

// Plutoscript
#include "framework/Vec3.hpp"
#include "framework/plutoscript.hpp"
