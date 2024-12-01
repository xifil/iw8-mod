#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/StreamKeyData.hpp"
#include "engine/iw8/XPakEntryInfo.hpp"
#include "engine/iw8/enums/StreamKeyBehaviorIndex.hpp"

namespace IW8 {
	class StreamKey {
	public:
		const char* m_Name;						// 0x0000
		XPakEntryInfo m_XPakInfo;				// 0x0008
		StreamKeyData m_Data;					// 0x0028
		union {
			void* m_BehaviorUserPtr;			// 0x0030
			std::uint64_t m_AssetHash;			// 0x0030
		};
		std::uint32_t m_DataSize;				// 0x0038
		StreamKeyBehaviorIndex m_BehaviorIndex;	// 0x003C
		std::uint8_t m_Flags;					// 0x003D
	private:
		char pad_003E[0x0002];					// 0x003E
	};
	ENGINE_ASSERT_SZ(StreamKey, 0x0040);
}
