#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/WeaponOffsetBlendInterpolationType.hpp"

namespace IW8 {
	class WeaponOffsetCurveDescription {
	public:
		float m_BlendTime;									// 0x0000
		float m_DecayTime;									// 0x0004
		float m_ShotDecayFireTimeFrac;						// 0x0008
		float m_HoldTime;									// 0x000C
		float m_ADSFractionBegin;							// 0x0010
		float m_ADSFractionEnd;								// 0x0014
		WeaponOffsetBlendInterpolationType m_InterpType;	// 0x0018
		WeaponOffsetBlendInterpolationType m_InterpTypeOut;	// 0x001C
	};
	ENGINE_ASSERT_SZ(WeaponOffsetCurveDescription, 0x0020);
}
