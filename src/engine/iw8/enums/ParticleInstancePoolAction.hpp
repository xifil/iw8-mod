#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class ParticleInstancePoolAction : int {
		PARTICLE_INSTANCE_POOL_ACTION_NO_SPAWN = 0x0,
		PARTICLE_INSTANCE_POOL_ACTION_KILL_OLDEST_AND_SPAWN = 0x1,
		PARTICLE_INSTANCE_POOL_ACTION_COUNT = 0x2
	};
}
