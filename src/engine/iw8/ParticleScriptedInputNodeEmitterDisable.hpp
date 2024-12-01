#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ParticleScriptedInputNode.hpp"

namespace IW8 {
	class ParticleScriptedInputNodeEmitterDisable : public ParticleScriptedInputNode {
	public:
		// no members
	};
	ENGINE_ASSERT_SZ(ParticleScriptedInputNodeEmitterDisable, 0x0010);
}
