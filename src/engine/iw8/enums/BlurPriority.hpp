#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class BlurPriority : int {
		BLUR_PRIORITY_NONE = 0x0,
		BLUR_PRIORITY_SCRIPT = 0x1,
		BLUR_PRIORITY_CODE = 0x2
	};
}
