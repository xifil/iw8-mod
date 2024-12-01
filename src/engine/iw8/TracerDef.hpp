#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/FxCombinedDef.hpp"
#include "engine/iw8/Material.hpp"
#include "engine/iw8/vec4_t.hpp"

namespace IW8 {
	class TracerDef {
	public:
		const char* m_Name;					// 0x0000
		FxCombinedDef m_Effect;				// 0x0008
		FxCombinedDef m_ViewModelEffect;	// 0x0010
		unsigned int m_DrawInterval;		// 0x0018
		float m_Speed;						// 0x001C
		bool m_DrawLegacyTracer;			// 0x0020
		bool m_FadeOverTime;				// 0x0021
	private:
		char pad_0022[0x0002];				// 0x0022
	public:
		float m_FadeTime;					// 0x0024
		Material* m_Material;				// 0x0028
		float m_BeamLength;					// 0x0030
		float m_BeamWidth;					// 0x0034
		float m_ScrewRadius;				// 0x0038
		float m_ScrewDist;					// 0x003C
		vec4_t m_Colors[5];					// 0x0040
	};
	ENGINE_ASSERT_SZ(TracerDef, 0x0090);
}
