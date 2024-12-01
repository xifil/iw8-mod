#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class WeaponSlot : __int32 {
		WEAPON_SLOT_NONE = 0x0,
		WEAPON_SLOT_PRIMARY = 0x1,
		WEAPON_SLOT_HEAVY = 0x2,
		WEAPON_SLOT_MELEE = 0x3,
		WEAPON_SLOT_EXECUTION = 0x4,
		WEAPON_SLOT_ACCESSORY = 0x5,
		WEAPON_SLOT_NUM = 0x6
	};
}
