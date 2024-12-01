#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/EncryptionHeader.hpp"

namespace IW8 {
	class XFile {
	public:
		std::uint64_t m_Size;				// 0x0000
		std::uint64_t m_PreloadWalkSize;	// 0x0008
		std::uint64_t m_BlockSize[11];		// 0x0010
		EncryptionHeader m_Encryption;		// 0x0068
	private:
		char pad_007C[0x0004];				// 0x007C
	};
	ENGINE_ASSERT_SZ(XFile, 0x0080);
}
