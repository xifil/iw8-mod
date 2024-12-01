#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/float4.hpp"
#include "engine/iw8/ParticleEmitterDef.hpp"
#include "engine/iw8/ParticleScriptedInputNodeDef.hpp"
#include "engine/iw8/enums/ParticlePhaseOptions.hpp"

namespace IW8 {
	class ParticleSystemDef {
	public:
		const char* m_Name;										// 0x0000
		ParticleEmitterDef* m_EmitterDefs;						// 0x0008
		ParticleScriptedInputNodeDef* m_ScriptedInputNodeDefs;	// 0x0010
		int m_Version;											// 0x0018
		int m_NumEmitters;										// 0x001C
		int m_NumScriptedInputNodes;							// 0x0020
		unsigned int m_Flags;									// 0x0024
		int m_OcclusionOverrideEmitterIndex;					// 0x0028
		ParticlePhaseOptions m_PhaseOptions;					// 0x002C
		float m_DrawFrustumCullRadius;							// 0x0030
		float m_UpdateFrustumCullRadius;						// 0x0034
		float m_SunDistance;									// 0x0038
		int m_PreRollMSec;										// 0x003C
		float4 m_EditorPosition;								// 0x0040
		float4 m_EditorRotation;								// 0x0050
		float4 m_GameTweakPosition;								// 0x0060
		float4 m_GameTweakRotation;								// 0x0070
	};
	ENGINE_ASSERT_SZ(ParticleSystemDef, 0x0080);
}
