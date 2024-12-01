#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class FullOcclusionDef {
	public:
		std::uint32_t m_ID;			// 0x0000
		std::uint32_t m_PresetName;	// 0x0004
		int m_EntChannelIdx;		// 0x0008
	};
	ENGINE_ASSERT_SZ(FullOcclusionDef, 0x000C);
}
