#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class TTFDef {
	public:
		const char* m_Name;		// 0x0000
		int m_FileLen;			// 0x0008
	private:
		char pad_000C[0x0004];	// 0x000C
	public:
		const char* m_File;		// 0x0010
		void* m_FontFace;		// 0x0018
	};
	ENGINE_ASSERT_SZ(TTFDef, 0x0020);
}
