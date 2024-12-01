#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ParticleCurveDef.hpp"
#include "engine/iw8/ParticleModule.hpp"

namespace IW8 {
	class ParticleModuleInitAtlas : public ParticleModule {
	public:
		int m_StartFrame;				// 0x0008
		int m_LoopCount;				// 0x000C
		bool m_RandomIndex;				// 0x0010
		bool m_PlayOverLife;			// 0x0011
	private:
		char pad_0012[0x0002];			// 0x0012
	public:
		std::uint32_t m_Pad[3];			// 0x0014
		ParticleCurveDef m_Curves[2];	// 0x0020
	};
	ENGINE_ASSERT_SZ(ParticleModuleInitAtlas, 0x0040);
}
