#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/PhysicsVFXEventAssetRules.hpp"

namespace IW8 {
	class PhysicsVFXEventAssetGravityEntry {
	public:
		bool m_Gravity;						// 0x0000
	private:
		char pad_0001[0x0007];				// 0x0001
	public:
		PhysicsVFXEventAssetRules m_Rules;	// 0x0008
	};
	ENGINE_ASSERT_SZ(PhysicsVFXEventAssetGravityEntry, 0x0018);
}
