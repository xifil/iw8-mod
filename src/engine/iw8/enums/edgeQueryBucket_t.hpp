#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class edgeQueryBucket_t : std::int8_t {
		MOUNT = 0x0,
		MANTLE = 0x1,
		LADDER_CENTERLINE = 0x2,
		INTERACTION = 0x3,
		EDGE_QUERY_BUCKET_COUNT = 0x4,
		LEGACY_MOUNT = 0x1,
		LEGACY_MANTLE = 0x2,
		LEGACY_LADDER_CENTERLINE = 0x4
	};
}
