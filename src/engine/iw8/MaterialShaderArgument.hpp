#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/MaterialArgumentType.hpp"

namespace IW8 {
	class MaterialShaderArgument {
	public:
		MaterialArgumentType m_Type;	// 0x0000
		std::uint8_t m_Shader;			// 0x0001
		std::uint16_t m_Dest;			// 0x0002
		std::uint16_t m_Index;			// 0x0004
	};
	ENGINE_ASSERT_SZ(MaterialShaderArgument, 0x0006);
}
