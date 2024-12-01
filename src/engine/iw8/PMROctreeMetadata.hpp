#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/float4.hpp"
#include "engine/iw8/PMROctreeNode.hpp"
#include "engine/iw8/enums/edgeQueryBucket_t.hpp"

namespace IW8 {
	class PMROctreeMetadata {
	public:
		float4 m_NodeHalfWidth[16];			// 0x0000
		float4 m_MinExtent;					// 0x0100
		PMROctreeNode m_RootNode;			// 0x0110
		std::uint32_t m_NodeSetCount;		// 0x0120
		float m_NodeBoundingRadiusSq[16];	// 0x0124
		edgeQueryBucket_t m_EdgeBucket;		// 0x0164
		std::uint8_t m_Flags[1];			// 0x0165
		char m_Pad[10];						// 0x0166
	};
	ENGINE_ASSERT_SZ(PMROctreeMetadata, 0x0170);
}
