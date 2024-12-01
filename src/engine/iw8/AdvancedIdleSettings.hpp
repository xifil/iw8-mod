#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class AdvancedIdleSettings {
	public:
		bool m_UseAdvancedIdleSettings;						// 0x0000
		bool m_UseRandomPointsAlgorithm;					// 0x0001
	private:
		char pad_0002[0x0002];								// 0x0002
	public:
		float m_BreathGaspScaleOverride;					// 0x0004
		float m_IdleSwaySetting1_HipBulletDirScale;			// 0x0008
		float m_IdleSwaySetting1_HipIdleSpeed;				// 0x000C
		float m_IdleSwaySetting1_HipWeaponMagnitudeX;		// 0x0010
		float m_IdleSwaySetting1_HipWeaponMagnitudeY;		// 0x0014
		float m_IdleSwaySetting1_HipWeaponMagnitudeZ;		// 0x0018
		float m_IdleSwaySetting1_HipWeaponMagnitudeF;		// 0x001C
		float m_IdleSwaySetting1_HipWeaponRotationOffset;	// 0x0020
		float m_IdleSwaySetting1_HipViewMagnitudeX;			// 0x0024
		float m_IdleSwaySetting1_HipViewMagnitudeY;			// 0x0028
		float m_IdleSwaySetting1_ADSBulletDirScale;			// 0x002C
		float m_IdleSwaySetting1_ADSIdleSpeed;				// 0x0030
		float m_IdleSwaySetting1_ADSWeaponMagnitudeX;		// 0x0034
		float m_IdleSwaySetting1_ADSWeaponMagnitudeY;		// 0x0038
		float m_IdleSwaySetting1_ADSWeaponMagnitudeZ;		// 0x003C
		float m_IdleSwaySetting1_ADSWeaponMagnitudeF;		// 0x0040
		float m_IdleSwaySetting1_ADSWeaponRotationOffset;	// 0x0044
		float m_IdleSwaySetting1_ADSViewMagnitudeX;			// 0x0048
		float m_IdleSwaySetting1_ADSViewMagnitudeY;			// 0x004C
		float m_IdleSwaySetting2_HipBulletDirScale;			// 0x0050
		float m_IdleSwaySetting2_HipIdleSpeed;				// 0x0054
		float m_IdleSwaySetting2_HipWeaponMagnitudeX;		// 0x0058
		float m_IdleSwaySetting2_HipWeaponMagnitudeY;		// 0x005C
		float m_IdleSwaySetting2_HipWeaponMagnitudeZ;		// 0x0060
		float m_IdleSwaySetting2_HipWeaponMagnitudeF;		// 0x0064
		float m_IdleSwaySetting2_HipWeaponRotationOffset;	// 0x0068
		float m_IdleSwaySetting2_HipViewMagnitudeX;			// 0x006C
		float m_IdleSwaySetting2_HipViewMagnitudeY;			// 0x0070
		float m_IdleSwaySetting2_ADSBulletDirScale;			// 0x0074
		float m_IdleSwaySetting2_ADSIdleSpeed;				// 0x0078
		float m_IdleSwaySetting2_ADSWeaponMagnitudeX;		// 0x007C
		float m_IdleSwaySetting2_ADSWeaponMagnitudeY;		// 0x0080
		float m_IdleSwaySetting2_ADSWeaponMagnitudeZ;		// 0x0084
		float m_IdleSwaySetting2_ADSWeaponMagnitudeF;		// 0x0088
		float m_IdleSwaySetting2_ADSWeaponRotationOffset;	// 0x008C
		float m_IdleSwaySetting2_ADSViewMagnitudeX;			// 0x0090
		float m_IdleSwaySetting2_ADSViewMagnitudeY;			// 0x0094
	};
	ENGINE_ASSERT_SZ(AdvancedIdleSettings, 0x0098);
}
