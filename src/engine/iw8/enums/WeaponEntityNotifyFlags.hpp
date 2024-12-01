#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class WeaponEntityNotifyFlags : int {
		WEAP_NOTIFY_FLAG_NONE = 0x0,
		WEAP_NOFITY_FLAG_CHECK_TEAM = 0x1,
		WEAP_NOFITY_FLAG_CHECK_VISIBLE = 0x2
	};
}
