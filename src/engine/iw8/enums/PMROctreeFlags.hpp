#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum PMROctreeFlags : std::int8_t {
		EMPTY_NODE = 0x1,
		LEAF_NODE = 0x2,
		ROOT_NODE = 0x4
	};
}
