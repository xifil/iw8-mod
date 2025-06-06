#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/PhysicsVFXEventAssetRules.hpp"

namespace IW8 {
	class PhysicsVFXEventAssetSpeedEntry {
	public:
		float m_SpeedThreshold;				// 0x0000
	private:
		char pad_0004[0x0004];				// 0x0004
	public:
		PhysicsVFXEventAssetRules m_Rules;	// 0x0008
	};
	ENGINE_ASSERT_SZ(PhysicsVFXEventAssetSpeedEntry, 0x0018);
}
