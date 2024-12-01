#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class XNADDR {
	public:
		std::uint8_t m_AddrBuff[0x0054];	// 0x0000
	};
	ENGINE_ASSERT_SZ(XNADDR, 0x0054);
}
