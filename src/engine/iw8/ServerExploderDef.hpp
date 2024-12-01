#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/vec3_t.hpp"
#include "engine/iw8/enums/scr_string_t.hpp"

namespace IW8 {
	class ServerExploderDef {
	public:
		vec3_t m_Origin;				// 0x0000
		int m_DelayMsec;				// 0x000C
		float m_DamageAmount;			// 0x0010
		float m_DamageRadius;			// 0x0014
		scr_string_t m_Name;			// 0x0018
		scr_string_t m_EarthquakeName;	// 0x001C
		scr_string_t m_RumbleName;		// 0x0020
		bool m_DamageEnvironmentOnly;	// 0x0024
		bool m_DamageDoOcclusionTraces;	// 0x0025
	private:
		char pad_0026[0x0002];			// 0x0026
	};
	ENGINE_ASSERT_SZ(ServerExploderDef, 0x0028);
}
