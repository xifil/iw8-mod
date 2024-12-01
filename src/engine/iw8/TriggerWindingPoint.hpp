#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	class TriggerWindingPoint {
	public:
		vec3_t m_Loc;	// 0x0000
	};
	ENGINE_ASSERT_SZ(TriggerWindingPoint, 0x000C);
}
