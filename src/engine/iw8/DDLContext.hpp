#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/DDLDef.hpp"
#include "engine/iw8/enums/DDLAccessOp.hpp"

namespace IW8 {
	class DDLContext {
	public:
		void* m_Buff;																				// 0x0000
		int m_Len;																					// 0x0008
	private:
		char pad_000C[0x0004];																		// 0x000C
	public:
		const DDLDef* m_Def;																		// 0x0010
		void(__fastcall* m_AccessCB)(const DDLContext*, std::uint32_t, std::uint32_t, DDLAccessOp);	// 0x0018
		void* m_UserData;																			// 0x0020
		bool m_Obfuscated;																			// 0x0028
	private:
		char pad_0029[0x0003];																		// 0x0029
	public:
		std::uint32_t m_RandomInt;																	// 0x002C
	};
	ENGINE_ASSERT_SZ(DDLContext, 0x0030);
}
