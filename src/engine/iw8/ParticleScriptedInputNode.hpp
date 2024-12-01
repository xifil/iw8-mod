#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/ParticleScriptedInputNodeType.hpp"

namespace IW8 {
	class ParticleScriptedInputNode {
	public:
		ParticleScriptedInputNodeType m_Type;	// 0x0000
		unsigned int m_Flags;					// 0x0004
		unsigned int m_EmitterIndex;			// 0x0008
		unsigned int m_Pad[1];					// 0x000C
	};
	ENGINE_ASSERT_SZ(ParticleScriptedInputNode, 0x0010);
}
