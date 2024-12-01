#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/CreateFxPaletteDef.hpp"

namespace IW8 {
	class CreateFxAssetData {
	public:
		std::uint16_t m_FxPaletteCount;		// 0x0000
	private:
		char pad_0002[0x0006];				// 0x0002
	public:
		CreateFxPaletteDef* m_FxPalette;	// 0x0008
	};
	ENGINE_ASSERT_SZ(CreateFxAssetData, 0x0010);
}
