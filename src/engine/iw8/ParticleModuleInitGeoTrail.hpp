#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ParticleFloatRange.hpp"
#include "engine/iw8/ParticleModule.hpp"

namespace IW8 {
	class ParticleModuleInitGeoTrail : public ParticleModule {
	public:
		std::uint32_t m_NumPointsMax;		// 0x0008
		float m_SplitDistance;				// 0x000C
		float m_SplitAngle;					// 0x0010
		float m_CenterOffset;				// 0x0014
		std::uint32_t m_NumSheets;			// 0x0018
		float m_FadeInDistance;				// 0x001C
		float m_FadeOutDistance;			// 0x0020
		float m_TileDistance;				// 0x0024
		ParticleFloatRange m_TileOffset;	// 0x0028
		float m_ScrollTime;					// 0x0030
		bool m_UseLocalVelocity;			// 0x0034
		bool m_UseVerticalTexture;			// 0x0035
		bool m_CameraFacing;				// 0x0036
		bool m_FixLeadingEdge;				// 0x0037
		bool m_ClampUVs;					// 0x0038
		std::uint8_t m_Pad[3];				// 0x0039
		std::uint32_t m_Pad2[1];			// 0x003C
	};
	ENGINE_ASSERT_SZ(ParticleModuleInitGeoTrail, 0x0040);
}
