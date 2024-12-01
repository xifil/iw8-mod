#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class DDLType : int {
		DDL_INVALID_TYPE = 0xFFFFFFFF,
		DDL_BYTE_TYPE = 0x0,
		DDL_SHORT_TYPE = 0x1,
		DDL_UINT_TYPE = 0x2,
		DDL_INT_TYPE = 0x3,
		DDL_UINT64_TYPE = 0x4,
		DDL_HASH_TYPE = 0x5,
		DDL_FLOAT_TYPE = 0x6,
		DDL_FIXEDPOINT_TYPE = 0x7,
		DDL_STRING_TYPE = 0x8,
		DDL_STRUCT_TYPE = 0x9,
		DDL_ENUM_TYPE = 0xA,
		DDL_PAD_TYPE = 0xB
	};
}
