#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class ReloadType : int {
		RELOAD_TYPE_NORMAL = 0x0,
		RELOAD_TYPE_SEGMENTED = 0x1,
		RELOAD_TYPE_MULTIPLE_BULLET = 0x2,
		RELOAD_TYPE_MULTIPLE_PERCENTAGE = 0x3,
		RELOAD_TYPE_COUNT = 0x4
	};
}
