#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/DDLDef.hpp"

namespace IW8 {
	class DDLFile {
	public:
		char* m_Name;		// 0x0000
		DDLDef* m_DDLDef;	// 0x0008
	};
	ENGINE_ASSERT_SZ(DDLFile, 0x0010);
}
