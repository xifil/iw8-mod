#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/scr_string_t.hpp"
#include "engine/iw8/enums/VariableType.hpp"

namespace IW8 {
	class SpawnerField {
	public:
		scr_string_t m_Key;				// 0x0000
		std::uint32_t m_KeyCanonical;	// 0x0004
		scr_string_t m_Value;			// 0x0008
		VariableType m_Type;			// 0x000C
	private:
		char pad_000D[0x0003];			// 0x000D
	};
	ENGINE_ASSERT_SZ(SpawnerField, 0x0010);
}
