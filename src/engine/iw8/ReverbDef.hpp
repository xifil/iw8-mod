#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class ReverbDef {
	public:
		std::uint32_t m_ID;			// 0x0000
		std::uint32_t m_RoomTypeID;	// 0x0004
		char m_RoomType[0x40];		// 0x0008
		float m_DryLevel;			// 0x0048
		float m_WetLevel;			// 0x004C
		float m_FadeTime;			// 0x0050
	};
	ENGINE_ASSERT_SZ(ReverbDef, 0x0054);
}
