#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/PhysicsSFXEventAssetRules.hpp"

namespace IW8 {
	class PhysicsSFXEventAsset {
	public:
		const char* m_Name;					// 0x0000
		int m_Priority;						// 0x0008
	private:
		char pad_000C[0x0004];				// 0x000C
	public:
		PhysicsSFXEventAssetRules m_Rules;	// 0x0010
	};
	ENGINE_ASSERT_SZ(PhysicsSFXEventAsset, 0x0020);
}
