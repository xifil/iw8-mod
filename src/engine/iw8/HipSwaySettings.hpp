#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/CommonSwaySettings.hpp"

namespace IW8 {
	class HipSwaySettings {
	public:
		CommonSwaySettings m_Common;	// 0x0000
		float m_MaxAngleSteadyAim;		// 0x001C
	};
	ENGINE_ASSERT_SZ(HipSwaySettings, 0x0020);
}
