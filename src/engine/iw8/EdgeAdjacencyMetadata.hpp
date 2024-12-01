#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class EdgeAdjacencyMetadata {
	public:
		std::uint32_t m_StartIndex : 23;		// 0x0000
		std::uint32_t m_MountCount : 2;			// 0x0000
		std::uint32_t m_InteractionCount : 2;	// 0x0000
	};
	ENGINE_ASSERT_SZ(EdgeAdjacencyMetadata, 0x0004);
}
