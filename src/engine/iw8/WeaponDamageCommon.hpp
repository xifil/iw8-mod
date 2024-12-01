#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class WeaponDamageCommon {
	public:
		int m_MinDamage;			// 0x0000
		int m_Mid1Damage;			// 0x0004
		int m_Mid2Damage;			// 0x0008
		int m_Mid3Damage;			// 0x000C
		int m_Damage;				// 0x0010
		float m_MaxDamageRange;		// 0x0014
		float m_Mid1DamageRange;	// 0x0018
		float m_Mid2DamageRange;	// 0x001C
		float m_Mid3DamageRange;	// 0x0020
		float m_MinDamageRange;		// 0x0024
	};
	ENGINE_ASSERT_SZ(WeaponDamageCommon, 0x0028);
}
