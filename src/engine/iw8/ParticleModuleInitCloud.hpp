#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ParticleModule.hpp"

namespace IW8 {
	class ParticleModuleInitCloud : public ParticleModule {
	public:
		unsigned int m_Pad[2];	// 0x0008
	};
	ENGINE_ASSERT_SZ(ParticleModuleInitCloud, 0x0010);
}
