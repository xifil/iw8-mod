#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class CommonSwaySettings {
	public:
		float m_MaxAngle;		// 0x0000
		float m_LerpSpeed;		// 0x0004
		float m_PitchScale;		// 0x0008
		float m_YawScale;		// 0x000C
		float m_HorizScale;		// 0x0010
		float m_VertScale;		// 0x0014
		float m_GunAngleScale;	// 0x0018
	};
	ENGINE_ASSERT_SZ(CommonSwaySettings, 0x001C);
}
