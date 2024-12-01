#include "Main.hpp"
#include "hooks/hooks.hpp"

IW8::dvar_t* Hooks::Dvar_RegisterString_Detour(const char* dvarName, const char* value, unsigned int flags, const char* description) {
	return g_Dvar_RegisterString.stub<IW8::dvar_t*>(dvarName, value, flags, description);
}
