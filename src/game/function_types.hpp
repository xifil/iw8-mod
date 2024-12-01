#pragma once
#include "engine/iw8/clientUIActive_t.hpp"
#include "engine/iw8/CmdArgs.hpp"
#include "engine/iw8/gentity_s.hpp"
#include "engine/iw8/lua_State.hpp"
#include "engine/iw8/ScreenPlacement.hpp"
#include "engine/iw8/vec2_t.hpp"
#include "engine/iw8/vec3_t.hpp"
#include "engine/iw8/enums/LocalClientNum_t.hpp"

namespace Game::Functions {
	using CG_WorldPosToScreenPosRealT = bool(IW8::LocalClientNum_t localClientNum, const IW8::ScreenPlacement* scrPlace, const IW8::vec3_t* worldPos, IW8::vec2_t* outScreenPos);
	using Dvar_GetStringSafeT = const char*(const char* dvarName);
	using FS_ReadFileT = std::int64_t(const char* qpath, void** buffer);
	using Info_ValueForKeyT = const char*(const char* s, const char* key);
	using j_vaT = const char*(const char* fmt, ...);
	using lua_tobooleanT = bool(IW8::lua_State* L, int idx);
	using lua_tointeger32T = std::int64_t(IW8::lua_State* L, int idx);
	using LuaShared_PCallT = bool(IW8::lua_State* luaVM, int nargs, int nresults);
	using SV_Cmd_ArgvT = const char*(int argIndex);
}
