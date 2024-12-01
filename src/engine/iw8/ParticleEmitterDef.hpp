#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ParticleCurveDef.hpp"
#include "engine/iw8/ParticleFloatRange.hpp"
#include "engine/iw8/ParticleIntRange.hpp"
#include "engine/iw8/ParticleStateDef.hpp"
#include "engine/iw8/enums/ParticleDataFlags.hpp"
#include "engine/iw8/enums/ParticleGravityOptions.hpp"
#include "engine/iw8/enums/ParticleGroupID.hpp"
#include "engine/iw8/enums/ParticleInstancePoolAction.hpp"

namespace IW8 {
	class ParticleEmitterDef {
	public:
		ParticleStateDef* m_StateDefs;					// 0x0000
		int m_NumStates;								// 0x0008
		ParticleFloatRange m_ParticleSpawnRate;			// 0x000C
		ParticleFloatRange m_ParticleLife;				// 0x0014
		ParticleFloatRange m_ParticleDelay;				// 0x001C
		unsigned int m_ParticleCountMax;				// 0x0024
		ParticleIntRange m_ParticleBurstCount;			// 0x0028
		ParticleFloatRange m_EmitterLife;				// 0x0030
		ParticleFloatRange m_EmitterDelay;				// 0x0038
		int m_RandomSeed;								// 0x0040
		ParticleFloatRange m_SpawnRangeSq;				// 0x0044
		float m_FadeOutMaxDistance;						// 0x004C
		ParticleCurveDef m_FadeCurveDef;				// 0x0050
		float m_SpawnFrustumCullRadius;					// 0x0060
		unsigned int m_Flags;							// 0x0064
		ParticleGravityOptions m_GravityOptions;		// 0x0068
		ParticleGroupID m_GroupIDs[4];					// 0x006C
		ParticleFloatRange m_EmitByDistanceDensity;		// 0x007C
		unsigned int m_InstancePool;					// 0x0084
		unsigned int m_SoloInstanceMax;					// 0x0088
		ParticleInstancePoolAction m_InstanceAction;	// 0x008C
		ParticleDataFlags m_DataFlags;					// 0x0090
		ParticleFloatRange m_ParticleSpawnShapeRange;	// 0x0094
		unsigned int m_Pad[1];							// 0x009C
	};
	ENGINE_ASSERT_SZ(ParticleEmitterDef, 0x00A0);
}
