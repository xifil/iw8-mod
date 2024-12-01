#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/TracerDef.hpp"
#include "engine/iw8/enums/tracerStyle_t.hpp"

namespace IW8 {
	class AttAmmoTracer {
	public:
		TracerDef* m_TracerType;		// 0x0000
		tracerStyle_t m_TracerStyle;	// 0x0008
	private:
		char pad_000C[0x0004];			// 0x000C
	};
	ENGINE_ASSERT_SZ(AttAmmoTracer, 0x0010);
}
