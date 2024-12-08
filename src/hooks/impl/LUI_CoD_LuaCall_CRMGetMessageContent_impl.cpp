#include "Main.hpp"
#include "game/game.hpp"
#include "hooks/hooks.hpp"
#include "common/utils/string.hpp"

std::int64_t Hooks::LUI_CoD_LuaCall_CRMGetMessageContent_impl_Detour(IW8::lua_State* luaVM) {
	auto lua_createtable = reinterpret_cast<void (*)(IW8::lua_State*, int, int)>(0x1420833B0_g);
	auto lua_pushnil = reinterpret_cast<void(*)(IW8::lua_State*)>(0x1420840E0_g);
	auto lua_tonumber32 = reinterpret_cast<float(*)(IW8::lua_State*, int)>(0x1419CE9C0_g);
	auto LuaShared_SetTableInt = reinterpret_cast<void(*)(const char*, __int64, IW8::lua_State*)>(0x1419CE4F0_g);
	auto LuaShared_SetTableString = reinterpret_cast<void(*)(const char*, const char*, IW8::lua_State*)>(0x1419CE5A0_g);

	int controllerIndex = (int)lua_tonumber32(luaVM, 1);
	int locationID = (int)lua_tonumber32(luaVM, 2);
	int messageIndex = (int)lua_tonumber32(luaVM, 3);

	printf("[LUI_CoD_LuaCall_CRMGetMessageContent_impl] controller: %d, location: %d, messageIndex: %d\n", controllerIndex, locationID, messageIndex);
	bool pushedData = false;

	nlohmann::json crm = nlohmann::json::parse(MOTD::g_CRMPatched);
	for (auto& [jLocationID, data] : crm.items()) {
		if (strcmp(jLocationID.c_str(), std::to_string(locationID).c_str()) != 0) {
			continue;
		}

		int jMessageIndex = -1;
		for (auto& messageData : data) {
			jMessageIndex++;
			if (jMessageIndex != messageIndex) {
				continue;
			}
			
			lua_createtable(luaVM, 0, 0);
			g_Pointers->m_LUI_BeginTable("message", luaVM);
			for (auto& [key, val] : messageData.items()) {
				if (val.is_string()) {
					LuaShared_SetTableString(key.c_str(), utils::string::replace(val.get<std::string>(), "\\n", "\n").c_str(), luaVM);
				}
				else if (val.is_number()) {
					LuaShared_SetTableInt(key.c_str(), val.get<std::int64_t>(), luaVM);
				}
			}
			g_Pointers->m_LUI_EndTable(luaVM);

			pushedData = true;
			break;
		}
	}

	if (!pushedData) {
		lua_pushnil(luaVM);
	}
	return 1;
}
