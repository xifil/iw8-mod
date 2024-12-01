#include "Main.hpp"
#include "hooks/hooks.hpp"

IW8::dvar_t* Hooks::Dvar_RegisterBool_Detour(const char* dvarName, bool value, unsigned int flags, const char* description) {
	bool valuePatched = value;
	if (strcmp(dvarName, "LSTQOKLTRN") == 0) {
		printf("[Dvar_RegisterBool] patched force_offline_menus -> true\n");
		valuePatched = true;
	}
	if (strcmp(dvarName, "MPSSOTQQPM") == 0) {
		printf("[Dvar_RegisterBool] patched force_offline_enabled -> true\n");
		valuePatched = true;
	}
	if (strcmp(dvarName, "LNTOKPTKS") == 0) {
		printf("[Dvar_RegisterBool] patched lui_cod_points_enabled -> false\n");
		valuePatched = false;
	}
	return g_Dvar_RegisterBool.stub<IW8::dvar_t*>(dvarName, valuePatched, flags, description);
}
