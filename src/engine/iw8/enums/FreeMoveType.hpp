#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class FreeMoveType : int {
		FREEMOVE_NONE = 0x0,
		FREEMOVE_NOCLIP = 0x1,
		FREEMOVE_UFO = 0x2,
		FREEMOVE_COUNT = 0x3
	};
}
