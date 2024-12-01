#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/PhysicsVFXEventAssetRules.hpp"

namespace IW8 {
	class PhysicsVFXEventAssetMassEntry {
	public:
		float m_MassThreshold;				// 0x0000
	private:
		char pad_0004[0x0004];				// 0x0004
	public:
		PhysicsVFXEventAssetRules m_Rules;	// 0x0008
	};
	ENGINE_ASSERT_SZ(PhysicsVFXEventAssetMassEntry, 0x0018);
}
