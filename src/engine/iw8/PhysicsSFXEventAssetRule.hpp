#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/PhysicsSFXEventAssetRuleUnion.hpp"
#include "engine/iw8/enums/PhysicsSFXEventAssetRuleType.hpp"

namespace IW8 {
	class PhysicsSFXEventAssetRule {
	public:
		PhysicsSFXEventAssetRuleType m_Type;	// 0x0000
	private:
		char pad_0004[0x0004];					// 0x0004
	public:
		PhysicsSFXEventAssetRuleUnion u;		// 0x0008
	};
	ENGINE_ASSERT_SZ(PhysicsSFXEventAssetRule, 0x0028);
}
