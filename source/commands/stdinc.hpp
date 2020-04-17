#pragma once
#include <shared/stdinc.hpp>

#define DLL_EXPORT extern "C" __declspec(dllexport)

#ifdef _DEBUG
#define DEBUG_LOG(...) printf(__VA_ARGS__);
#else
#define DEBUG_LOG(...)
#endif // DEBUG
