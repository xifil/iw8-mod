#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/AdsSwaySettings.hpp"
#include "engine/iw8/AdvancedHipSwaySettings.hpp"
#include "engine/iw8/HipSwaySettings.hpp"

namespace IW8 {
	class SwaySettings {
	public:
		HipSwaySettings m_Hip;			// 0x0000
		AdsSwaySettings m_ADS;			// 0x0020
	private:
		char pad_004C[0x0004];			// 0x004C
	public:
		AdvancedHipSwaySettings m_Adv;	// 0x0050
		float m_ShellShockScale;		// 0x00F8
		bool m_OverrideHip;				// 0x00FC
		bool m_OverrideAds;				// 0x00FD
	private:
		char pad_00FE[0x0002];			// 0x00FE
	};
	ENGINE_ASSERT_SZ(SwaySettings, 0x0100);
}
