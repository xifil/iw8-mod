#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class ParticleFloatRange {
	public:
		float m_Min;	// 0x0000
		float m_Max;	// 0x0004
	};
	ENGINE_ASSERT_SZ(ParticleFloatRange, 0x0008);
}
