#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class StanceState : int {
		CL_STANCE_STAND = 0x0,
		CL_STANCE_CROUCH = 0x1,
		CL_STANCE_PRONE = 0x2,
		CL_STANCE_SLIDE = 0x3,
		CL_STANCE_SLIDE_NOHOLD = 0x4
	};
}
