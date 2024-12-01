#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/RumbleGraph.hpp"
#include "engine/iw8/vec2_t.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	class AdvancedHipSwaySettings {
	public:
		bool m_Enabled;											// 0x0000
	private:
		char pad_0001[0x0003];									// 0x0001
	public:
		float m_TorsoGoalSmoothSpeed;							// 0x0004
		int m_TorsoGoalViewSmoothDurationMs;					// 0x0008
		vec2_t m_TorsoGoalDeadzoneAdjustSpeed;					// 0x000C
	private:
		char pad_0014[0x0004];									// 0x0014
	public:
		RumbleGraph* m_TorsoGoalViewSpeedToMaxDeadZoneGraph;	// 0x0018
		vec2_t m_TorsoGoalViewSpeedToMaxDeadZoneViewSpeed;		// 0x0020
		vec2_t m_TorsoGoalViewSpeedToMaxDeadZoneMaxDeadZone;	// 0x0028
		vec2_t m_TorsoMass;										// 0x0030
		vec2_t m_TorsoSpring;									// 0x0038
		vec2_t m_TorsoDamper;									// 0x0040
		int m_GunGoalViewSmoothDurationMs;						// 0x0048
	private:
		char pad_004C[0x0004];									// 0x004C
	public:
		RumbleGraph* m_GunGoalViewSpeedToOffsetGraph;			// 0x0050
		vec2_t m_GunGoalViewSpeedToOffsetViewSpeed;				// 0x0058
		vec2_t m_GunGoalViewSpeedToOffsetOffset;				// 0x0060
		vec2_t m_GunMass;										// 0x0068
		vec2_t m_GunSpring;										// 0x0070
		vec2_t m_GunDamper;										// 0x0078
		vec3_t m_GunPivotPoint;									// 0x0080
		float m_GunYawToRollScale;								// 0x008C
		int m_FireDurationMs;									// 0x0090
		int m_FireStartBlendDurationMs;							// 0x0094
		int m_FireFinishBlendDurationMs;						// 0x0098
		float m_FireTorsoGoalSmoothSpeed;						// 0x009C
		float m_FireTorsoDeadZoneScale;							// 0x00A0
		float m_FireTorsoToGunDirScale;							// 0x00A4
	};
	ENGINE_ASSERT_SZ(AdvancedHipSwaySettings, 0x00A8);
}
