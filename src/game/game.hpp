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
		Functions::Dvar_GetStringSafeT* m_Dvar_GetStringSafe{};
		Functions::FS_ReadFileT* m_FS_ReadFile{};
		Functions::Info_ValueForKeyT* m_Info_ValueForKey{};
		Functions::j_vaT* m_j_va{};
		Functions::lua_tobooleanT* m_lua_toboolean{};
		Functions::lua_tointeger32T* m_lua_tointeger32{};
		Functions::LuaShared_PCallT* m_LuaShared_PCall{};
		Functions::SV_Cmd_ArgvT* m_SV_Cmd_Argv{};

		IW8::clientUIActive_t* m_clientUIActives{};
		IW8::CmdArgs* m_cmd_args{};
		IW8::gentity_s** m_g_entities{};
		IW8::lua_State** m_LUI_luaVM{};
	};
}
inline std::unique_ptr<Game::Pointers> g_Pointers{};
