#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class ParticleIntRange {
	public:
		int m_Min;	// 0x0000
		int m_Max;	// 0x0004
	};
	ENGINE_ASSERT_SZ(ParticleIntRange, 0x0008);
}
