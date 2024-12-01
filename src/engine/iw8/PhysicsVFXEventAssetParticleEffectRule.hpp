#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class PhysicsVFXEventAssetParticleEffectRule {
	public:
		char* m_HitParticleEffectAlias;		// 0x0000
		char* m_ScrapeParticleEffectAlias;	// 0x0008
	};
	ENGINE_ASSERT_SZ(PhysicsVFXEventAssetParticleEffectRule, 0x0010);
}
