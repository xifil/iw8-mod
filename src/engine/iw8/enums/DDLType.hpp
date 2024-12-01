#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class DDLType : int {
		DDL_INVALID_TYPE = -1,
		DDL_BYTE_TYPE = 0,
		DDL_SHORT_TYPE = 1,
		DDL_UINT_TYPE = 2,
		DDL_INT_TYPE = 3,
		DDL_UINT64_TYPE = 4,
		DDL_HASH_TYPE = 5,
		DDL_FLOAT_TYPE = 6,
		DDL_FIXEDPOINT_TYPE = 7,
		DDL_STRING_TYPE = 8,
		DDL_STRUCT_TYPE = 9,
		DDL_ENUM_TYPE = 10,
		DDL_PAD_TYPE = 11
	};
}
