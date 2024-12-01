#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class SpatialPartition_Tree {
	public:
		std::uint8_t* m_Tree;				// 0x0000
		std::uint32_t* m_AlwaysList;		// 0x0008
		std::uint32_t m_TreeSize;			// 0x0010
		std::uint32_t m_AlwaysListLength;	// 0x0014
	};
	ENGINE_ASSERT_SZ(SpatialPartition_Tree, 0x0018);
}
