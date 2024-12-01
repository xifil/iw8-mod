#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ParticleScriptedInputNode.hpp"
#include "engine/iw8/ParticleScriptedInputNodeEmitterDisable.hpp"
#include "engine/iw8/ParticleScriptedInputNodeKVP.hpp"

namespace IW8 {
	union ParticleScriptedInputNodeDef {
		ParticleScriptedInputNode m_NodeBase;						// 0x0000
		ParticleScriptedInputNodeKVP m_KVP;							// 0x0000
		ParticleScriptedInputNodeEmitterDisable m_EmitterDisable;	// 0x0000
	};
	ENGINE_ASSERT_SZ(ParticleScriptedInputNodeDef, 0x0020);
}
