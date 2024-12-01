#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/CommonSwaySettings.hpp"

namespace IW8 {
	class AdsSwaySettings {
	public:
		CommonSwaySettings m_Common;		// 0x0000
		float m_SwayTransitionLerpSpeed;	// 0x001C
		float m_ADSSwayScale[3];			// 0x0020
	};
	ENGINE_ASSERT_SZ(AdsSwaySettings, 0x002C);
}
