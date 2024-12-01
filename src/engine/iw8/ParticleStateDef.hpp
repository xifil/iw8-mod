#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ParticleModuleGroupDef.hpp"

namespace IW8 {
	class ParticleStateDef {
	public:
		ParticleModuleGroupDef* m_ModuleGroupDefs;	// 0x0000
		std::uint32_t m_ElementType;				// 0x0008
	private:
		char pad_000C[0x0004];						// 0x000C
	public:
		std::uint64_t m_Flags;						// 0x0010
		std::uint32_t m_Pad[2];						// 0x0018
	};
	ENGINE_ASSERT_SZ(ParticleStateDef, 0x0020);
}
