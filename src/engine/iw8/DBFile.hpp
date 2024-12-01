#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/DBFileHandle.hpp"
#include "engine/iw8/EncryptionInfo.hpp"

namespace IW8 {
	struct DBFile {
		char m_Name[64];				// 0x0000
		DBFileHandle m_DBFileHandle;	// 0x0040
		bool m_IsSecured;				// 0x0050
	private:
		char pad_0051[0x0003];			// 0x0051
	public:
		EncryptionInfo m_Encryption;	// 0x0054
	};
	ENGINE_ASSERT_SZ(DBFile, 0x0088);
}
