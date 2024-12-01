#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class AdsrZoneEntry {
	public:
		const char* m_Name;			// 0x0000
		std::uint32_t m_ID;			// 0x0008
	private:
		char pad_000C[0x0004];		// 0x000C
	public:
		const char* m_WeaponName;	// 0x0010
		int m_ADSRIdx;				// 0x0018
		std::uint32_t m_WeaponIdx;	// 0x001C
	};
	ENGINE_ASSERT_SZ(AdsrZoneEntry, 0x0020);
}
