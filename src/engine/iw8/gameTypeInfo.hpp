#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class gameTypeInfo {
	public:
		char m_GameTypeInternalName[12];	// 0x0000
		char m_GameTypeName[32];			// 0x000C
		char m_CustomizedGameTypeName[64];	// 0x002C
		char m_CustomizedGameTypeDesc[64];	// 0x006C
	};
	ENGINE_ASSERT_SZ(gameTypeInfo, 0x00AC);
}
