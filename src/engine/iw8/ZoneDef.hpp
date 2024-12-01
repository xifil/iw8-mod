#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class ZoneDef {
	public:
		std::uint32_t m_ID;							// 0x0000
		std::uint32_t m_StateID;					// 0x0004
		std::int16_t m_ReverbIndex;					// 0x0008
		std::int16_t m_StartOcclusionIndex;			// 0x000A
		std::int16_t m_NumOcclusion;				// 0x000C
		std::int16_t m_StartFilterIndex;			// 0x000E
		std::int16_t m_NumFilter;					// 0x0010
		std::int16_t m_StartMixIndex;				// 0x0012
		std::int16_t m_NumMix;						// 0x0014
	private:
		char pad_0016[0x0002];						// 0x0016
	public:
		const char* m_AmbientStream;				// 0x0018
		std::int16_t m_StartADSRZoneIndex;			// 0x0020
		std::int16_t m_NumADSRZone;					// 0x0022
		std::int16_t m_StartNPCADSRZoneIndex;		// 0x0024
		std::int16_t m_NumNPCADSRZone;				// 0x0026
		std::int16_t m_AmbientDefIndex;				// 0x0028
		std::int16_t m_StartFullOccIndex;			// 0x002A
		std::int16_t m_NumDisableFullOcc;			// 0x002C
		std::int16_t m_StartPlayerBreathStateIndex;	// 0x002E
		std::int16_t m_NumPlayerBreathStates;		// 0x0030
	private:
		char pad_0032[0x0002];						// 0x0032
	public:
		std::uint32_t m_WeapReflId;					// 0x0034
		bool m_Exterior;							// 0x0038
	private:
		char pad_0039[0x0007];						// 0x0039
	public:
		const char* m_ZoneName;						// 0x0040
		const char* m_StateName;					// 0x0048
		const char* m_AmbientName;					// 0x0050
		const char* m_MixName;						// 0x0058
		const char* m_ReverbName;					// 0x0060
		const char* m_FilterName;					// 0x0068
		const char* m_OcclusionName;				// 0x0070
		const char* m_PlrADSRName;					// 0x0078
		const char* m_NPCADSRName;					// 0x0080
		const char* m_WeapReflName;					// 0x0088
		const char* m_FullOccName;					// 0x0090
		const char* m_PlayerBreathStateName;		// 0x0098
		std::uint32_t m_ContextType1;				// 0x00A0
		std::uint32_t m_ContextValue1;				// 0x00A4
		std::uint32_t m_ContextType2;				// 0x00A8
		std::uint32_t m_ContextValue2;				// 0x00AC
		std::uint32_t m_ContextType3;				// 0x00B0
		std::uint32_t m_ContextValue3;				// 0x00B4
		std::uint32_t m_ContextType4;				// 0x00B8
		std::uint32_t m_ContextValue4;				// 0x00BC
		std::uint32_t m_Duck;						// 0x00C0
	private:
		char pad_00C4[0x0004];						// 0x00C4
	};
	ENGINE_ASSERT_SZ(ZoneDef, 0x00C8);
}
