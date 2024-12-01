#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class ParticleScriptedInputNodeType : int {
		PARTICLE_SCRIPTED_INPUT_NODE_INVALID = -1,
		PARTICLE_SCRIPTED_INPUT_NODE_KVP = 0,
		PARTICLE_SCRIPTED_INPUT_NODE_EMITTER_DISABLE = 1,
		PARTICLE_SCRIPTED_INPUT_NODE_COUNT = 2
	};
}
