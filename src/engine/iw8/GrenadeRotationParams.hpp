#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/GrenadeRotationDirection.hpp"

namespace IW8 {
	class GrenadeRotationParams {
	public:
		float m_InitialPitch;							// 0x0000
		float m_InitialYaw;								// 0x0004
		float m_InitialRoll;							// 0x0008
		GrenadeRotationDirection m_RotationPitchDir;	// 0x000C
		int m_RotationPitchMin;							// 0x0010
		int m_RotationPitchMax;							// 0x0014
		GrenadeRotationDirection m_RotationYawDir;		// 0x0018
		int m_RotationYawMin;							// 0x001C
		int m_RotationYawMax;							// 0x0020
		GrenadeRotationDirection m_RotationRollDir;		// 0x0024
		int m_RotationRollMin;							// 0x0028
		int m_RotationRollMax;							// 0x002C
		bool m_Rotate;									// 0x0030
	private:
		char pad_0031[0x0003];							// 0x0031
	};
	ENGINE_ASSERT_SZ(GrenadeRotationParams, 0x0034);
}
