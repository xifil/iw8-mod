#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/StreamKey.hpp"

namespace IW8 {
	class SndBankStreamInfo {
		StreamKey* m_LoadedStreamKey;	// 0x0000
		bool m_AlwaysLoaded;			// 0x0008
	private:
		char pad_0009[0x0007];			// 0x0009
	};
	ENGINE_ASSERT_SZ(SndBankStreamInfo, 0x0010);
}
