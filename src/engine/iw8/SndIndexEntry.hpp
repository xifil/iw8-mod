#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class SndIndexEntry {
	public:
		std::uint16_t m_Value;	// 0x0000
		std::uint16_t m_Next;	// 0x0002
	};
	ENGINE_ASSERT_SZ(SndIndexEntry, 0x0004);
}
