#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class StringTable {
	public:
		const char* m_Name;				// 0x0000
		int m_ColumnCount;				// 0x0008
		int m_RowCount;					// 0x000C
		int m_UniqueCellCount;			// 0x0010
	private:
		char pad_0014[0x0004];			// 0x0014
	public:
		std::uint16_t* m_CellIndices;	// 0x0018
		int* m_Hashes;					// 0x0020
		const char** m_Strings;			// 0x0028
	};
	ENGINE_ASSERT_SZ(StringTable, 0x0030);
}
