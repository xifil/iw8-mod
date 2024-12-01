#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/Bounds.hpp"

namespace IW8 {
	class TriggerHull {
	public:
		Bounds m_Bounds;			// 0x0000
		int m_Contents;				// 0x0018
		std::uint16_t m_SlabCount;	// 0x001C
		std::uint16_t m_FirstSlab;	// 0x001E
	};
	ENGINE_ASSERT_SZ(TriggerHull, 0x0020);
}
