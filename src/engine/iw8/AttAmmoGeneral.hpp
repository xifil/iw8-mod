#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/weapFireType_t.hpp"

namespace IW8 {
	class AttAmmoGeneral {
	public:
		weapFireType_t m_FireType;	// 0x0000
		int m_BurstCount;			// 0x0004
	};
	ENGINE_ASSERT_SZ(AttAmmoGeneral, 0x0008);
}
