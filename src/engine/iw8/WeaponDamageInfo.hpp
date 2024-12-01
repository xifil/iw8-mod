#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/WeaponDamageCommon.hpp"
#include "engine/iw8/enums/AnimDamageType.hpp"

namespace IW8 {
	class WeaponDamageInfo {
	public:
		WeaponDamageCommon m_DamageData[3];		// 0x0000
		AnimDamageType m_DeathAnimDamageType;	// 0x0078
		float m_TerminateAtRange;				// 0x007C
	};
	ENGINE_ASSERT_SZ(WeaponDamageInfo, 0x0080);
}
