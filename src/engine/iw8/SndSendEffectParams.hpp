#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class SndSendEffectParams {
	public:
		char m_Name[0x40];			// 0x0000
		std::uint32_t m_ID;			// 0x0040
		float m_Smoothing;			// 0x0044
		float m_EarlyTime;			// 0x0048
		float m_LateTime;			// 0x004C
		float m_EarlyGain;			// 0x0050
		float m_LateGain;			// 0x0054
		float m_LateGainProx;		// 0x0058
		float m_ReturnGain;			// 0x005C
		float m_EarlyLPF;			// 0x0060
		float m_LateLPF;			// 0x0064
		float m_InputLPF;			// 0x0068
		float m_DampLPF;			// 0x006C
		float m_WallReflect;		// 0x0070
		float m_DryGain;			// 0x0074
		float m_EarlySize;			// 0x0078
		float m_LateSize;			// 0x007C
		float m_Diffusion;			// 0x0080
		float m_RearLevel;			// 0x0084
		bool m_Delay1Enabled;		// 0x0088
	private:
		char pad_0089[0x0003];		// 0x0089
	public:
		float m_Delay1DelayTimeMS;	// 0x008C
		float m_Delay1Level;		// 0x0090
		float m_Delay1LPFCutoff;	// 0x0094
		float m_Delay1HPFCutoff;	// 0x0098
		bool m_Delay2Enabled;		// 0x009C
	private:
		char pad_009D[0x0003];		// 0x009D
	public:
		float m_Delay2DelayTimeMS;	// 0x00A0
		float m_Delay2Level;		// 0x00A4
		float m_Delay2LPFCutoff;	// 0x00A8
		float m_Delay2HPFCutoff;	// 0x00AC
		bool m_Delay3Enabled;		// 0x00B0
	private:
		char pad_00B1[0x0003];		// 0x00B1
	public:
		float m_Delay3DelayTimeMS;	// 0x00B4
		float m_Delay3Level;		// 0x00B8
		float m_Delay3LPFCutoff;	// 0x00BC
		float m_Delay3HPFCutoff;	// 0x00C0
		bool m_Delay4Enabled;		// 0x00C4
	private:
		char pad_00C5[0x0003];		// 0x00C5
	public:
		float m_Delay4DelayTimeMS;	// 0x00C8
		float m_Delay4Level;		// 0x00CC
		float m_Delay4LPFCutoff;	// 0x00D0
		float m_Delay4HPFCutoff;	// 0x00D4
		bool m_Delay5Enabled;		// 0x00D8
	private:
		char pad_00D9[0x0003];		// 0x00D9
	public:
		float m_Delay5DelayTimeMS;	// 0x00DC
		float m_Delay5Level;		// 0x00E0
		float m_Delay5LPFCutoff;	// 0x00E4
		float m_Delay5HPFCutoff;	// 0x00E8
	};
	ENGINE_ASSERT_SZ(SndSendEffectParams, 0x00EC);
}
