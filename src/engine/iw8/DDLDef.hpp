#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/DDLEnum.hpp"
#include "engine/iw8/DDLStruct.hpp"

namespace IW8 {
	#pragma pack(push, 1)
	class DDLDef {
	public:
		char* m_Name;				// 0x0000
		std::uint16_t m_Version;	// 0x0008
	private:
		char pad_000A[0x0006];		// 0x000A
	public:
		std::uint64_t m_GuidSeed;	// 0x0010
		std::uint64_t m_Guid;		// 0x0018
		int m_BitSize;				// 0x0020
		int m_ByteSize;				// 0x0024
		DDLStruct* m_StructList;	// 0x0028
		int m_StructCount;			// 0x0030
	private:
		char pad_0034[0x0004];		// 0x0034
	public:
		DDLEnum* m_EnumList;		// 0x0038
		int m_EnumCount;			// 0x0040
	private:
		char pad_0044[0x0004];		// 0x0044
	public:
		DDLDef* m_Next;				// 0x0048
		int m_HeaderBitSize;		// 0x0050
		int m_HeaderByteSize;		// 0x0054
		bool m_PaddingUsed;			// 0x0058
		bool m_MinimalHeader;		// 0x0059
	private:
		char pad_005A[0x0006];		// 0x005A
	};
	#pragma pack(pop)
	ENGINE_ASSERT_SZ(DDLDef, 0x0060);
}
