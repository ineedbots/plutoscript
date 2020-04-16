#include "../stdinc.hpp"

namespace util::hook
{
	uintptr_t __::detour(uintptr_t target, uintptr_t hook, const int len)
	{
		uintptr_t tampoline = (uintptr_t)VirtualAlloc(0, len + 5, MEM_COMMIT | MEM_RESERVE, PAGE_EXECUTE_READWRITE);

		std::memcpy((void*)tampoline, (void*)target, len);

		*(uint8_t*)(tampoline + len) = 0xE9;
		*(uintptr_t*)(tampoline + len + 1) = (uintptr_t)(target - tampoline - 5);

		DWORD dwBack;
		VirtualProtect((void*)target, len, PAGE_EXECUTE_READWRITE, &dwBack);

		*(uint8_t*)target = 0xE9;
		*(uintptr_t*)(target + 1) = (uintptr_t)((uintptr_t)hook - target - 5);

		for (int i = 5; i < len; i++)
			*(uint8_t*)(target + i) = 0x90;

		VirtualProtect((void*)target, len, dwBack, &dwBack);

		return tampoline;
	}
}
