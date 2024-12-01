#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class FlaggedEdgeMetadata {
	public:
		float m_PackedAdjacentNormal;		// 0x0000
		std::uint16_t m_PackedOpenAngle;	// 0x0004
		std::uint8_t m_Flags[1];			// 0x0006
	private:
		char pad_0007[0x0001];				// 0x0007
	};
	ENGINE_ASSERT_SZ(FlaggedEdgeMetadata, 0x0008);
}
