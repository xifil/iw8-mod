#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/GfxImage.hpp"
#include "engine/iw8/Material.hpp"
#include "engine/iw8/enums/weapOverlayReticle_t.hpp"

namespace IW8 {
	class ADSOverlay {
	public:
		Material* m_ShaderMat;			// 0x0000
		Material* m_ShaderLowResMat;	// 0x0008
		Material* m_ShaderEMPMat;		// 0x0010
		Material* m_ShaderEMPLowResMat;	// 0x0018
		GfxImage* m_ShaderImg;			// 0x0020
		GfxImage* m_ShaderLowResImg;	// 0x0028
		GfxImage* m_ShaderEMPImg;		// 0x0030
		GfxImage* m_ShaderEMPLowResImg;	// 0x0038
		bool m_ApplyVisionSet;			// 0x0040
	private:
		char pad_0041[0x0003];			// 0x0041
	public:
		weapOverlayReticle_t m_Reticle;	// 0x0044
		float m_Width;					// 0x0048
		float m_Height;					// 0x004C
		float m_WidthSplitscreen;		// 0x0050
		float m_HeightSplitscreen;		// 0x0054
		const char* m_VisionSetName;	// 0x0058
		float m_VisionSetADSFraction;	// 0x0060
		int m_VisionSetBlendInTimeMs;	// 0x0064
		int m_VisionSetBlendOutTimeMs;	// 0x0068
	private:
		char pad_006C[0x0004];			// 0x006C
	};
	ENGINE_ASSERT_SZ(ADSOverlay, 0x0070);
}
