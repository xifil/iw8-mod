#include "Main.hpp"
#include "hooks/hooks.hpp"

IW8::dvar_t* Hooks::Dvar_FindVarByName_Detour(const char* dvarName) {
	return g_Dvar_FindVarByName.stub<IW8::dvar_t*>(dvarName);
}
