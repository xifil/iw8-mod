#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/PhysicsVFXEventAssetRule.hpp"

namespace IW8 {
	class PhysicsVFXEventAssetRules {
	public:
		int m_NumRules;						// 0x0000
	private:
		char pad_0004[0x0004];				// 0x0004
	public:
		PhysicsVFXEventAssetRule* m_Rules;	// 0x0008
	};
	ENGINE_ASSERT_SZ(PhysicsVFXEventAssetRules, 0x0010);
}
