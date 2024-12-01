#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class ScriptFile {
	public:
		const char* m_Name;			// 0x0000
		int m_CompressedLen;		// 0x0008
		int m_Len;					// 0x000C
		int m_BytecodeLen;			// 0x0010
	private:
		char pad_0014[0x0004];		// 0x0014
	public:
		const char* m_Buffer;		// 0x0018
		std::uint8_t* m_Bytecode;	// 0x0020
	};
	ENGINE_ASSERT_SZ(ScriptFile, 0x0028);
}
