#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/PhysicsSFXEventAssetRules.hpp"

namespace IW8 {
	class PhysicsSFXEventAssetFrequencyEntry {
	public:
		int m_MaxEvents;					// 0x0000
	private:
		char pad_0004[0x0004];				// 0x0004
	public:
		PhysicsSFXEventAssetRules m_Rules;	// 0x0008
	};
	ENGINE_ASSERT_SZ(PhysicsSFXEventAssetFrequencyEntry, 0x0018);
}
