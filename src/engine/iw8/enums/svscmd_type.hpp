#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class svscmd_type : int {
		SV_CMD_NONE = 0x0,
		SV_CMD_CAN_IGNORE = 0x1,
		SV_CMD_RELIABLE = 0x2
	};
}
