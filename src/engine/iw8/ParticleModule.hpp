#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/ParticleModuleType.hpp"

namespace IW8 {
	class ParticleModule {
	public:
		ParticleModuleType m_Type;	// 0x0000
	private:
		char pad_0002[0x0002];		// 0x0002
	public:
		unsigned int m_Flags;		// 0x0004
	};
	ENGINE_ASSERT_SZ(ParticleModule, 0x0008);
}
