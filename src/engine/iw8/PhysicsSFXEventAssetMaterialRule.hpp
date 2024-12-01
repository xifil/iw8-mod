#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class PhysicsSFXEventAssetMaterialEntry;
	class PhysicsSFXEventAssetMaterialRule {
	public:
		int m_NumEntries;							// 0x0000
	private:
		char pad_0004[0x0004];						// 0x0004
	public:
		PhysicsSFXEventAssetMaterialEntry* entries;	// 0x0008
	};
	ENGINE_ASSERT_SZ(PhysicsSFXEventAssetMaterialRule, 0x0010);
}
