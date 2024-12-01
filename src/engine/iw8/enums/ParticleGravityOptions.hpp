#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class ParticleGravityOptions : int {
		PARTICLE_GRAVITY_OPTION_NONE = 0x0,
		PARTICLE_GRAVITY_OPTION_GRAVITY_ONLY = 0x1,
		PARTICLE_GRAVITY_OPTION_GRAVITY_NEVER = 0x2,
		PARTICLE_GRAVITY_OPTION_COUNT = 0x3
	};
}
