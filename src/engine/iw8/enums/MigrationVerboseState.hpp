#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class MigrationVerboseState : int {
		MVSTATE_INACTIVE = 0x0,
		MVSTATE_WAITING = 0x1,
		MVSTATE_RATING = 0x2,
		MVSTATE_SENDING = 0x3,
		MVSTATE_MIGRATING = 0x4,
		MVSTATE_COUNT = 0x5
	};
}
