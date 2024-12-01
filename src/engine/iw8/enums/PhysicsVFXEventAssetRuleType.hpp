#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class PhysicsVFXEventAssetRuleType : int {
		Types_PhysicsVFXEventRule = 0x0,
		Types_PhysicsVFXEventParticleEffectRule = 0x1,
		Types_PhysicsVFXEventMaterialRule = 0x2,
		Types_PhysicsVFXEventAngleRule = 0x3,
		Types_PhysicsVFXEventSpeedRule = 0x4,
		Types_PhysicsVFXEventMassRule = 0x5,
		Types_PhysicsVFXEventGravityRule = 0x6,
		Types_PhysicsVFXEventAtmosphereRule = 0x7,
		Types_PhysicsVFXEventCameraDistanceRule = 0x8,
		Types_PhysicsVFXEventFrequencyRule = 0x9,
		Types_PhysicsVFXEventRuleCount = 0xA
	};
}
