#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class SndDuck {
	public:
		char m_Name[0x40];				// 0x0000
		std::uint32_t m_ID;				// 0x0040
		float m_FadeIn;					// 0x0044
		float m_FadeOut;				// 0x0048
		float m_StartDelay;				// 0x004C
		float m_MinDistance;			// 0x0050
		float m_Distance;				// 0x0054
		float m_Length;					// 0x0058
		std::uint32_t m_FadeInCurve;	// 0x005C
		std::uint32_t m_FadeOutCurve;	// 0x0060
	private:
		char pad_0064[0x0004];			// 0x0064
	public:
		float* m_Attenuation;			// 0x0068
		float* m_HPF;					// 0x0070
		float* m_LPF;					// 0x0078
		float* m_FocusAmount;			// 0x0080
		std::uint32_t* m_FocusCone;		// 0x0088
		bool m_UpdateWhilePaused;		// 0x0090
		bool m_TrackAmplitude;			// 0x0091
		bool m_DisableInSplitscreen;	// 0x0092
	private:
		char pad_0093[0x0001];			// 0x0093
	public:
		float m_AliasAttenuation;		// 0x0094
		float m_AliasHPF;				// 0x0098
		float m_AliasLPF;				// 0x009C
		std::uint32_t m_DuckAlias;		// 0x00A0
	private:
		char pad_00A4[0x0004];			// 0x00A4
	};
	ENGINE_ASSERT_SZ(SndDuck, 0x00A8);
}
