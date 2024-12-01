#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class LuaFile {
	public:
		const char* m_Name;				// 0x0000
		int m_Len;						// 0x0008
		std::uint8_t m_StrippingType;	// 0x000C
	private:
		char pad_000D[0x0003];			// 0x000D
	public:
		const std::uint8_t* m_Buffer;	// 0x0010
	};
	ENGINE_ASSERT_SZ(LuaFile, 0x0018);
}
