#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class TurnRateCapInfo {
	public:
		float m_MaxPitchSpeed;	// 0x0000
		float m_MaxYawSpeed;	// 0x0004
	};
	ENGINE_ASSERT_SZ(TurnRateCapInfo, 0x0008);
}
