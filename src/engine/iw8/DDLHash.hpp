#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class DDLHash {
	public:
		std::uint32_t m_Hash;	// 0x0000
		int m_Index;			// 0x0004
	};
	ENGINE_ASSERT_SZ(DDLHash, 0x0008);
}
