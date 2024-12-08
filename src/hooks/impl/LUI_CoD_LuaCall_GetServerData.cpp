#include "Main.hpp"
#include "functions.hpp"
#include "game/game.hpp"
#include "hooks/hooks.hpp"
#include "engine/iw8/ClServerInfo.hpp"

std::int64_t Hooks::LUI_CoD_LuaCall_GetServerData_Detour(IW8::lua_State* luaVM) {
	int controller = g_Pointers->m_lua_tointeger32(luaVM, 1);
	int index = g_Pointers->m_lua_tointeger32(luaVM, 2);
	int column = g_Pointers->m_lua_tointeger32(luaVM, 3);

	int numlocalservers = *(int*)(0x14EEB1220_g);
	IW8::ClServerInfo* localServers = (IW8::ClServerInfo*)(0x14EEB1224_g);
	int* indexes = (int*)(0x152C46A8C_g);

	if (index > numlocalservers) {
		printf("[LUI_CoD_LuaCall_GetServerData] index exceeded number of local servers %d/%d\n", index, numlocalservers);
		g_Pointers->m_lua_pushstring(luaVM, "");
		return 1;
	}
	auto data = &localServers[indexes[index]];
	g_Pointers->m_lua_pushstring(luaVM, data->m_MapName);

	return 1;
}
