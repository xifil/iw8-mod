#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class SpatialPartition_Population_Node {
	public:
		std::uint32_t m_SpatialNodeNext;	// 0x0000
	};
	ENGINE_ASSERT_SZ(SpatialPartition_Population_Node, 0x0004);
}
