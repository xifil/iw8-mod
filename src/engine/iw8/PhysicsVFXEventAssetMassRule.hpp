#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class PhysicsVFXEventAssetMassEntry;
	class PhysicsVFXEventAssetMassRule {
	public:
		int m_NumEntries;							// 0x0000
	private:
		char pad_0004[0x0004];						// 0x0004
	public:
		PhysicsVFXEventAssetMassEntry* m_Entries;	// 0x0008
	};
	ENGINE_ASSERT_SZ(PhysicsVFXEventAssetMassRule, 0x0010);
}
