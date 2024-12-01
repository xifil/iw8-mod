#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/float4.hpp"
#include "engine/iw8/ParticleModule.hpp"

namespace IW8 {
	class ParticleModuleInitAttributes : public ParticleModule {
	public:
		bool m_UseNonUniformInterpolationForColor;	// 0x0008
		bool m_UseNonUniformInterpolationForSize;	// 0x0009
		std::uint8_t m_Pad[6];						// 0x000A
		float4 m_SizeMin;							// 0x0010
		float4 m_SizeMax;							// 0x0020
		float4 m_ColorMin;							// 0x0030
		float4 m_ColorMax;							// 0x0040
		float4 m_VelocityMin;						// 0x0050
		float4 m_VelocityMax;						// 0x0060
	};
	ENGINE_ASSERT_SZ(ParticleModuleInitAttributes, 0x0070);
}
