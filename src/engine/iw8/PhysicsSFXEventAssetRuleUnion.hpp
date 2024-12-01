#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/PhysicsSFXEventAssetAngleRule.hpp"
#include "engine/iw8/PhysicsSFXEventAssetAtmosphereRule.hpp"
#include "engine/iw8/PhysicsSFXEventAssetCameraDistanceRule.hpp"
#include "engine/iw8/PhysicsSFXEventAssetFrequencyRule.hpp"
#include "engine/iw8/PhysicsSFXEventAssetGravityRule.hpp"
#include "engine/iw8/PhysicsSFXEventAssetMassRule.hpp"
#include "engine/iw8/PhysicsSFXEventAssetMaterialRule.hpp"
#include "engine/iw8/PhysicsSFXEventAssetSoundRule.hpp"
#include "engine/iw8/PhysicsSFXEventAssetSpeedRule.hpp"

namespace IW8 {
	union PhysicsSFXEventAssetRuleUnion {
		PhysicsSFXEventAssetSoundRule m_SoundRule;						// 0x0000
		PhysicsSFXEventAssetMaterialRule m_MaterialRule;				// 0x0000
		PhysicsSFXEventAssetAngleRule m_AngleRule;						// 0x0000
		PhysicsSFXEventAssetSpeedRule m_SpeedRule;						// 0x0000
		PhysicsSFXEventAssetMassRule m_MassRule;						// 0x0000
		PhysicsSFXEventAssetGravityRule m_GravityRule;					// 0x0000
		PhysicsSFXEventAssetAtmosphereRule m_AtmosphereRule;			// 0x0000
		PhysicsSFXEventAssetCameraDistanceRule m_CameraDistanceRule;	// 0x0000
		PhysicsSFXEventAssetFrequencyRule m_FrequencyRule;				// 0x0000
	};
	ENGINE_ASSERT_SZ(PhysicsSFXEventAssetRuleUnion, 0x0020);
}
