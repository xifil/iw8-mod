#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/Bounds.hpp"

namespace IW8 {
	class ClientTriggerHull {
	public:
		Bounds m_TriggerSpaceBounds;	// 0x0000
		std::uint16_t m_SlabCount;		// 0x0018
	private:
		char pad_001A[0x0002];			// 0x001A
	public:
		std::uint32_t m_FirstSlab;		// 0x001C
	};
	ENGINE_ASSERT_SZ(ClientTriggerHull, 0x0020);
}
