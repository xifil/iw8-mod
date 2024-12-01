#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class EntHandle {
	public:
		std::uint16_t m_Number;		// 0x0000
		std::uint16_t m_InfoIndex;	// 0x0002
	};
	ENGINE_ASSERT_SZ(EntHandle, 0x0004);
}
