#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class bdSecurityKey {
	public:
		std::uint8_t m_AB[0x0010];	// 0x0000

		bdSecurityKey() {
			std::fill(std::begin(this->m_AB), std::end(this->m_AB), 0x01);
		}
	};
	ENGINE_ASSERT_SZ(bdSecurityKey, 0x0010);
}
