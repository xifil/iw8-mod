#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	class Bounds {
	public:
		vec3_t m_MidPoint;	// 0x0000
		vec3_t m_HalfSize;	// 0x000C
	};
	ENGINE_ASSERT_SZ(Bounds, 0x0018);
}
