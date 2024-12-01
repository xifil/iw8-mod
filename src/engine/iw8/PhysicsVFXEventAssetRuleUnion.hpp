#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/PhysicsVFXEventAssetAngleRule.hpp"
#include "engine/iw8/PhysicsVFXEventAssetAtmosphereRule.hpp"
#include "engine/iw8/PhysicsVFXEventAssetFrequencyRule.hpp"
#include "engine/iw8/PhysicsVFXEventAssetCameraDistanceRule.hpp"
#include "engine/iw8/PhysicsVFXEventAssetGravityRule.hpp"
#include "engine/iw8/PhysicsVFXEventAssetMassRule.hpp"
#include "engine/iw8/PhysicsVFXEventAssetMaterialRule.hpp"
#include "engine/iw8/PhysicsVFXEventAssetParticleEffectRule.hpp"
#include "engine/iw8/PhysicsVFXEventAssetSpeedRule.hpp"

namespace IW8 {
	union PhysicsVFXEventAssetRuleUnion {
		PhysicsVFXEventAssetParticleEffectRule m_ParticleEffectRule;	// 0x0000
		PhysicsVFXEventAssetMaterialRule m_MaterialRule;				// 0x0000
		PhysicsVFXEventAssetAngleRule m_AngleRule;						// 0x0000
		PhysicsVFXEventAssetSpeedRule m_SpeedRule;						// 0x0000
		PhysicsVFXEventAssetMassRule m_MassRule;						// 0x0000
		PhysicsVFXEventAssetGravityRule m_GravityRule;					// 0x0000
		PhysicsVFXEventAssetAtmosphereRule m_AtmosphereRule;			// 0x0000
		PhysicsVFXEventAssetCameraDistanceRule m_CameraDistanceRule;	// 0x0000
		PhysicsVFXEventAssetFrequencyRule m_FrequencyRule;				// 0x0000
	};
	ENGINE_ASSERT_SZ(PhysicsVFXEventAssetRuleUnion, 0x0010);
}
