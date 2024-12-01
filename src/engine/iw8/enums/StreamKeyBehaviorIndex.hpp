#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class StreamKeyBehaviorIndex : std::int8_t {
		SKBI_NONE = 0x0,
		SKBI_TERRAIN = 0x1,
		SKBI_SOUND = 0x2,
		SKBI_STREAMTREE = 0x3,
		SKBI_CLUTTER_BITMASK = 0x4,
		SKBI_COUNT = 0x5
	};
}
