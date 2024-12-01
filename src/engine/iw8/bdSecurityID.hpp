#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class bdSecurityID {
	public:
		std::uint8_t m_AB[0x0008];	// 0x0000

		bdSecurityID() {
			std::fill(std::begin(this->m_AB), std::end(this->m_AB), 0x00);
		}

		bool IsValid() {
			return reinterpret_cast<std::int64_t>(this->m_AB) != 0;
		}

		bool operator==(const bdSecurityID& obj) const {
			return reinterpret_cast<std::int64_t>(this->m_AB) == reinterpret_cast<std::int64_t>(obj.m_AB);
		}

		bool operator!=(const bdSecurityID& obj) const {
			return reinterpret_cast<std::int64_t>(this->m_AB) != reinterpret_cast<std::int64_t>(obj.m_AB);
		}
	};
	ENGINE_ASSERT_SZ(bdSecurityID, 0x0008);
}
