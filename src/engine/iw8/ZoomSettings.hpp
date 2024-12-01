#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/SceneZoomSettings.hpp"
#include "engine/iw8/WeaponZoomSettings.hpp"

namespace IW8 {
	class ZoomSettings {
	public:
		SceneZoomSettings m_Scene;		// 0x0000
		WeaponZoomSettings m_Weapon;	// 0x0040
	};
	ENGINE_ASSERT_SZ(ZoomSettings, 0x0070);
}
