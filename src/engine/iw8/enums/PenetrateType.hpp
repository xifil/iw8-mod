#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class PenetrateType : int {
		PENETRATE_TYPE_NONE = 0x0,
		PENETRATE_TYPE_SMALL = 0x1,
		PENETRATE_TYPE_MEDIUM = 0x2,
		PENETRATE_TYPE_LARGE = 0x3,
		PENETRATE_TYPE_MAXIMUM = 0x4,
		PENETRATE_TYPE_TABLE_ENTRY_COUNT = 0x4,
		PENETRATE_TYPE_RICOCHET = 0x5,
		PENETRATE_TYPE_COUNT = 0x6
	};
}
