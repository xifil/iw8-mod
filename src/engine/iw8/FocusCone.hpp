#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class FocusCone {
	public:
		char m_Name[0x40];		// 0x0000
		std::uint32_t m_ID;		// 0x0040
		float m_InnerAngle;		// 0x0044
		float m_OuterAngle;		// 0x0048
		float m_InnerDist;		// 0x004C
		float m_OuterDist;		// 0x0050
		float m_Attenuation;	// 0x0054
	};
	ENGINE_ASSERT_SZ(FocusCone, 0x0058);
}
