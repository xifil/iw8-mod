#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/PhysicsVFXEventAssetRuleUnion.hpp"
#include "engine/iw8/enums/PhysicsVFXEventAssetRuleType.hpp"

namespace IW8 {
	class PhysicsVFXEventAssetRule {
	public:
		PhysicsVFXEventAssetRuleType m_Type;	// 0x0000
	private:
		char pad_0004[0x0004];					// 0x0004
	public:
		PhysicsVFXEventAssetRuleUnion u;		// 0x0008
	};
	ENGINE_ASSERT_SZ(PhysicsVFXEventAssetRule, 0x0018);
}
