#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class WeaponOffsetBlendInterpolationType : int {
		WOBIT_LINEAR = 0x0,
		WOBIT_CUBIC_EASE_IN = 0x1,
		WOBIT_CUBIC_EASE_OUT = 0x2,
		WOBIT_QUARTIC_EASE_IN = 0x3,
		WOBIT_QUARTIC_EASE_OUT = 0x4,
		WOBIT_EXPONENTIAL_EASE_IN = 0x5,
		WOBIT_EXPONENTIAL_EASE_OUT = 0x6,
		NUM_WEAPON_OFFSET_BLEND_INTERPOLATION_TYPES = 0x7
	};
}
