#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ParticleModuleDef.hpp"

namespace IW8 {
	class ParticleModuleGroupDef {
	public:
		ParticleModuleDef* m_ModuleDefs;	// 0x0000
		int m_NumModules;					// 0x0008
		bool m_Disabled;					// 0x000D
	private:
		char pad_000D[0x0003];				// 0x000D
	};
	ENGINE_ASSERT_SZ(ParticleModuleGroupDef, 0x0010);
}
