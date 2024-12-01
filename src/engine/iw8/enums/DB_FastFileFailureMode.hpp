#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class DB_FastFileFailureMode : int {
		REQUIRED = 0x0,
		ALLOW_MISSING = 0x1
	};
}
