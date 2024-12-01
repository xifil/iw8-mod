#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/DopplerPreset.hpp"
#include "engine/iw8/FocusCone.hpp"
#include "engine/iw8/OcclusionShape.hpp"
#include "engine/iw8/SndAliasList.hpp"
#include "engine/iw8/SndBankStreamInfo.hpp"
#include "engine/iw8/SndCurve.hpp"
#include "engine/iw8/SndDuck.hpp"
#include "engine/iw8/SndFutz.hpp"
#include "engine/iw8/SndIndexEntry.hpp"
#include "engine/iw8/SndMusicSet.hpp"
#include "engine/iw8/SndSendEffectParams.hpp"
#include "engine/iw8/SoundTable.hpp"
#include "engine/iw8/SpeakerMap.hpp"
#include "engine/iw8/WeaponReflectionDef.hpp"

namespace IW8 {
	class SndBank {
	public:
		const char* m_Name;						// 0x0000
		const char* m_Zone;						// 0x0008
		const char* m_GameLanguage;				// 0x0010
		const char* m_SoundLanguage;			// 0x0018
		std::uint32_t m_AliasCount;				// 0x0020
	private:
		char pad_0024[0x0004];					// 0x0024
	public:
		SndAliasList* m_Alias;					// 0x0028
		SndIndexEntry* m_AliasIndex;			// 0x0030
		std::uint32_t m_SendEffectCount;		// 0x0038
	private:
		char pad_003C[0x0004];					// 0x003C
	public:
		SndSendEffectParams* m_SendEffects;		// 0x0040
		SoundTable m_SoundTable;				// 0x0048
		std::uint32_t m_DuckCount;				// 0x0130
	private:
		char pad_0134[0x0004];					// 0x0134
	public:
		SndDuck* m_Ducks;						// 0x0138
		std::uint32_t m_MusicSetCount;			// 0x0140
	private:
		char pad_0144[0x0004];					// 0x0144
	public:
		SndMusicSet* m_MusicSets;				// 0x0148
		std::uint32_t m_WeapReflectionCount;	// 0x0150
	private:
		char pad_0154[0x0004];					// 0x0154
	public:
		WeaponReflectionDef* m_WeapReflections;	// 0x0158
		std::uint32_t m_DopplerPresetCount;		// 0x0160
	private:
		char pad_0164[0x0004];					// 0x0164
	public:
		DopplerPreset* m_DopplerPresets;		// 0x0168
		std::uint32_t m_OcclusionShapeCount;	// 0x0170
	private:
		char pad_0174[0x0004];					// 0x0174
	public:
		OcclusionShape* m_OcclusionShapes;		// 0x0178
		std::uint32_t m_FocusConeCount;			// 0x0180
	private:
		char pad_0184[0x0004];					// 0x0184
	public:
		FocusCone* m_FocusCones;				// 0x0188
		std::uint32_t m_VfCurveCount;			// 0x0190
	private:
		char pad_0194[0x0004];					// 0x0194
	public:
		SndCurve* m_VfCurves;					// 0x0198
		std::uint32_t m_LpfCurveCount;			// 0x01A0
	private:
		char pad_01A4[0x0004];					// 0x01A4
	public:
		SndCurve* m_LpfCurves;					// 0x01A8
		std::uint32_t m_HpfCurveCount;			// 0x01B0
	private:
		char pad_01B4[0x0004];					// 0x01B4
	public:
		SndCurve* m_HpfCurves;					// 0x01B8
		std::uint32_t m_RvbCurveCount;			// 0x01C0
	private:
		char pad_01C4[0x0004];					// 0x01C4
	public:
		SndCurve* m_RvbCurves;					// 0x01C8
		std::uint32_t m_SpeakerMapCount;		// 0x01D0
	private:
		char pad_01D4[0x0004];					// 0x01D4
	public:
		SpeakerMap* m_SpeakerMaps;				// 0x01D8
		std::uint32_t m_FutzCount;				// 0x01E0
	private:
		char pad_01E4[0x0004];					// 0x01E4
	public:
		SndFutz* m_Futzs;						// 0x01E8
		SndBankStreamInfo m_StreamInfo;			// 0x01F0
	};
	ENGINE_ASSERT_SZ(SndBank, 0x0200);
}
