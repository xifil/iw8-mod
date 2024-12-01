#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class SpeakerMap {
	public:
		char m_Name[0x40];			// 0x0000
		std::uint32_t m_ID;			// 0x0040
		float m_MonoToStereo[2];	// 0x0044
		float m_StereoToStereo[4];	// 0x004C
		float m_MonoTo51[6];		// 0x005C
		float m_StereoTo51[12];		// 0x0074
		float m_MonoTo71[8];		// 0x00A4
		float m_StereoTo71[16];		// 0x00C4
		float m_MonoTo7144[16];		// 0x0104
		float m_StereoTo7144[32];	// 0x0144
	};
	ENGINE_ASSERT_SZ(SpeakerMap, 0x01C4);
}
