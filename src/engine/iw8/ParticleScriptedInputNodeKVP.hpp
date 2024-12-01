#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ParticleScriptedInputNode.hpp"
#include "engine/iw8/ParticleScriptedInputRecord.hpp"

namespace IW8 {
	class ParticleScriptedInputNodeKVP : public ParticleScriptedInputNode {
	public:
		ParticleScriptedInputRecord m_InputRecord;	// 0x0010
	};
	ENGINE_ASSERT_SZ(ParticleScriptedInputNodeKVP, 0x0020);
}
