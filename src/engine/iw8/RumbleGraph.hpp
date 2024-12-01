#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec2_t.hpp"

namespace IW8 {
	class RumbleGraph {
	public:
		const char* m_Name;			// 0x0000
		vec2_t m_Knots[16];			// 0x0008
		std::uint16_t m_KnotCount;	// 0x0088
	private:
		char pad_008A[0x0006];		// 0x008A
	};
	ENGINE_ASSERT_SZ(RumbleGraph, 0x0090);
}
