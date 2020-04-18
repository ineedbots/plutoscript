#pragma once

namespace util::hook
{
	template<typename T>
	T detour(T target, T hook, const int len)
	{
		uintptr_t tampoline = (uintptr_t)VirtualAlloc(0, len + 5, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

		std::memcpy((void*)tampoline, (void*)target, len);

		*(uint8_t*)(tampoline + len) = 0xE9;
		*(uintptr_t*)(tampoline + len + 1) = (uintptr_t)((uintptr_t)target - tampoline - 5);

		DWORD dwBack;
		VirtualProtect((void*)target, len, PAGE_EXECUTE_READWRITE, &dwBack);

		*(uint8_t*)target = 0xE9;
		*(uintptr_t*)((uintptr_t)target + 1) = (uintptr_t)((uintptr_t)hook - (uintptr_t)target - 5);

		for (int i = 5; i < len; i++)
			*(uint8_t*)((uintptr_t)target + i) = 0x90;

		VirtualProtect((void*)target, len, dwBack, &dwBack);

		return (T)tampoline;
	}
}
