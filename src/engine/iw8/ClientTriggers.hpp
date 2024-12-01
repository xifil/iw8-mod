#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/ClientEntityLinkToDef.hpp"
#include "engine/iw8/ClientMapTriggers.hpp"
#include "engine/iw8/CTAudRvbPanInfo.hpp"
#include "engine/iw8/SndBankTransient.hpp"
#include "engine/iw8/SpatialPartition_Tree.hpp"
#include "engine/iw8/vec3_t.hpp"

namespace IW8 {
	class ClientTriggers {
	public:
		ClientMapTriggers m_Trigger;			// 0x0000
		std::uint32_t m_TriggerStringLength;	// 0x0030
	private:
		char pad_0034[0x0004];					// 0x0034
	public:
		char* m_TriggerString;					// 0x0038
		std::int16_t* m_VisionSetTriggers;		// 0x0040
		std::uint16_t* m_TriggerType;			// 0x0048
		vec3_t* m_Origins;						// 0x0050
		float* m_ScriptDelay;					// 0x0058
		float* m_Priority;						// 0x0060
		std::int16_t* m_AudioTriggers;			// 0x0068
		std::int16_t* m_BlendLookup;			// 0x0070
		std::int16_t* m_NPCTriggers;			// 0x0078
		std::int16_t* m_AudioStateIds;			// 0x0080
		SndBankTransient** m_DetailSoundBank;	// 0x0088
		CTAudRvbPanInfo* m_AudioRvbPanInfo;		// 0x0090
		std::int16_t* m_Parent;					// 0x0098
		ClientEntityLinkToDef** m_LinkTo;		// 0x00A0
		SpatialPartition_Tree* m_SpatialTree;	// 0x00A8
	};
	ENGINE_ASSERT_SZ(ClientTriggers, 0x00B0);
}
