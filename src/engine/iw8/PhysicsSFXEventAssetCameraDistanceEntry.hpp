#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/PhysicsSFXEventAssetRules.hpp"

namespace IW8 {
	class PhysicsSFXEventAssetCameraDistanceEntry {
	public:
		float m_Distance;					// 0x0000
	private:
		char pad_0004[0x0004];				// 0x0004
	public:
		PhysicsSFXEventAssetRules m_Rules;	// 0x0008
	};
	ENGINE_ASSERT_SZ(PhysicsSFXEventAssetCameraDistanceEntry, 0x0018);
}
