#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/enums/AdsOffsetInterpolationType.hpp"

namespace IW8 {
	class SceneZoomSettings {
	public:
		int m_ADSZoomCount;									// 0x0000
		float m_ADSZoomFov[3];								// 0x0004
		float m_ADSReloadFov[3];							// 0x0010
		int m_ADSZoomFovTransitionTime[3];					// 0x001C
		AdsOffsetInterpolationType m_ADSZoomFovLerpType;	// 0x0028
		float m_ADSZoomInFrac;								// 0x002C
		float m_ADSZoomOutFrac;								// 0x0030
		float m_ADSFOVNVG;									// 0x0034
		float m_ADSReloadFovNVG;							// 0x0038
		bool m_ADSZoomLevelIndexResetOnToggle;				// 0x003C
	private:
		char pad_003D[0x0003];								// 0x003D
	};
	ENGINE_ASSERT_SZ(SceneZoomSettings, 0x0040);
}
