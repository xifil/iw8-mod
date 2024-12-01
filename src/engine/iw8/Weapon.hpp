#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class Weapon {
	public:
		std::uint16_t m_WeaponIdx;						// 0x0000
		std::uint16_t m_StickerIndices[4];				// 0x0002
		std::uint16_t m_WeaponClientLoadout;			// 0x000A
		std::uint16_t m_WeaponOthers;					// 0x000C
		std::uint8_t m_WeaponAttachments[13];			// 0x000E
		std::uint8_t m_AttachmentVariationIndices[29];	// 0x001B
		std::uint8_t m_WeaponCamo;						// 0x0038
		std::uint8_t m_WeaponLootId;					// 0x0039
		std::uint8_t m_ScopeVariation;					// 0x003A
		std::uint8_t m_VisualAttachmentHighAddr;		// 0x003B
	};
	ENGINE_ASSERT_SZ(Weapon, 0x003C);
}
