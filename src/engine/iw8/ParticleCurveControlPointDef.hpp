#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class ParticleCurveControlPointDef {
	public:
		float m_Time;			// 0x0000
		float m_Value;			// 0x0004
		float m_InvTimeDelta;	// 0x0008
		std::uint32_t m_Pad[1];	// 0x000C
	};
	ENGINE_ASSERT_SZ(ParticleCurveControlPointDef, 0x0010);
}
