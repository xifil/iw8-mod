#include "lui_cod.h"
#include "game_inc.h"
#include "saved_settings.h"
#include "g_cmds.h"
#include "functions.hpp"

void LUI_CoD_RegisterDvars_Detour() {
	printf("[LUI_CoD_RegisterDvars] registering custom dvars...\n");
	Dvars::player_name = Dvar_RegisterString("player_name", "Unknown Soldier", 0, "Current display name (auto-saved)");
	Dvars::sv_cheats = Dvar_RegisterBool("sv_cheats", false, 0, "Enable cheats to be used on a server");
	Dvars::spawn_br_gas = Dvar_RegisterBool("spawn_br_gas", true, 0, "Enable gas in Battle Royale maps");
	Dvars::show_watermark = Dvar_RegisterBool("show_watermark", true, 0, "Show the iw8-mod watermark");
	Dvars::player_sustainAmmo = Dvar_RegisterBool("player_sustainAmmo", false, 0, "Prevent firing from decreasing ammo in the clip");
	Dvars::print_debug = Dvar_RegisterBool("print_debug", false, 0, "Print debug output to the external console");
	Dvars::weap_impactType = Dvar_RegisterInt("weap_impactType", -1, -1, 1000, 0, "Force a weapon impact type on every weapon. -1 = default");
	Dvars::weap_dismembermentAlwaysEnabled = Dvar_RegisterBool("weap_dismembermentAlwaysEnabled", false, 0, "Enable dismemberment effect for all weapons");
	Dvars::g_dumpScripts = Dvar_RegisterBool("g_dumpScripts", false, 0, "Dump GSC scripts");
	printf("[LUI_CoD_RegisterDvars] registered custom dvars.\n");

	lui_cod_registerdvars.stub<void>();

	saved_settings::Load();
	printf("[LUI_CoD_RegisterDvars] loaded player settings.\n");
	CopyStdString(saved_settings::g_player_name, &Dvars::player_name->m_Current.m_String);
}

int LuaShared_LuaCall_IsDemoBuild_Detour(uintptr_t luaVM) {
	lua_pushboolean(luaVM, 1);
	return 1;
}

void LUI_CoD_LuaCall_EngineNotifyServer_Detour(uintptr_t luaVM) {
	static bool executedUnlockAll = false;
	if (!executedUnlockAll && saved_settings::g_unlock_all_enabled) {
		Cmd_UnlockAll_f();
		executedUnlockAll = true;
	}
	static std::unordered_map<std::string, std::function<void()>> handlerMap = {
		{ "class_edit", SaveInventory },
		{ "loadout_showcase_entered", SaveInventory }
	};
	if (lua_isstring(luaVM, 1)) {
		size_t strLen = 0;
		const char* rawStr = lua_tolstring(luaVM, 1, &strLen);
		std::string str(rawStr, strLen);
		if (handlerMap.find(str) != handlerMap.cend()) {
			handlerMap.at(str)();
		}
	}
	lui_cod_luacall_enginenotifyserver_detour_impl.stub<void>(luaVM);
}