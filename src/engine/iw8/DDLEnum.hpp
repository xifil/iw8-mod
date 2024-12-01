#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/DDLHashTable.hpp"

namespace IW8 {
	class DDLEnum {
	public:
		const char* m_Name;			// 0x0000
		int m_MemberCount;			// 0x0008
	private:
		char pad_000C[0x0004];		// 0x000C
	public:
		const char** m_Members;		// 0x0010
		DDLHashTable m_HashTable;	// 0x0018
	};
	ENGINE_ASSERT_SZ(DDLEnum, 0x0028);
}
