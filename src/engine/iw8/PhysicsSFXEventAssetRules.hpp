#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/PhysicsSFXEventAssetRule.hpp"

namespace IW8 {
	class PhysicsSFXEventAssetRules {
	public:
		int m_NumRules;						// 0x0000
	private:
		char pad_0004[0x0004];				// 0x0004
	public:
		PhysicsSFXEventAssetRule* m_Rules;	// 0x0008
	};
	ENGINE_ASSERT_SZ(PhysicsSFXEventAssetRules, 0x0010);
}
