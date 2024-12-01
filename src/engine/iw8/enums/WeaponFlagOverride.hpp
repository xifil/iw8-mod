#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class WeaponFlagOverride : int {
		WEAPON_FLAG_OVERRIDE_NO_OVERRIDE = 0x0,
		WEAPON_FLAG_OVERRIDE_FALSE = 0x1,
		WEAPON_FLAG_OVERRIDE_TRUE = 0x2,
		WEAPON_FLAG_OVERRIDE_NUM = 0x3
	};
}
