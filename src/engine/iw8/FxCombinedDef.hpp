#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ParticleSystemDef.hpp"

namespace IW8 {
	class FxCombinedDef {
	public:
		const ParticleSystemDef* m_ParticleSystemDef;	// 0x0000
	};
	ENGINE_ASSERT_SZ(FxCombinedDef, 0x0008);
}
