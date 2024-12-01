#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class EdgeAdjacency {
	public:
		std::uint16_t m_Start;		// 0x0000
		std::uint16_t m_End;		// 0x0002
		std::uint32_t m_AdjEdge;	// 0x0004
		std::uint16_t m_AdjStart;	// 0x0008
		std::uint16_t m_AdjEnd;		// 0x000A
	};
	ENGINE_ASSERT_SZ(EdgeAdjacency, 0x000C);
}
