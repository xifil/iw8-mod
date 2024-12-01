#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class OcclusionShape {
	public:
		char m_Name[0x40];			// 0x0000
		std::uint32_t m_ID;			// 0x0040
		float m_InnerAngleVolume;	// 0x0044
		float m_OuterAngleVolume;	// 0x0048
		float m_OccludedVolume;		// 0x004C
		float m_InnerAngleLPF;		// 0x0050
		float m_OuterAngleLPF;		// 0x0054
		float m_OccludedLPF;		// 0x0058
		float m_YawOffsetAngle;		// 0x005C
		float m_PitchOffsetAngle;	// 0x0060
	};
	ENGINE_ASSERT_SZ(OcclusionShape, 0x0064);
}
