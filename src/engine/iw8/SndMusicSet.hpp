#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/SndMusicState.hpp"

namespace IW8 {
	class SndMusicSet {
	public:
		char m_Name[0x40];			// 0x0000
		std::uint32_t m_ID;			// 0x0040
		std::uint32_t m_StateCount;	// 0x0044
		SndMusicState* m_States;	// 0x0048
	};
	ENGINE_ASSERT_SZ(SndMusicSet, 0x0050);
}
