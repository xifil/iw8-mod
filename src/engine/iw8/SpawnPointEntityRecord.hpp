#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec3_t.hpp"
#include "engine/iw8/enums/scr_string_t.hpp"

namespace IW8 {
	class SpawnPointEntityRecord {
	public:
		std::uint16_t m_Index;				// 0x0000
	private:
		char pad_0002[0x0002];				// 0x0002
	public:
		scr_string_t m_Name;				// 0x0004
		scr_string_t m_Target;				// 0x0008
		scr_string_t m_ScriptNoteworthy;	// 0x000C
		vec3_t m_Origin;					// 0x0010
		vec3_t m_Angles;					// 0x001C
	};
	ENGINE_ASSERT_SZ(SpawnPointEntityRecord, 0x0028);
}
