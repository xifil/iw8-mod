#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class GrenadeRotationDirection : int {
		GRD_RANDOM = 0x0,
		GRD_CLOCKWISE = 0x1,
		GRD_COUNTERCLOCKWISE = 0x2,
		GRD_COUNT = 0x3
	};
}
