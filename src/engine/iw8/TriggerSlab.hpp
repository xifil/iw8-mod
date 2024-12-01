#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	class TriggerSlab {
	public:
		vec3_t m_Dir;		// 0x0000
		float m_MidPoint;	// 0x000C
		float m_HalfSize;	// 0x0010
	};
	ENGINE_ASSERT_SZ(TriggerSlab, 0x0014);
}
