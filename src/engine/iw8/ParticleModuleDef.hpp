#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ParticleModuleTypeDef.hpp"
#include "engine/iw8/enums/ParticleModuleType.hpp"

namespace IW8 {
	class ParticleModuleDef {
	public:
		ParticleModuleType m_ModuleType;	// 0x0000
	private:
		char pad_0002[0x0002];				// 0x0002
	public:
		unsigned int m_Pad[2];				// 0x0004
	private:
		char pad_000C[0x0004];				// 0x000C
	public:
		ParticleModuleTypeDef m_ModuleData;	// 0x0010
	};
	ENGINE_ASSERT_SZ(ParticleModuleDef, 0x00F0);
}
