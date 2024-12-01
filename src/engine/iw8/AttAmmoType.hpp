#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class AttAmmoType {
	public:
		const char* m_AmmoName;	// 0x0000
	};
	ENGINE_ASSERT_SZ(AttAmmoType, 0x0008);
}
