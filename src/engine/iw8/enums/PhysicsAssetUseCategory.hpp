#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class PhysicsAssetUseCategory : int {
		PhysicsAssetUseCategory_StaticModel = 0x0,
		PhysicsAssetUseCategory_CommonEntity = 0x1,
		PhysicsAssetUseCategory_Vehicle = 0x2,
		PhysicsAssetUseCategory_Dynent = 0x3,
		PhysicsAssetUseCategory_EntityOrDynent = 0x4,
		PhysicsAssetUseCategory_Ragdoll = 0x5,
		PhysicsAssetUseCategory_Particle = 0x6,
		PhysicsAssetUseCategory_Custom = 0x7,
		PhysicsAssetUseCategory_NumCategories = 0x8
	};
}
