#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class TimescaleEntry {
	public:
		std::uint32_t m_ID;			// 0x0000
		std::uint32_t m_PresetName;	// 0x0004
		int m_EntChannelIdx;		// 0x0008
		float m_Scale;				// 0x000C
	};
	ENGINE_ASSERT_SZ(TimescaleEntry, 0x0010);
}
