#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class weapProjExposion_t : int {
		WEAPPROJEXP_GRENADE = 0x0,
		WEAPPROJEXP_ROCKET = 0x1,
		WEAPPROJEXP_FLASHBANG = 0x2,
		WEAPPROJEXP_MOLOTOV = 0x3,
		WEAPPROJEXP_NONE = 0x4,
		WEAPPROJEXP_DUD = 0x5,
		WEAPPROJEXP_SMOKE = 0x6,
		WEAPPROJEXP_HEAVY = 0x7,
		WEAPPROJEXP_NUM = 0x8
	};
}
