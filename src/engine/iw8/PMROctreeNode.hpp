#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/PMROctreeFlags.hpp"

namespace IW8 {
	class PMROctreeNode {
	public:
		std::uint16_t m_UniformGridIndex[3];	// 0x0000
		std::uint8_t m_Depth;					// 0x0006
		PMROctreeFlags m_Flags;					// 0x0007
		union {
			std::uint32_t m_ParentNodeIndex;	// 0x0008
			std::uint32_t m_QEdgeTableIndex;	// 0x0008
		};
		union {
			std::uint32_t m_ChildNodeSetIndex;	// 0x000C
			std::uint32_t m_QEdgeTableCount;	// 0x000C
		};
	};
	ENGINE_ASSERT_SZ(PMROctreeNode, 0x0010);
}
