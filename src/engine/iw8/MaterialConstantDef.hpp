#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec4_t.hpp"

namespace IW8 {
	class MaterialConstantDef {
	public:
		std::uint8_t m_Index;	// 0x0000
	private:
		char pad_0001[0x0003];	// 0x0001
	public:
		vec4_t m_Literal;		// 0x0004
	};
	ENGINE_ASSERT_SZ(MaterialConstantDef, 0x0014);
}
