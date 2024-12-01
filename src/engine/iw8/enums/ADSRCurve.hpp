#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class ADSRCurve : int {
		ADSR_CURVE_LINEAR = 0x0,
		ADSR_CURVE_LOG_FAST = 0x1,
		ADSR_CURVE_LOG_SLOW = 0x2,
		ADSR_CURVE_FLAT_ENDED = 0x3,
		ADSR_CURVE_FLAT_MIDDLE = 0x4
	};
}
