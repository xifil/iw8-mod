#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class OmnvarData {
	public:
		std::uint32_t m_TimeModified;	// 0x0000
		OmnvarValue m_Current;			// 0x0004
	};
	ENGINE_ASSERT_SZ(OmnvarData, 0x0008);
}
