#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum ParticleModuleInitBeamFlags : int {
		PARTICLE_MODULE_INIT_BEAM_FLAG_TILE = 0x1,
		PARTICLE_MODULE_INIT_BEAM_FLAG_USE_CURVE_POINTS = 0x2,
		PARTICLE_MODULE_INIT_BEAM_FLAG_CAMERA_FACING = 0x4
	};
}
