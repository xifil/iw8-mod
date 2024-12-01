#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class guidedMissileType_t : int {
		MISSILE_GUIDANCE_NONE = 0x0,
		MISSILE_GUIDANCE_SIDEWINDER = 0x1,
		MISSILE_GUIDANCE_HELLFIRE = 0x2,
		MISSILE_GUIDANCE_JAVELIN = 0x3,
		MISSILE_GUIDANCE_ROBOTECH = 0x4,
		MISSILE_GUIDANCE_SOFTLOCKON = 0x5,
		MISSILE_GUIDANCE_COUNT = 0x6
	};
}
