#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class OmnvarType : std::int8_t {
		OMNVAR_TYPE_BOOL = 0x0,
		OMNVAR_TYPE_FLOAT = 0x1,
		OMNVAR_TYPE_INT = 0x2,
		OMNVAR_TYPE_UINT = 0x3,
		OMNVAR_TYPE_TIME = 0x4,
		OMNVAR_TYPE_NCS_LUI = 0x5,
		OMNVAR_TYPE_COUNT = 0x6
	};
}
