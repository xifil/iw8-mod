#include "Main.hpp"
#include "game/game.hpp"
#include "hooks/hooks.hpp"
#include "functions.hpp"

const char* Hooks::SEH_StringEd_GetString_Detour(const char* pszReference) {
	const char* ret = g_SEH_StringEd_GetString.stub<const char*>(pszReference);

	if (!pszReference[1]) {
		if ((*pszReference & 0x80) != 0) {
			return "t";
		}
		return pszReference;
	}

	GamerProfile_SetDataByName(0, "acceptedEULA", 1);
	GamerProfile_SetDataByName(0, "hasEverPlayed_MainMenu", 1);

	bool isMapUnavailable = false;
	isMapUnavailable |= strcmp(pszReference, "LUA_MENU/MAPNAME_ANIYAH") == 0;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_M_CAGE") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_CAVE_AM") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_CAVE") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_M_CARGO") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_CRASH2") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_M_OVERUNDER") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_EUPHRATES") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_RAID") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_M_SHOWERS") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_RUNNER_AM") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_RUNNER") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_HACKNEY_AM") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_HACKNEY_YARD") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_M_HILL") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_PICCADILLY") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_M_PINE") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_SPEAR_AM") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_SPEAR") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_PETROGRAD") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_M_STACK") != nullptr;
	isMapUnavailable |= strstr(pszReference, "LUA_MENU/MAPNAME_VACANT") != nullptr;
	if (isMapUnavailable) {
		return g_Pointers->m_j_va("%s ^1(Unavailable)", ret);
	}

	bool isLaunchOptionUnavailable = false;
	isLaunchOptionUnavailable |= strstr(pszReference, "MENU_SP/CAMPAIGN") != nullptr;
	isLaunchOptionUnavailable |= strstr(pszReference, "LUA_MENU/LOCAL_COOP_CAPS") != nullptr;
	if (isLaunchOptionUnavailable) {
		return g_Pointers->m_j_va("^1%s", ret);
	}

	if (strstr(pszReference, "MENU/CAMPAIGN")) {
		return "^3Campaign is not available in this build of the game.";
	}

	if (strstr(pszReference, "LUA_MENU/LOCAL_COOP_DESC")) {
		return "^3CO-OP is not available in this build of the game.";
	}

	if (strstr(pszReference, "LUA_MENU/LOCAL_MULTIPLAYER_CAPS")) {
		return "MULTIPLAYER";
	}

	//if (strstr(pszReference, "LOCAL") != nullptr || strstr(pszReference, "local") != nullptr) {
	//	return g_Pointers->m_j_va("%s (%s)", ret, pszReference);
	//}
	//else {
		return ret;
	//}
}
