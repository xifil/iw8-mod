#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/GfxImage.hpp"

namespace IW8 {
	class MaterialTextureDef {
	public:
		std::uint8_t m_Index;	// 0x0000
	private:
		char pad_0001[0x0007];	// 0x0001
	public:
		GfxImage* m_Image;		// 0x0008
	};
	ENGINE_ASSERT_SZ(MaterialTextureDef, 0x0010);
}
