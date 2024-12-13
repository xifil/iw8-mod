#include "Main.hpp"
#include "game/game.hpp"
#include "memory/memory.hpp"

#define SETUP_POINTER(name) #name, (void**)&this->m_##name
#define SETUP_MOD(mod) [](Memory::ScannedResult<void> r) { return r.##mod##; }

namespace Game {
	void Pointers::PointerList::Apply() {
		for (PointerCalculator ptr : this->m_Pointers) {
			Memory::ScannedResult<void> res = Memory::SigScan(ptr.m_Calculator.m_Signature, this->m_Module, ptr.m_Name);
			if (res) {
				ptr.m_Calculator.m_Mod(res).Apply(ptr.m_Pointer);
			}
		}
	}

	Pointers::PointerList Pointers::GetPointerList() {
		utils::nt::library game{};
		return {
			game.get_name(), {
				// CG_WorldPosToScreenPosReal
				{
					{ "E8 ? ? ? ? 4C 8D 4D ? 49 8B D6 4C 8D 45 E7", SETUP_MOD(Add(1).Rip()) },
					SETUP_POINTER(CG_WorldPosToScreenPosReal)
				},
				// CL_PlayerData_GetDDLBuffer
				{
					{ "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 48 83 EC ? 48 8B E9 49 63 F8" },
					SETUP_POINTER(CL_PlayerData_GetDDLBuffer)
				},
				// Com_GameInfo_GetGameTypeForInternalName
				{
					{ "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 8B 35 ? ? ? ? 45 33 DB 48 8B E9" },
					SETUP_POINTER(Com_GameInfo_GetGameTypeForInternalName)
				},
				// Com_GameInfo_GetMapInfoForLoadName
				{
					{ "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 48 89 7C 24 ? 41 56 8B 3D ? ? ? ? 45 33 DB 48 8B E9" },
					SETUP_POINTER(Com_GameInfo_GetMapInfoForLoadName)
				},
				// Com_ParseNavStrings
				{
					{ "48 83 EC ? 45 33 D2 41 C7 01" },
					SETUP_POINTER(Com_ParseNavStrings)
				},
				// DB_LoadXFile
				{
					{ "E8 ? ? ? ? 8B F8 44 38 AB", SETUP_MOD(Add(1).Rip()) },
					SETUP_POINTER(DB_LoadXFile)
				},
				// DB_Zones_PerformZoneLoad
				{
					{ "48 89 5C 24 ? 48 89 6C 24 ? 48 89 74 24 ? 57 41 54 41 55 41 56 41 57 48 83 EC ? 45 8B F9 41 0F B6 F0" },
					SETUP_POINTER(DB_Zones_PerformZoneLoad)
				},
				// DDL_GetEnum
				{
					{ "48 89 5C 24 ? 57 48 83 EC ? 48 8B FA 48 8B D9 E8 ? ? ? ? 84 C0 74 ? 4C 8B 4B ? 48 8B CF 41 8B 41 ? 99 41 F7 79 ? 45 8B 49 ? 8B 53 ? 44 8B C0 E8 ? ? ? ? EB ? 33 C0 8B D0 48 8B CB 48 8B 5C 24" },
					SETUP_POINTER(DDL_GetEnum)
				},
				// DDL_GetInt
				{
					{ "48 89 5C 24 ? 57 48 83 EC ? 48 8B FA 48 8B D9 E8 ? ? ? ? 84 C0 74 ? 4C 8B 4B ? 48 8B CF 41 8B 41 ? 99 41 F7 79 ? 45 8B 49 ? 8B 53 ? 44 8B C0 E8 ? ? ? ? EB ? 33 C0 48 8B 4B" },
					SETUP_POINTER(DDL_GetInt)
				},
				// DDL_GetRootState
				{
					{ "33 C0 C7 41 ? ? ? ? ? 48 89 41 ? 89 41 ? 48 8B C1 48 89 51" },
					SETUP_POINTER(DDL_GetRootState)
				},
				// DDL_GetString
				{
					{ "40 55 56 48 83 EC ? 48 8B EA" },
					SETUP_POINTER(DDL_GetString)
				},
				// DDL_MoveToPath
				{
					{ "48 89 74 24 ? 48 89 7C 24 ? 41 56 48 83 EC ? 4D 8B F1 48 8B FA 48 85 C9 74 ? 48 85 D2 74 ? 48 8B 41 ? 48 89 42 ? 48 8B 41 ? 48 89 42 ? 8B 41 ? 89 42 ? 8B 41 ? 89 42 ? 0F B6 01 88 02 48 89 5C 24 ? 49 63 F0 45 85 C0 7E ? 33 DB 48 8B CF E8 ? ? ? ? 4D 8B 04 DE" },
					SETUP_POINTER(DDL_MoveToPath)
				},
				// DDL_SetEnum
				{
					{ "48 89 5C 24 ? 57 48 83 EC ? 48 8B FA 48 8B D9 33 D2 49 8B C8" },
					SETUP_POINTER(DDL_SetEnum)
				},
				// DDL_SetInt
				{
					{ "E9 ? ? ? ? 85 C9 75 ? 8D 42", SETUP_MOD(Add(1).Rip()) },
					SETUP_POINTER(DDL_SetInt)
				},
				// DDL_SetString
				{
					{ "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 49 8B D8 48 8B F2 48 8B F9 E8" },
					SETUP_POINTER(DDL_SetString)
				},
				// Dvar_GetIntSafe
				{
					{ "E8 ? ? ? ? 8B D0 85 C0 75 ? 38 05", SETUP_MOD(Add(1).Rip()) },
					SETUP_POINTER(Dvar_GetIntSafe)
				},
				// Dvar_GetStringSafe
				{
					{ "48 83 EC ? E8 ? ? ? ? 8B C8 E8 ? ? ? ? 48 85 C0 75 ? 48 8D 05 ? ? ? ? 48 83 C4 ? C3 80 78" },
					SETUP_POINTER(Dvar_GetStringSafe)
				},
				// FS_ReadFile
				{
					{ "40 53 57 41 57 48 83 EC ? 48 8B FA" },
					SETUP_POINTER(FS_ReadFile)
				},
				// j_va
				{
					{ "48 89 4C 24 ? 48 89 54 24 ? 4C 89 44 24 ? 4C 89 4C 24 ? 53 48 83 EC ? B9" },
					SETUP_POINTER(j_va)
				},
				// Info_ValueForKey
				{
					{ "48 89 74 24 ? 57 48 83 EC ? 48 8B FA 48 8B F1 48 85 C9 74" },
					SETUP_POINTER(Info_ValueForKey)
				},
				// lua_getfield
				{
					{ "48 89 5C 24 ? 57 48 83 EC ? 4D 8B D0 48 8B D9 E8 ? ? ? ? 48 8B F8 49 C7 C0 ? ? ? ? 90 49 FF C0 43 80 3C 02 ? 75 ? 49 8B D2 48 8B CB E8 ? ? ? ? 48 B9 ? ? ? ? ? ? ? ? 4C 8D 44 24 ? 48 0B C1 48 8B D7 48 8B CB 48 89 44 24 ? E8 ? ? ? ? 48 85 C0" },
					SETUP_POINTER(lua_getfield)
				},
				// lua_pushstring
				{
					{ "48 89 5C 24 ? 57 48 83 EC ? 48 8B FA 48 8B D9 48 85 D2 75 ? 48 8B 41" },
					SETUP_POINTER(lua_pushstring)
				},
				// lua_remove
				{
					{ "4C 8B C1 85 D2 7E ? 8D 42 ? 48 63 D0 48 8B 41 ? 48 8B 49" },
					SETUP_POINTER(lua_remove)
				},
				// lua_toboolean
				{
					{ "48 83 EC ? E8 ? ? ? ? 48 8B 08 33 C0" },
					SETUP_POINTER(lua_toboolean)
				},
				// lua_tointeger32
				{
					{ "E8 ? ? ? ? 8B F0 80 FB", SETUP_MOD(Add(1).Rip()) },
					SETUP_POINTER(lua_tointeger32)
				},
				// LuaShared_PCall
				{
					{ "E8 ? ? ? ? 8B E8 F7 D6", SETUP_MOD(Add(1).Rip()) },
					SETUP_POINTER(LuaShared_PCall)
				},
				// LUI_BeginTable
				{
					{ "E8 ? ? ? ? 85 ED 74 ? BB", SETUP_MOD(Add(1).Rip()) },
					SETUP_POINTER(LUI_BeginTable)
				},
				// LUI_EndTable
				{
					{ "E8 ? ? ? ? 44 3B 76", SETUP_MOD(Add(1).Rip()) },
					SETUP_POINTER(LUI_EndTable)
				},
				// LUI_OpenMenu
				{
					{ "48 89 5C 24 ? 48 89 74 24 ? 57 48 83 EC ? 41 8B F1 41 8B D8" },
					SETUP_POINTER(LUI_OpenMenu)
				},
				// PartyHost_StartPrivateParty
				{
					{ "E8 ? ? ? ? 48 8D 0D ? ? ? ? E8 ? ? ? ? 33 C9 85 C0", SETUP_MOD(Add(1).Rip()) },
					SETUP_POINTER(PartyHost_StartPrivateParty)
				},
				// ProcessScriptFile
				{
					{ "48 89 5C 24 ? 48 89 74 24 ? 55 57 41 54 41 56 41 57 48 8B EC 48 83 EC ? 8B 5A" },
					SETUP_POINTER(ProcessScriptFile)
				},
				// SEH_StringEd_GetString
				{
					{ "E8 ? ? ? ? 48 8B CB 48 8B F8 E8 ? ? ? ? 48 8B D0 48 8B CF E8 ? ? ? ? 4C 8B 05 ? ? ? ? 48 8D 0D ? ? ? ? 48 8B D0 E8 ? ? ? ? 48 8B 0D", SETUP_MOD(Add(1).Rip()) },
					SETUP_POINTER(SEH_StringEd_GetString)
				},
				// SV_Cmd_Argv
				{
					{ "E8 ? ? ? ? 4C 8B D0 4C 2B D3", SETUP_MOD(Add(1).Rip()) },
					SETUP_POINTER(SV_Cmd_Argv)
				},
				// SV_UpdateUserinfo_f
				{
					{ "40 53 48 83 EC ? 48 8B D9 B9 ? ? ? ? E8 ? ? ? ? 48 8D 8B" },
					SETUP_POINTER(SV_UpdateUserinfo_f)
				},
				// Unk_GetBNetClass
				{
					{ "E8 ? ? ? ? 44 38 B8", SETUP_MOD(Add(1).Rip()) },
					SETUP_POINTER(Unk_GetBNetClass)
				},
				// clientUIActives
				{
					{ "48 8D 15 ? ? ? ? 8B 4C 10", SETUP_MOD(Add(3).Rip()) },
					SETUP_POINTER(clientUIActives)
				},
				// cmd_args
				{
					{ "48 63 05 ? ? ? ? 33 C9 41 89 AC 87", SETUP_MOD(Add(3).Rip()) },
					SETUP_POINTER(cmd_args)
				},
				// g_entities
				{
					{ "48 8B 0D ? ? ? ? 8B F2 4C 69 E0", SETUP_MOD(Add(3).Rip()) },
					SETUP_POINTER(g_entities)
				},
				// LUI_luaVM
				{
					{ "4C 8B 05 ? ? ? ? 48 8D 0D ? ? ? ? 48 8B D0 E8 ? ? ? ? BA ? ? ? ? 48 8B CE E8 ? ? ? ? 4D 8D 7F", SETUP_MOD(Add(3).Rip()) },
					SETUP_POINTER(LUI_luaVM)
				},
				// s_luaInFrontend
				{
					{ "88 1D ? ? ? ? E8 ? ? ? ? 48 89 1D ? ? ? ? 88 1D", SETUP_MOD(Add(2).Rip()) },
					SETUP_POINTER(s_luaInFrontend)
				},
				// s_presenceData
				{
					{ "48 8D 05 ? ? ? ? 4C 8D 05 ? ? ? ? 48 39 08 74 ? FF C2 48 05", SETUP_MOD(Add(3).Rip()) },
					SETUP_POINTER(s_presenceData)
				}
			}
		};
	}

	Pointers::Pointers() {
		this->GetPointerList().Apply();
	}
}