#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class SndFutz {
	public:
		char m_Name[0x40];				// 0x0000
		std::uint32_t m_ID;				// 0x0040
		bool m_Enable;					// 0x0044
	private:
		char pad_0045[0x0003];			// 0x0045
	public:
		float m_BpfF;					// 0x0048
		float m_BpfQ;					// 0x004C
		float m_LsG;					// 0x0050
		float m_LsF;					// 0x0054
		float m_LsQ;					// 0x0058
		float m_Dist;					// 0x005C
		float m_PreG;					// 0x0060
		float m_PostG;					// 0x0064
		float m_TH;						// 0x0068
		float m_TG;						// 0x006C
		float m_ClipPre;				// 0x0070
		float m_ClipPost;				// 0x0074
		float m_Blend;					// 0x0078
		std::uint32_t m_StartAliasID;	// 0x007C
		std::uint32_t m_StopAliasID;	// 0x0080
		std::uint32_t m_LoopAliasID;	// 0x0084
	};
	ENGINE_ASSERT_SZ(SndFutz, 0x0088);
}
