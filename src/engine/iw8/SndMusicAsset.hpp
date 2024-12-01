#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class SndMusicAsset {
	public:
		char m_Alias[0x40];					// 0x0000
		std::uint32_t m_AliasID;			// 0x0040
		bool m_Inactive;					// 0x0044
		bool m_CompleteLoop;				// 0x0045
		bool m_RemoveAfterPlay;				// 0x0046
		bool m_FirstRandom;					// 0x0047
		bool m_StartSync;					// 0x0048
		bool m_StopSync;					// 0x0049
		bool m_CompleteOnStop;				// 0x004A
	private:
		char pad_004B[0x0001];				// 0x004B
	public:
		std::uint32_t m_LoopStartOffset;	// 0x004C
		int m_BPM;							// 0x0050
		int m_AssetType;					// 0x0054
		int m_LoopNumber;					// 0x0058
		std::uint32_t m_SampleCount;		// 0x005C
		int m_StartDelayBeats;				// 0x0060
		int m_StartFadeBeats;				// 0x0064
		int m_StopDelayBeats;				// 0x0068
		int m_StopFadeBeats;				// 0x006C
		int m_StartOffsetFrames;			// 0x0070
		int m_Meter;						// 0x0074
		std::uint32_t m_SampleRate;			// 0x0078
	};
	ENGINE_ASSERT_SZ(SndMusicAsset, 0x007C);
}
