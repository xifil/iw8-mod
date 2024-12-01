#include "Main.hpp"
#include "hooks/hooks.hpp"

void Hooks::Essential() {
	g_CG_MainMP_Init.create(0x141792E60_g, CG_MainMP_Init_Detour);
	g_CL_CreateDevGui.create(0x1415B2080_g, CL_CreateDevGui_Detour);
	g_Com_GameMode_SupportsFeature.create(0x1410C8980_g, Com_GameMode_SupportsFeature_Detour);
	g_DB_CheckXFileVersion.create(0x1411A7840_g, DB_CheckXFileVersion_Detour);
	g_DB_LoadXFile.create(0x1411A79F0_g, DB_LoadXFile_Detour);
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
	g_PartyHost_StartPrivateParty.create(0x14119F0D0_g, PartyHost_StartPrivateParty_Detour);
	g_ProcessScriptFile.create(0x141322350_g, ProcessScriptFile_Detour);
	g_SEH_StringEd_GetString.create(0x1413CC2A0_g, SEH_StringEd_GetString_Detour);
	g_SV_UpdateUserinfo_f.create(0x14136D0C0_g, SV_UpdateUserinfo_f_Detour);
}

void Hooks::Secondary() {
	g_DB_Zones_PerformZoneLoad.create(0x140F677A0_g, DB_Zones_PerformZoneLoad_Detour);
}
