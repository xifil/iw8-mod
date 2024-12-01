#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/SpawnerField.hpp"
#include "engine/iw8/vec3_t.hpp"
#include "engine/iw8/enums/scr_string_t.hpp"

namespace IW8 {
	class Spawner {
	public:
		vec3_t m_Origin;			// 0x0000
		vec3_t m_Angles;			// 0x000C
		SpawnerField* m_Fields;		// 0x0018
		int m_Flags;				// 0x0020
		int m_Count;				// 0x0024
		std::uint32_t m_NumFields;	// 0x0028
		scr_string_t m_TargetName;	// 0x002C
		scr_string_t m_ClassName;	// 0x0030
	private:
		char pad_0034[0x0004];		// 0x0034
	};
	ENGINE_ASSERT_SZ(Spawner, 0x0038);
}
