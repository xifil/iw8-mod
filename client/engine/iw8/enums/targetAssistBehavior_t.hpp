#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class targetAssistBehavior_t : int {
		TARGET_ASSISTBEHAVE_DEFAULT = 0x0,
		TARGET_ASSISTBEHAVE_DIRECT_DAMAGE = 0x1,
		TARGET_ASSISTBEHAVE_TARGET_ONLY = 0x2,
		TARGET_ASSISTBEHAVE_BEAM = 0x3,
		TARGET_ASSISTBEHAVE_SMART_PELLET = 0x4,
		TARGET_ASSISTBEHAVE_COUNT = 0x5
	};
}
