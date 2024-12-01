#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/BallisticInfoCalculated.hpp"

namespace IW8 {
	class BallisticInfo {
	public:
		float m_MuzzleVelocity;					// 0x0000
		float m_BallisticCoefficient;			// 0x0004
		float m_Diameter;						// 0x0008
		float m_Mass;							// 0x000C
		float m_GravityFactor;					// 0x0010
		float m_ZeroingDistance;				// 0x0014
		BallisticInfoCalculated* m_Calculated;	// 0x0018
		bool m_EnableBallisticTrajectory;		// 0x0020
	private:
		char pad_0021[0x0003];					// 0x0021
	public:
		int m_LifeTimeMs;						// 0x0024
	};
	ENGINE_ASSERT_SZ(BallisticInfo, 0x0028);
}
