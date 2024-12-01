#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum GfxImageCategory : std::int8_t {
		IMG_CATEGORY_UNKNOWN = 0x0,
		IMG_CATEGORY_AUTO_GENERATED = 0x1,
		IMG_CATEGORY_LIGHTMAP = 0x2,
		IMG_CATEGORY_LOAD_FROM_FILE = 0x3,
		IMG_CATEGORY_RAW = 0x4,
		IMG_CATEGORY_FIRST_UNMANAGED = 0x5,
		IMG_CATEGORY_RENDERTARGET = 0x5,
		IMG_CATEGORY_TEMP = 0x6
	};
}
