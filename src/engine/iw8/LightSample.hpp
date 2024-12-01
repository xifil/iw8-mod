#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class LightSample {
	public:
		bool m_Valid;			// 0x0000
		std::uint8_t m_Value;	// 0x0001
	};
	ENGINE_ASSERT_SZ(LightSample, 0x0002);
}
