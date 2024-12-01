#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class AudioPropagationEdge {
	public:
		std::int16_t m_Neighbor;	// 0x0000
		std::int16_t m_PortalIndex;	// 0x0002
	};
	ENGINE_ASSERT_SZ(AudioPropagationEdge, 0x0004);
}
