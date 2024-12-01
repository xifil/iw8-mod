#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class mapInfo {
	public:
		char m_MapName[32];				// 0x0000
		char m_MapLoadName[16];			// 0x0020
		char m_MapDescription[32];		// 0x0030
		char m_MapLoadImage[32];		// 0x0050
		char m_MapVoteImage[32];		// 0x0070
		char m_MapCamoTypes[2][16];		// 0x0090
		char m_MapDefaultGameType[32];	// 0x00B0
		char m_MapGameTypes[1024];		// 0x00D0
		int m_IsAliensMap;				// 0x04D0
		int m_MapPack;					// 0x04D4
	};
	ENGINE_ASSERT_SZ(mapInfo, 0x04D8);
}
