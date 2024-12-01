#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class EncryptionHeader {
	public:
		std::uint32_t m_IsEncrypted;	// 0x0000
		std::uint8_t m_IV[16];			// 0x0004
	};
	ENGINE_ASSERT_SZ(EncryptionHeader, 0x0014);
}
