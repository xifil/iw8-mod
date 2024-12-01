#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/WeaponEntityNotifyFlags.hpp"

namespace IW8 {
	class WeaponEntityNotify {
	public:
		WeaponEntityNotifyFlags m_Flags;	// 0x0000
		float m_Radius;						// 0x0004
		float m_Height;						// 0x0008
		float m_MinSpeed;					// 0x000C
	};
	ENGINE_ASSERT_SZ(WeaponEntityNotify, 0x0010);
}
