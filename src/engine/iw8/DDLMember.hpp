#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class DDLMember {
	public:
		const char* m_Name;			// 0x0000
		int m_Index;				// 0x0008
		int m_BitSize;				// 0x000C
		int m_LimitSize;			// 0x0010
		int m_Offset;				// 0x0014
		int m_Type;					// 0x0018
		int m_ExternalIndex;		// 0x001C
		std::uint32_t m_RangeLimit;	// 0x0020
		bool m_IsArray;				// 0x0024
	private:
		char pad_0025[0x0003];		// 0x0025
	public:
		int m_ArraySize;			// 0x0028
		int m_EnumIndex;			// 0x002C
	};
	ENGINE_ASSERT_SZ(DDLMember, 0x0030);
}
