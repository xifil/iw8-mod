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
					{ "48 89 5C 24 ? 57 48 83 EC ? 48 8B 05 ? ? ? ? 48 33 C4 48 89 44 24 ? F3 41 0F 10 18" },
					SETUP_POINTER(CG_WorldPosToScreenPosReal)
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
				// SV_Cmd_Argv
				{
					{ "E8 ? ? ? ? 4C 8B D0 4C 2B D3", SETUP_MOD(Add(1).Rip()) },
					SETUP_POINTER(SV_Cmd_Argv)
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
				}
			}
		};
	}

	Pointers::Pointers() {
		this->GetPointerList().Apply();
	}
}