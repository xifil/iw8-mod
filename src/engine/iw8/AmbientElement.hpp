#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class AmbientElement {
	public:
		std::uint32_t m_ID;				// 0x0000
	private:
		char pad_0004[0x0004];			// 0x0004
	public:
		const char* m_UnusedNameField;	// 0x0008
		const char* m_AliasName;		// 0x0010
		float m_RangeMin;				// 0x0018
		float m_RangeMax;				// 0x001C
		float m_ConeMin;				// 0x0020
		float m_ConeMax;				// 0x0024
	};
	ENGINE_ASSERT_SZ(AmbientElement, 0x0028);
}
