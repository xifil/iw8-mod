#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class WeapDetonateType : int {
		DETONATE_TYPE_NONE = 0x0,
		DETONATE_TYPE_GESTURE = 0x1,
		DETONATE_TYPE_VIEWMODEL = 0x2,
		DETONATE_TYPE_COUNT = 0x3
	};
}
