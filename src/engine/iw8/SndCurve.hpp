#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec2_t.hpp"

namespace IW8 {
	class SndCurve {
	public:
		char m_Name[0x40];		// 0x0000
		std::uint32_t m_ID;		// 0x0040
		int m_NumPoints;		// 0x0044
		vec2_t m_Points[0x10];	// 0x0048
	};
	ENGINE_ASSERT_SZ(SndCurve, 0x00C8);
}
