#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/netsrc_t.hpp"

namespace IW8 {
	class msg_t {
	public:
		int m_Overflowed;					// 0x0000
		int m_ReadOnly;						// 0x0004
		std::uint8_t* m_Data;				// 0x0008
		std::uint8_t* m_SplitData;			// 0x0010
		int m_MaxSize;						// 0x0018
		int m_CurSize;						// 0x001C
		int m_SplitSize;					// 0x0020
		int m_ReadCount;					// 0x0024
		int m_Bit;							// 0x0028
		int m_LastEntityRef;				// 0x002C
		netsrc_t m_TargetLocalNetID;		// 0x0030
		std::uint32_t m_CompressionFlags;	// 0x0034
	};
	ENGINE_ASSERT_SZ(msg_t, 0x0038);
}
