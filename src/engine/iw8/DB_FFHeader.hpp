#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/XFile.hpp"

namespace IW8 {
	class DB_FFHeader {
	public:
		char m_Magic[8];						// 0x0000
		std::uint32_t m_HeaderVersion;			// 0x0008
		std::uint32_t m_XFileVersion;			// 0x000C
		bool m_DashCompressBuild;				// 0x0010
		bool m_DashEncryptBuild;				// 0x0011
		std::uint8_t m_TransientFileType[1];	// 0x0012
	private:
		char pad_0013[0x0001];					// 0x0013
	public:
		std::uint32_t m_ResidentPartSize;		// 0x0014
		std::uint32_t m_ResidentHash;			// 0x0018
		std::uint32_t m_AlwaysLoadedPartSize;	// 0x001C
		XFile m_XFileHeader;					// 0x0020
	};
	ENGINE_ASSERT_SZ(DB_FFHeader, 0x00A0);
}
