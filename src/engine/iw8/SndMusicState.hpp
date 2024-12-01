#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/SndMusicAsset.hpp"
#include "engine/iw8/enums/SndMusicStateStatus.hpp"

namespace IW8 {
	class SndMusicState {
	public:
		char m_Name[0x40];				// 0x0000
		std::uint32_t m_ID;				// 0x0040
		SndMusicAsset m_Intro;			// 0x0044
		SndMusicAsset m_Exit;			// 0x00C0
		std::uint32_t m_LoopCount;		// 0x013C
		SndMusicAsset* m_Loops;			// 0x0140
		int m_Order;					// 0x0148
		int m_InterruptPriority;		// 0x014C
		int m_PersistPriority;			// 0x0150
		bool m_IsRandom;				// 0x0154
		bool m_IsSequential;			// 0x0155
		bool m_SkipPreviousExit;		// 0x0156
		bool m_WallClockSync;			// 0x0157
		std::uint32_t m_RefCount;		// 0x0158
		SndMusicStateStatus m_Status;	// 0x015C
	};
	ENGINE_ASSERT_SZ(SndMusicState, 0x0160);
}
