#pragma once
#include "Main.hpp"
#include "addr_utils.hpp"

#include "common/utils/hook.hpp"

#include "engine/iw8/DB_FFHeader.hpp"
#include "engine/iw8/DBFileHandle.hpp"
#include "engine/iw8/DDLContext.hpp"
#include "engine/iw8/DDLState.hpp"
#include "engine/iw8/dvar_t.hpp"
#include "engine/iw8/lua_State.hpp"
#include "engine/iw8/netadr_t.hpp"
#include "engine/iw8/ScriptFile.hpp"
#include "engine/iw8/XAssetHeader.hpp"
#include "engine/iw8/enums/DB_FastFileFailureMode.hpp"
#include "engine/iw8/enums/netsrc_t.hpp"

namespace Hooks {
	void Essential();
	void Secondary();

	inline utils::hook::detour g_CG_MainMP_Init;
	void CG_MainMP_Init_Detour(int localClientNum, int serverMessageNum, int serverCommandSequence, int clientNum, void* hunkUser);

	inline utils::hook::detour g_CL_CreateDevGui;
	void CL_CreateDevGui_Detour(int fsMenuEntries, const char* modeCfg);

	inline utils::hook::detour g_Com_GameMode_SupportsFeature;
	bool Com_GameMode_SupportsFeature_Detour(unsigned int featureID);

	inline utils::hook::detour g_DB_CheckXFileVersion;
	bool DB_CheckXFileVersion_Detour(const IW8::DB_FFHeader* header, const IW8::DBFileHandle* handle, const char* path, const char* baseFileForPatch);

	inline utils::hook::detour g_DB_LoadXFile;
	int DB_LoadXFile_Detour(const char* zoneName, uintptr_t zoneMem, uintptr_t assetList, int zoneFlags, bool wasPaused, int failureMode, uintptr_t outSignature);

	inline utils::hook::detour g_DB_PollFastfileState;
	int DB_PollFastfileState_Detour(const char* zoneName);

	inline utils::hook::detour g_DB_Zones_PerformZoneLoad;
	std::int64_t DB_Zones_PerformZoneLoad_Detour(bool processingPreloadedFiles, bool isBaseMap, bool wasPaused, IW8::DB_FastFileFailureMode failureMode);

	inline utils::hook::detour g_DDL_SetUInt;
	bool DDL_SetUInt_Detour(const IW8::DDLState* state, IW8::DDLContext* ddlContext, unsigned int val);

	inline utils::hook::detour g_Dvar_FindVarByName;
	IW8::dvar_t* Dvar_FindVarByName_Detour(const char* dvarName);

	inline utils::hook::detour g_Dvar_RegisterBool;
	IW8::dvar_t* Dvar_RegisterBool_Detour(const char* dvarName, bool value, unsigned int flags, const char* description);

	inline utils::hook::detour g_Dvar_RegisterString;
	IW8::dvar_t* Dvar_RegisterString_Detour(const char* dvarName, const char* value, unsigned int flags, const char* description);

	inline utils::hook::detour g_Load_ClipMapAsset;
	void Load_ClipMapAsset_Detour(IW8::XAssetHeader* clipMap);

	inline utils::hook::detour g_LUI_CoD_LuaCall_CRMGetMessageContent_impl;
	std::int64_t LUI_CoD_LuaCall_CRMGetMessageContent_impl_Detour(IW8::lua_State* luaVM);

	inline utils::hook::detour g_LUI_CoD_LuaCall_GetServerData;
	std::int64_t LUI_CoD_LuaCall_GetServerData_Detour(IW8::lua_State* luaVM);

	inline utils::hook::detour g_MarketingCommsManager_GetMessageToDisplayCount;
	std::uint32_t MarketingCommsManager_GetMessageToDisplayCount_Detour(void* _this, int messageType);

	inline utils::hook::detour g_NET_OutOfBandData;
	bool NET_OutOfBandData_Detour(IW8::netsrc_t sock, IW8::netadr_t* adr, const unsigned __int8* format, int len);

	inline utils::hook::detour g_PartyHost_StartPrivateParty;
	void PartyHost_StartPrivateParty_Detour(int localClientNum, int localControllerIndex, bool currentlyActive, int hostType);

	inline utils::hook::detour g_ProcessScriptFile;
	void ProcessScriptFile_Detour(void* scrContext, IW8::ScriptFile* scriptFile);

	inline utils::hook::detour g_SEH_StringEd_GetString;
	const char* SEH_StringEd_GetString_Detour(const char* pszReference);

	inline utils::hook::detour g_SV_UpdateUserinfo_f;
	void SV_UpdateUserinfo_f_Detour(void* cl);
}
