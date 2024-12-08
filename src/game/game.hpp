#pragma once
#include "Main.hpp"
#include "game/function_types.hpp"
#include "memory/scanned_result.hpp"

namespace Game {
	class Pointers {
	public:
		class SignatureCalculator {
		public:
			using Res = Memory::ScannedResult<void>;

			SignatureCalculator(const std::string& signature, std::function<Res(Res)> mod)
				: m_Signature(signature)
				, m_Mod(std::move(mod))
			{}

			SignatureCalculator(const std::string& signature)
				: SignatureCalculator(signature, [](Res r) { return r; })
			{}

			std::string m_Signature;
			std::function<Res(Res)> m_Mod;
		};

		class PointerCalculator {
		public:
			PointerCalculator(SignatureCalculator calculator, std::string name, void** pointer)
				: m_Calculator(calculator)
				, m_Name(name)
				, m_Pointer(pointer)
			{}

			SignatureCalculator m_Calculator;
			std::string m_Name;
			void** m_Pointer;
		};

		class PointerList {
		public:
			PointerList(std::string _module, std::vector<PointerCalculator> pointers) {
				this->m_Module = _module;
				this->m_Pointers = pointers;
			}

			std::string m_Module{};
			std::vector<PointerCalculator> m_Pointers{};

			void Apply();
		};

		explicit Pointers();
		PointerList GetPointerList();

		Functions::CG_WorldPosToScreenPosRealT* m_CG_WorldPosToScreenPosReal{};
		Functions::CL_PlayerData_GetDDLBufferT* m_CL_PlayerData_GetDDLBuffer{};
		Functions::Com_GameInfo_GetGameTypeForInternalNameT* m_Com_GameInfo_GetGameTypeForInternalName{};
		Functions::Com_GameInfo_GetMapInfoForLoadNameT* m_Com_GameInfo_GetMapInfoForLoadName{};
		Functions::Com_ParseNavStringsT* m_Com_ParseNavStrings{};
		Functions::DB_Zones_PerformZoneLoadT* m_DB_Zones_PerformZoneLoad{};
		Functions::DDL_GetEnumT* m_DDL_GetEnum{};
		Functions::DDL_GetIntT* m_DDL_GetInt{};
		Functions::DDL_GetRootStateT* m_DDL_GetRootState{};
		Functions::DDL_GetStringT* m_DDL_GetString{};
		Functions::DDL_MoveToPathT* m_DDL_MoveToPath{};
		Functions::DDL_SetEnumT* m_DDL_SetEnum{};
		Functions::DDL_SetIntT* m_DDL_SetInt{};
		Functions::DDL_SetStringT* m_DDL_SetString{};
		Functions::Dvar_GetIntSafeT* m_Dvar_GetIntSafe{};
		Functions::Dvar_GetStringSafeT* m_Dvar_GetStringSafe{};
		Functions::FS_ReadFileT* m_FS_ReadFile{};
		Functions::Info_ValueForKeyT* m_Info_ValueForKey{};
		Functions::j_vaT* m_j_va{};
		Functions::lua_getfieldT* m_lua_getfield{};
		Functions::lua_pushstringT* m_lua_pushstring{};
		Functions::lua_removeT* m_lua_remove{};
		Functions::lua_tobooleanT* m_lua_toboolean{};
		Functions::lua_tointeger32T* m_lua_tointeger32{};
		Functions::LuaShared_PCallT* m_LuaShared_PCall{};
		Functions::LUI_BeginTableT* m_LUI_BeginTable{};
		Functions::LUI_EndTableT* m_LUI_EndTable{};
		Functions::LUI_OpenMenuT* m_LUI_OpenMenu{};
		Functions::PartyHost_StartPrivatePartyT* m_PartyHost_StartPrivateParty{};
		Functions::ProcessScriptFileT* m_ProcessScriptFile{};
		Functions::SEH_StringEd_GetStringT* m_SEH_StringEd_GetString{};
		Functions::SV_Cmd_ArgvT* m_SV_Cmd_Argv{};
		Functions::SV_UpdateUserinfo_fT* m_SV_UpdateUserinfo_f{};

		IW8::clientUIActive_t* m_clientUIActives{};
		IW8::CmdArgs* m_cmd_args{};
		IW8::gentity_s** m_g_entities{};
		IW8::lua_State** m_LUI_luaVM{};
		bool* m_s_luaInFrontend{};
	};
}
inline std::unique_ptr<Game::Pointers> g_Pointers{};
