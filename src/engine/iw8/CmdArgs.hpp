#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/LocalClientNum_t.hpp"

namespace IW8 {
	class CmdArgs {
	public:
		int m_Nesting;							// 0x0000
		LocalClientNum_t m_LocalClientNum[8];	// 0x0004
		int m_ControllerIndex[8];				// 0x0024
		int m_Argc[8];							// 0x0044
	private:
		char pad_0064[0x0004];					// 0x0064
	public:
		const char** m_Argv[8];					// 0x0068
		char m_TextPool[16384];					// 0x00A8
		const char* m_ArgvPool[512];			// 0x40A8
		int m_UsedTextPool[8];					// 0x50A8
		int m_TotalUsedArgvPool;				// 0x50C8
		int m_TotalUsedTextPool;				// 0x50CC
	};
	ENGINE_ASSERT_SZ(CmdArgs, 0x50D0);
}
