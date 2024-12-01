#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/ParticleScriptedInputKey.hpp"

namespace IW8 {
	class ParticleScriptedInputRecord {
	public:
		ParticleScriptedInputKey m_Key;	// 0x0000
		bool m_Dirty;					// 0x0004
		bool m_Value;					// 0x0005
	private:
		char pad_0006[0x0002];			// 0x0006
	public:
		unsigned int m_Pad[2];			// 0x0008
	};
	ENGINE_ASSERT_SZ(ParticleScriptedInputRecord, 0x0010);
}
