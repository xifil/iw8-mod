#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class DopplerPreset {
	public:
		char m_Name[0x40];				// 0x0000
		std::uint32_t m_ID;				// 0x0040
		float m_SpeedOfSound;			// 0x0044
		float m_PlayerVelocityScale;	// 0x0048
		float m_MinPitch;				// 0x004C
		float m_MaxPitch;				// 0x0050
		float m_Smoothing;				// 0x0054
	};
	ENGINE_ASSERT_SZ(DopplerPreset, 0x0058);
}
