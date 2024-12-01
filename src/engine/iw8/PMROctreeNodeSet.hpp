#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/PMROctreeNode.hpp"

namespace IW8 {
	class PMROctreeNodeSet {
	public:
		PMROctreeNode m_Node[8];
	};
	ENGINE_ASSERT_SZ(PMROctreeNodeSet, 0x0080);
}
