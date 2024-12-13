#include "Main.hpp"
#include "game/game.hpp"
#include "hooks/hooks.hpp"

void Hooks::Essential() {
#	if CLIENT_SHIP
		g_DB_LoadXFile.create(g_Pointers->m_DB_LoadXFile, DB_LoadXFile_Detour);
#	else
		g_CG_MainMP_Init.create(0x141792E60_g, CG_MainMP_Init_Detour);
		g_CL_CreateDevGui.create(0x1415B2080_g, CL_CreateDevGui_Detour);
		g_Com_GameMode_SupportsFeature.create(0x1410C8980_g, Com_GameMode_SupportsFeature_Detour);
		g_DB_CheckXFileVersion.create(0x1411A7840_g, DB_CheckXFileVersion_Detour);
		g_DB_LoadXFile.create(g_Pointers->m_DB_LoadXFile, DB_LoadXFile_Detour);
		// g_DB_PollFastfileState.create(0x1411ADD00_g, DB_PollFastfileState_Detour);
		g_DDL_SetUInt.create(0x1420529C0_g, DDL_SetUInt_Detour);
		g_Dvar_FindVarByName.create(0x1413E63A0_g, Dvar_FindVarByName_Detour);
		g_Dvar_RegisterBool.create(0x1413E7670_g, Dvar_RegisterBool_Detour);
		g_Dvar_RegisterString.create(0x1413E7A70_g, Dvar_RegisterString_Detour);
		g_Load_ClipMapAsset.create(0x140F60F40_g, Load_ClipMapAsset_Detour);
		g_LUI_CoD_LuaCall_CRMGetMessageContent_impl.create(0x141AC2900_g, LUI_CoD_LuaCall_CRMGetMessageContent_impl_Detour);
		g_LUI_CoD_LuaCall_GetServerData.create(0x1419E1680_g, LUI_CoD_LuaCall_GetServerData_Detour);
		g_MarketingCommsManager_GetMessageToDisplayCount.create(0x140F69500_g, MarketingCommsManager_GetMessageToDisplayCount_Detour);
		g_NET_OutOfBandData.create(0x1412BB350_g, NET_OutOfBandData_Detour);
		g_PartyHost_StartPrivateParty.create(g_Pointers->m_PartyHost_StartPrivateParty, PartyHost_StartPrivateParty_Detour);
		g_ProcessScriptFile.create(g_Pointers->m_ProcessScriptFile, ProcessScriptFile_Detour);
		g_SEH_StringEd_GetString.create(g_Pointers->m_SEH_StringEd_GetString, SEH_StringEd_GetString_Detour);
		g_SV_UpdateUserinfo_f.create(g_Pointers->m_SV_UpdateUserinfo_f, SV_UpdateUserinfo_f_Detour);
#	endif
}

void Hooks::Secondary() {
	g_DB_Zones_PerformZoneLoad.create(g_Pointers->m_DB_Zones_PerformZoneLoad, DB_Zones_PerformZoneLoad_Detour);
}
