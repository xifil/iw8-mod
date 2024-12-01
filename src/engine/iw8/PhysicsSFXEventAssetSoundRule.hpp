#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class PhysicsSFXEventAssetSoundRule {
	public:
		char* m_HitSoundAlias;						// 0x0000
		char* m_ScrapeSoundAlias;					// 0x0008
		float m_ScrapeSoundVolumeSpeedThresholdMin;	// 0x0010
		float m_ScrapeSoundVolumeSpeedThresholdMax;	// 0x0014
		float m_ScrapeSoundVolumeBlendSpeed;		// 0x0018
	private:
		char pad_001C[0x0004];						// 0x001C
	};
	ENGINE_ASSERT_SZ(PhysicsSFXEventAssetSoundRule, 0x0020);
}
