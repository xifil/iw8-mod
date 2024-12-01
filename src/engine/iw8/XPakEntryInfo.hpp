#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class XPakEntryInfo {
	public:
		std::uint64_t m_Key;					// 0x0000
		std::int64_t m_Offset;					// 0x0008
		std::uint64_t m_Size;					// 0x0010
		std::uint64_t m_XPakIndex : 8;			// 0x0018
		std::uint64_t m_Compressed : 1;			// 0x0018
		std::uint64_t m_Valid : 1;				// 0x0018
		std::uint64_t m_AdjacentLeftType : 3;	// 0x0018
		std::uint64_t m_AdjacentRightType : 3;	// 0x0018
		std::uint64_t m_AdjacentLeft : 19;		// 0x0018
		std::uint64_t m_AdjacentRight : 19;		// 0x0018
		std::uint64_t m_Padding : 10;			// 0x0018
	};
	ENGINE_ASSERT_SZ(XPakEntryInfo, 0x0020);
}
