#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/float4.hpp"
#include "engine/iw8/ParticleCurveDef.hpp"
#include "engine/iw8/ParticleFloatRange.hpp"
#include "engine/iw8/ParticleModule.hpp"

namespace IW8 {
	class ParticleModuleInitFlare : public ParticleModule {
	public:
		unsigned int m_Pad[1];					// 0x0008
		float m_Position;						// 0x000C
		float4 m_Direction;						// 0x0010
		int m_AngularRotCount;					// 0x0020
		unsigned int m_FlareFlags;				// 0x0024
		ParticleFloatRange m_DepthScaleRange;	// 0x0028
		ParticleFloatRange m_DepthScaleValue;	// 0x0030
		ParticleFloatRange m_RadialRot;			// 0x0038
		ParticleFloatRange m_RadialScaleX;		// 0x0040
		ParticleFloatRange m_RadialScaleY;		// 0x0048
		ParticleCurveDef m_Curves[4];			// 0x0050
	};
	ENGINE_ASSERT_SZ(ParticleModuleInitFlare, 0x0090);
}
