#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/ADSRCurve.hpp"

namespace IW8 {
	class ADSRSetting {
	public:
		const char* m_Name;			// 0x0000
		std::uint32_t m_ID;			// 0x0008
		float m_AttackLength;		// 0x000C
		ADSRCurve m_AttackCurve;	// 0x0010
		float m_DecayLength;		// 0x0014
		ADSRCurve m_DecayCurve;		// 0x0018
		float m_ReleaseLength;		// 0x001C
		ADSRCurve m_ReleaseCurve;	// 0x0020
		float m_SustainLevel;		// 0x0024
		float m_SustainLength;		// 0x0028
	private:
		char pad_002C[0x0004];		// 0x002C
	};
	ENGINE_ASSERT_SZ(ADSRSetting, 0x0030);
}
