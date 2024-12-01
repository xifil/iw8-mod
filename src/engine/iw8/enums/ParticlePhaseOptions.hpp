#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class ParticlePhaseOptions : int {
		PARTICLE_PHASE_OPTION_PHASE_NEVER = 0x0,
		PARTICLE_PHASE_OPTION_PHASE_ONLY = 0x1,
		PARTICLE_PHASE_OPTION_ALWAYS = 0x2,
		PARTICLE_PHASE_OPTION_COUNT = 0x3
	};
}
