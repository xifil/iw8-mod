#include "addr_utils.hpp"

#include <cctype>
#include <string>
#include <windows.h>

struct Addresses {
	uintptr_t ModuleBase;
	uintptr_t jmp_rbx;
};

Addresses g_Addrs{};

void initAddrUtils() {
	g_Addrs.ModuleBase = (uintptr_t)(GetModuleHandle(0));
}

size_t _b(const size_t val) { return g_Addrs.ModuleBase + val; }

size_t operator"" _b(const size_t val) { return _b(val); }

size_t reverse_b(const size_t val) { return val - g_Addrs.ModuleBase; }

size_t reverse_b(const void* val) { return reverse_b(reinterpret_cast<size_t>(val)); }

size_t _g(const size_t val) { return g_Addrs.ModuleBase + (val - 0x140000000); }

size_t operator"" _g(const size_t val) { return _g(val); }

size_t reverse_g(const size_t val) { return (val - g_Addrs.ModuleBase) + 0x140000000; }

size_t reverse_g(const void* val) { return reverse_g(reinterpret_cast<size_t>(val)); }
