#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class MaterialSerializedShader {
	public:
		const char* m_Name;				// 0x0000
		const char* m_DebugName;		// 0x0008
		std::uint8_t* m_Program;		// 0x0010
		std::uint8_t* m_MetaData;		// 0x0018
		std::uint32_t m_ProgramSize;	// 0x0020
		std::uint32_t m_MetaDataSize;	// 0x0024
		std::uint32_t m_MicroCodeCrc;	// 0x0028
	private:
		char pad_002C[0x0004];			// 0x002C
	};
	ENGINE_ASSERT_SZ(MaterialSerializedShader, 0x0030);
}
