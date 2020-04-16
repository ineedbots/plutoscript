#pragma once

namespace util::hook
{
	namespace __
	{
		uintptr_t detour(uintptr_t target, uintptr_t hook, const int len);
	}

	template<typename T>
	T detour(uintptr_t target, T hook, const int len)
	{
		return reinterpret_cast<T>(__::detour(target, reinterpret_cast<uintptr_t>(hook), len));
	}
}
