#include "Main.hpp"
#include "hooks/hooks.hpp"
#include "common/utils/string.hpp"

std::int64_t Hooks::LUI_CoD_LuaCall_CRMGetMessageContent_impl_Detour(IW8::lua_State* luaVM) {
	auto lua_createtable = reinterpret_cast<void (*)(IW8::lua_State*, int, int)>(0x1420833B0_g);
	auto lua_pushnil = reinterpret_cast<void(*)(IW8::lua_State*)>(0x1420840E0_g);
	auto lua_tonumber32 = reinterpret_cast<float(*)(IW8::lua_State*, int)>(0x1419CE9C0_g);
	auto LuaShared_SetTableInt = reinterpret_cast<void(*)(const char*, __int64, IW8::lua_State*)>(0x1419CE4F0_g);
	auto LuaShared_SetTableString = reinterpret_cast<void(*)(const char*, const char*, IW8::lua_State*)>(0x1419CE5A0_g);
	auto LUI_BeginTable1 = reinterpret_cast<void(*)(const char*, IW8::lua_State*)>(0x1419BCF00_g);
	auto LUI_EndTable = reinterpret_cast<void(*)(IW8::lua_State*)>(0x1419BDAC0_g);

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
			LUI_BeginTable1("message", luaVM);
			for (auto& [key, val] : messageData.items()) {
				if (val.is_string()) {
					LuaShared_SetTableString(key.c_str(), utils::string::replace(val.get<std::string>(), "\\n", "\n").c_str(), luaVM);
				}
				else if (val.is_number()) {
					LuaShared_SetTableInt(key.c_str(), val.get<std::int64_t>(), luaVM);
				}
			}
			LUI_EndTable(luaVM);

			pushedData = true;
			break;
		}
	}

	if (!pushedData) {
		lua_pushnil(luaVM);
	}
	// might move to json in future idk
	/*if (locationID == 1 && messageIndex == 0) {
		lua_createtable(luaVM, 0, 0);
		LUI_BeginTable1("message", luaVM);
		LuaShared_SetTableString("message_id", "1", luaVM);
		LuaShared_SetTableString("title", "^1Welcome to iw8-mod!^7", luaVM);
		LuaShared_SetTableString("content_short", "content_short placeholder", luaVM);
		LuaShared_SetTableString("action", "goto_ingame", luaVM);
		LuaShared_SetTableString("content_long", "This mod is a work-in-progress and should not be demonstrated as a finished product.\n"
			"Any bugs or errors found should be reported to ^4@lifix^7 or ^4@xifil^7 on Discord.\n"
			"\n"
			"^7https://discord.gg/dPzJajt", luaVM);
		LuaShared_SetTableString("layout_type", "0", luaVM);
		
		//LuaShared_SetTableString("popup_image", "mw_store_billboard_bronze_knight", luaVM);
		//LuaShared_SetTableString("image", "mw_store_billboard_bronze_knight", luaVM);
		//LuaShared_SetTableString("action_location", "barracks", luaVM);

		LuaShared_SetTableString("checksum", "12345678", luaVM);
		LuaShared_SetTableInt("location_id", 1, luaVM);
		LuaShared_SetTableInt("message_index", 0, luaVM);
		LUI_EndTable(luaVM);
	}
	else if (locationID == 1 && messageIndex == 1) {
		lua_createtable(luaVM, 0, 0);
		LUI_BeginTable1("message", luaVM);
		LuaShared_SetTableString("message_id", "1", luaVM);
		LuaShared_SetTableString("title", "Credits", luaVM);
		LuaShared_SetTableString("content_short", "^1xifil^7 - lead developer\n"
			"^1ProjectDonetsk^7 - base code\n"
			"^1codUPLOADER^7 - original code author", luaVM);
		LuaShared_SetTableString("action", "goto_ingame", luaVM);
		LuaShared_SetTableString("content_long", "content_long placeholder", luaVM);
		LuaShared_SetTableString("layout_type", "0", luaVM);

		//LuaShared_SetTableString("popup_image", "mw_store_billboard_bronze_knight", luaVM);
		//LuaShared_SetTableString("image", "mw_store_billboard_bronze_knight", luaVM);
		//LuaShared_SetTableString("action_location", "barracks", luaVM);

		LuaShared_SetTableString("checksum", "12345679", luaVM);
		LuaShared_SetTableInt("location_id", 1, luaVM);
		LuaShared_SetTableInt("message_index", 1, luaVM);
		LUI_EndTable(luaVM);
	}
	else {
		lua_pushnil(luaVM);
	}*/
	return 1;
}
