#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/EncryptionHeader.hpp"

namespace IW8 {
	struct EncryptionInfo {
		EncryptionHeader m_Header;		// 0x0000
		std::uint8_t m_PrivateKey[32];	// 0x0014
	};
	ENGINE_ASSERT_SZ(EncryptionInfo, 0x0034);
}
