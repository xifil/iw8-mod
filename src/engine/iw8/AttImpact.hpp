#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class AttImpact {
	public:
		int m_VFXImpactType;	// 0x0000
	};
	ENGINE_ASSERT_SZ(AttImpact, 0x0004);
}
