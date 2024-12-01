#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class PhysicsAssetSimulationCategory : int {
		PhysicsAssetSimulationCategory_Static = 0x0,
		PhysicsAssetSimulationCategory_KeyframedEntity = 0x1,
		PhysicsAssetSimulationCategory_KeyframedAnimated = 0x2,
		PhysicsAssetSimulationCategory_KeyframedBoneOffset = 0x3,
		PhysicsAssetSimulationCategory_DynamicEntity = 0x4,
		PhysicsAssetSimulationCategory_DynamicDebris = 0x5,
		PhysicsAssetSimulationCategory_Ragdoll = 0x6,
		PhysicsAssetSimulationCategory_VehicleChassis = 0x7,
		PhysicsAssetSimulationCategory_VehicleChassisNoForce = 0x8,
		PhysicsAssetSimulationCategory_Custom = 0x9,
		PhysicsAssetSimulationCategory_NumCategories = 0xA
	};
}
