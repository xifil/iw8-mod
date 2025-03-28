#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	enum class WeapOverlayInteface_t : int {
		WEAPOVERLAYINTERFACE_NONE = 0x0,
		WEAPOVERLAYINTERFACE_JAVELIN = 0x1,
		WEAPOVERLAYINTERFACE_TURRETSCOPE = 0x2,
		WEAPOVERLAYINTERFACE_BINOCULARS = 0x3,
		WEAPOVERLAYINTERFACECOUNT = 0x4
	};
}
