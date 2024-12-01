#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class UserCommandStateFlags : int {
		NONE = 0x0,
		HALF = 0x1,
		HALF_HALF = 0x2,
		LONG = 0x3,
		LONG_LONG = 0x4,
		MAX_INT = 0x5,
		SIZE_T = 0x6,
		PTRDIFF = 0x7,
		LONG_DOUBLE = 0x8
	};
}
