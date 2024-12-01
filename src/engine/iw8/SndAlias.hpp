#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class SndAlias {
	public:
		const char* m_AliasName;				// 0x0000
		const char* m_Subtitle;					// 0x0008
		const char* m_SecondaryAliasName;		// 0x0010
		const char* m_AssetFileName;			// 0x0018
		std::uint32_t m_ID;						// 0x0020
		std::uint32_t m_SecondaryID;			// 0x0024
		std::uint32_t m_AssetID;				// 0x0028
		std::uint32_t m_ContextType;			// 0x002C
		std::uint32_t m_ContextValue;			// 0x0030
		std::uint32_t m_Context2Type;			// 0x0034
		std::uint32_t m_Context2Value;			// 0x0038
		std::uint32_t m_Duck;					// 0x003C
		std::uint64_t m_SurfaceFlags;			// 0x0040
		int m_Sequence;							// 0x0048
		float m_VolMin;							// 0x004C
		float m_VolMax;							// 0x0050
		int m_VolModIndex;						// 0x0054
		float m_PitchMin;						// 0x0058
		float m_PitchMax;						// 0x005C
		float m_DonutFadeEnd;					// 0x0060
		float m_DistMin;						// 0x0064
		float m_DistMax;						// 0x0068
		float m_VelocityMin;					// 0x006C
		int m_Flags;							// 0x0070
		float m_Probability;					// 0x0074
		float m_LfePercentage;					// 0x0078
		float m_CenterPercentage;				// 0x007C
		int m_StartDelay;						// 0x0080
		int m_StartDelayMax;					// 0x0084
		std::uint32_t m_VolumeFalloffCurve;		// 0x0088
		std::uint32_t m_LPFCurve;				// 0x008C
		std::uint32_t m_HPFCurve;				// 0x0090
		std::uint32_t m_ReverbSendCurve;		// 0x0094
		float m_EnvelopMin;						// 0x0098
		float m_EnvelopMax;						// 0x009C
		float m_EnvelopPercentage;				// 0x00A0
		std::uint32_t m_SpeakerMap;				// 0x00A4
		float m_ReverbMultiplier;				// 0x00A8
		float m_FarReverbMultiplier;			// 0x00AC
		std::uint32_t m_OcclusionShape;			// 0x00B0
		std::uint32_t m_DopplerPreset;			// 0x00B4
		float m_SmartPanDistance2d;				// 0x00B8
		float m_SmartPanDistance3d;				// 0x00BC
		float m_SmartPanAttenuation2d;			// 0x00C0
		float m_StereoSpreadMinDist;			// 0x00C4
		float m_StereoSpreadMaxDist;			// 0x00C8
		float m_StereoSpreadMidPoint;			// 0x00CC
		std::uint8_t m_StereoSpreadMaxAngle;	// 0x00D0
		std::uint8_t m_MasterPriority;			// 0x00D1
	private:
		char pad_00D2[0x0002];					// 0x00D2
	public:
		float m_MasterPercentage;				// 0x00D4
		float m_MasterSlavePercentage;			// 0x00D8
		float m_MasterThreshold;				// 0x00DC
		std::int16_t m_MaxDurationDsec;			// 0x00E0
	private:
		char pad_00E2[0x0006];					// 0x00E2
	};
	ENGINE_ASSERT_SZ(SndAlias, 0x00E8);
}
