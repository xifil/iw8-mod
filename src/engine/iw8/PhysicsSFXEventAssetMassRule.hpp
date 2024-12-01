#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class PhysicsSFXEventAssetMassEntry;
	class PhysicsSFXEventAssetMassRule {
	public:
		int m_NumEntries;							// 0x0000
	private:
		char pad_0004[0x0004];						// 0x0004
	public:
		PhysicsSFXEventAssetMassEntry* m_Entries;	// 0x0008
	};
	ENGINE_ASSERT_SZ(PhysicsSFXEventAssetMassRule, 0x0010);
}
