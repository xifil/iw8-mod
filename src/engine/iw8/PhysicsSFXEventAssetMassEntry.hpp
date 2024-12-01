#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/PhysicsSFXEventAssetRules.hpp"

namespace IW8 {
	class PhysicsSFXEventAssetMassEntry {
	public:
		float m_MassThreshold;				// 0x0000
		float m_HitSoundVolumeModifierMin;	// 0x0004
		float m_HitSoundVolumeModifierMax;	// 0x0008
		float m_HitSoundPitchModifierMin;	// 0x000C
		float m_HitSoundPitchModifierMax;	// 0x0010
	private:
		char pad_0014[0x0004];				// 0x0014
	public:
		PhysicsSFXEventAssetRules m_Rules;	// 0x0018
	};
	ENGINE_ASSERT_SZ(PhysicsSFXEventAssetMassEntry, 0x0028);
}
