#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/AdsOffsetInterpolationType.hpp"

namespace IW8 {
	class WeaponZoomSettings {
	public:
		float m_ADSZoomFov;									// 0x0000
		AdsOffsetInterpolationType m_ADSZoomFovLerpType;	// 0x0004
		float m_ADSZoomFovXOffset;							// 0x0008
		float m_ADSReloadZoomFov;							// 0x000C
		float m_ADSReloadZoomFovXOffset;					// 0x0010
		float m_ADSNVGZoomFov;								// 0x0014
		float m_ADSNVGZoomFovXOffset;						// 0x0018
		float m_ADSNVGReloadZoomFov;						// 0x001C
		float m_ADSNVGReloadZoomFovXOffset;					// 0x0020
		float m_ADSZoomInFrac;								// 0x0024
		float m_ADSZoomOutFrac;								// 0x0028
		bool m_ADSZoomFovXOffsetOverride;					// 0x002C
		bool m_ADSReloadFovXOffsetOverride;					// 0x002D
	private:
		char pad_002E[0x0002];								// 0x002E
	};
	ENGINE_ASSERT_SZ(WeaponZoomSettings, 0x0030);
}
