#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/DDLHash.hpp"

namespace IW8 {
	class DDLHashTable {
	public:
		DDLHash* m_List;	// 0x0000
		int m_Count;		// 0x0008
		int m_Max;			// 0x000C
	};
	ENGINE_ASSERT_SZ(DDLHashTable, 0x0010);
}
