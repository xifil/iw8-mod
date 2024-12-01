#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class PhysicsSFXEventAssetCameraDistanceEntry;
	class PhysicsSFXEventAssetCameraDistanceRule {
	public:
		int m_NumEntries;									// 0x0000
	private:
		char pad_0004[0x0004];								// 0x0004
	public:
		PhysicsSFXEventAssetCameraDistanceEntry* m_Entries;	// 0x0008
	};
	ENGINE_ASSERT_SZ(PhysicsSFXEventAssetCameraDistanceRule, 0x0010);
}
