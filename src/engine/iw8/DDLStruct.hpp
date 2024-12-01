#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/DDLHashTable.hpp"
#include "engine/iw8/DDLMember.hpp"

namespace IW8 {
	class DDLStruct {
	public:
		const char* m_Name;				// 0x0000
		int m_BitSize;					// 0x0008
		int m_MemberCount;				// 0x000C
		DDLMember* m_Members;			// 0x0010
		DDLHashTable m_HashTableUpper;	// 0x0018
		DDLHashTable m_HashTableLower;	// 0x0028
	};
	ENGINE_ASSERT_SZ(DDLStruct, 0x0038);
}
