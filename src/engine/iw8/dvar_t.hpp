#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/BbConstUsageFlags.hpp"
#include "engine/iw8/DvarLimits.hpp"
#include "engine/iw8/DvarValue.hpp"

namespace IW8 {
	class dvar_t {
	public:
		const char* m_Name;						// 0x0000
		std::uint32_t m_Checksum;				// 0x0008
	private:
		char pad_000C[0x0004];					// 0x000C
	public:
		const char* m_Description;				// 0x0010
		std::uint32_t m_Flags;					// 0x0018
		std::uint8_t m_Level[1];				// 0x001C
		std::uint8_t m_Type;					// 0x001D
		bool m_Modified;						// 0x001E
	private:
		char pad_001F[0x0001];					// 0x001F
	public:
		std::uint16_t m_HashNext;				// 0x0020
	private:
		char pad_0022[0x0006];					// 0x0022
	public:
		DvarValue m_Current;					// 0x0028
		DvarValue m_Latched;					// 0x0038
		DvarValue m_Reset;						// 0x0048
		DvarLimits m_Domain;					// 0x0058
		BbConstUsageFlags m_BbConstUsageFlags;	// 0x0068
	};
	ENGINE_ASSERT_SZ(dvar_t, 0x0080);
}
