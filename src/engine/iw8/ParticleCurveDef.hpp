#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ParticleCurveControlPointDef.hpp"

namespace IW8 {
	class ParticleCurveDef {
	public:
		ParticleCurveControlPointDef* m_ControlPoints;	// 0x0000
		int m_NumControlPoints;							// 0x0008
		float m_Scale;									// 0x000C
	};
	ENGINE_ASSERT_SZ(ParticleCurveDef, 0x0010);
}
