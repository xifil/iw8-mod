#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class DBFileHandle {
	public:
		std::uint8_t m_FileID[4];		// 0x0000
	private:
		char pad_0004[0x0004];			// 0x0004
	public:
		std::uint64_t m_DCacheFileID;	// 0x0008
	};
	ENGINE_ASSERT_SZ(DBFileHandle, 0x0010);
}
