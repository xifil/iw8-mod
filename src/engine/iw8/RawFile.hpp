#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class RawFile {
	public:
		const char* m_Name;				// 0x0000
		std::uint32_t m_CompressedLen;	// 0x0008
		std::uint32_t m_Len;			// 0x000C
		const char* m_Buffer;			// 0x0010
	};
	ENGINE_ASSERT_SZ(RawFile, 0x0018);
}
