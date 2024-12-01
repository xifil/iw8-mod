#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/PhysicsAssetUsageCounter.hpp"
#include "engine/iw8/PhysicsSFXEventAsset.hpp"
#include "engine/iw8/PhysicsVFXEventAsset.hpp"
#include "engine/iw8/enums/PhysicsAssetSimulationCategory.hpp"
#include "engine/iw8/enums/PhysicsAssetUseCategory.hpp"

namespace IW8 {
	struct PhysicsAsset {
	public:
		const char* m_Name;										// 0x0000
		char* m_HavokData;										// 0x0008
		std::uint32_t m_HavokDataSize;							// 0x0010
		PhysicsAssetUseCategory m_UseCategory;					// 0x0014
		int m_NumRigidBodies;									// 0x0018
		int m_NumConstraints;									// 0x001C
		PhysicsAssetSimulationCategory* m_SimulationCategories;	// 0x0020
		std::uint32_t* m_BodyContents;							// 0x0028
		int m_NumSFXEventAssets;								// 0x0030
		int m_NumVFXEventAssets;								// 0x0034
		PhysicsSFXEventAsset** m_SFXEventAssets;				// 0x0038
		PhysicsVFXEventAsset** m_VFXEventAssets;				// 0x0040
		PhysicsAssetUsageCounter m_UsageCounter;				// 0x0048
		bool m_ContainsDynamicBodies;							// 0x0054
	private:
		char pad_0055[0x0003];									// 0x0055
	};
	ENGINE_ASSERT_SZ(PhysicsAsset, 0x0058);
}
