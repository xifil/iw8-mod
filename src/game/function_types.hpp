#pragma once
#include "engine/iw8/clientUIActive_t.hpp"
#include "engine/iw8/CmdArgs.hpp"
#include "engine/iw8/DDLContext.hpp"
#include "engine/iw8/DDLState.hpp"
#include "engine/iw8/gameTypeInfo.hpp"
#include "engine/iw8/gentity_s.hpp"
#include "engine/iw8/lua_State.hpp"
#include "engine/iw8/mapInfo.hpp"
#include "engine/iw8/ScreenPlacement.hpp"
#include "engine/iw8/ScriptFile.hpp"
#include "engine/iw8/vec2_t.hpp"
#include "engine/iw8/vec3_t.hpp"
#include "engine/iw8/enums/DB_FastFileFailureMode.hpp"
#include "engine/iw8/enums/LocalClientNum_t.hpp"
#include "engine/iw8/enums/PartyHostType.hpp"
#include "engine/iw8/enums/StatsGroup.hpp"
#include "engine/iw8/enums/StatsSource.hpp"

namespace Game::Functions {
	using CG_WorldPosToScreenPosRealT = bool(IW8::LocalClientNum_t localClientNum, const IW8::ScreenPlacement* scrPlace, const IW8::vec3_t* worldPos, IW8::vec2_t* outScreenPos);
	using CL_PlayerData_GetDDLBufferT = bool(IW8::DDLContext* context, int controllerIndex, IW8::StatsSource statsSource, IW8::StatsGroup statsGroup);
	using Com_GameInfo_GetGameTypeForInternalNameT = IW8::gameTypeInfo*(const char* gameTypeName);
	using Com_GameInfo_GetMapInfoForLoadNameT = IW8::mapInfo*(const char* mapName);
	using Com_ParseNavStringsT = bool(const char* pStr, const char** navStrings, int navStringMax, int* navStringCount);
	using DB_Zones_PerformZoneLoadT = std::int64_t(bool processingPreloadedFiles, bool isBaseMap, bool wasPaused, IW8::DB_FastFileFailureMode failureMode);
	using DDL_GetEnumT = const char*(const IW8::DDLState* state, const IW8::DDLContext* ddlContext);
	using DDL_GetIntT = int(const IW8::DDLState* state, const IW8::DDLContext* ddlContext);
	using DDL_GetRootStateT = IW8::DDLState*(IW8::DDLState* result, const IW8::DDLDef* ddlDef);
	using DDL_GetStringT = const char*(const IW8::DDLState* state, const IW8::DDLContext* ddlContext);
	using DDL_MoveToPathT = bool(const IW8::DDLState* fromState, IW8::DDLState* toState, int depth, const char** path);
	using DDL_SetEnumT = void(IW8::DDLState* state, IW8::DDLContext* ddlContext, const char* val);
	using DDL_SetIntT = void(IW8::DDLState* state, IW8::DDLContext* ddlContext, int val);
	using DDL_SetStringT = void(IW8::DDLState* state, IW8::DDLContext* ddlContext, const char* val);
	using Dvar_GetIntSafeT = int(const char* dvarName);
	using Dvar_GetStringSafeT = const char*(const char* dvarName);
	using FS_ReadFileT = std::int64_t(const char* qpath, void** buffer);
	using Info_ValueForKeyT = const char*(const char* s, const char* key);
	using j_vaT = const char*(const char* fmt, ...);
	using lua_getfieldT = void(IW8::lua_State* L, int idx, const char* k);
	using lua_pushstringT = void(IW8::lua_State* L, const char* str);
	using lua_removeT = void(IW8::lua_State* L, int idx);
	using lua_tobooleanT = bool(IW8::lua_State* L, int idx);
	using lua_tointeger32T = std::int64_t(IW8::lua_State* L, int idx);
	using LuaShared_PCallT = bool(IW8::lua_State* luaVM, int nargs, int nresults);
	using LUI_BeginTableT = void(const char* key, IW8::lua_State* luaVM);
	using LUI_EndTableT = void(IW8::lua_State* luaVM);
	using LUI_OpenMenuT = void(IW8::LocalClientNum_t localClientNum, const char* menuName, int isPopup, int isModal, int isExclusive);
	using PartyHost_StartPrivatePartyT = void(IW8::LocalClientNum_t localClientNum, int localControllerIndex, bool currentlyActive, IW8::PartyHostType hostType);
	using ProcessScriptFileT = void(void* scrContext, IW8::ScriptFile* scriptFile);
	using SEH_StringEd_GetStringT = const char*(const char* pszReference);
	using SV_Cmd_ArgvT = const char*(int argIndex);
	using SV_UpdateUserinfo_fT = void(void* cl);
}
