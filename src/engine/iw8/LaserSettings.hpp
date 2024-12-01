#pragma once
#include "engine/engine_common.hpp"

namespace IW8 {
	class LaserSettings {
	public:
		bool m_ForceLaserOn;					// 0x0000
		bool m_LocalPlayerADSLaserEnabled;		// 0x0001
		bool m_LocalPlayerHipLaserEnabled;		// 0x0002
		bool m_LocalPlayerNVGADSLaserEnabled;	// 0x0003
		bool m_LocalPlayerNVGHipLaserEnabled;	// 0x0004
		bool m_RemotePlayerADSLaserEnabled;		// 0x0005
		bool m_RemotePlayerHipLaserEnabled;		// 0x0006
		bool m_RemotePlayerNVGADSLaserEnabled;	// 0x0007
		bool m_RemotePlayerNVGHipLaserEnabled;	// 0x0008
		bool m_LaserViewCenterInAds;			// 0x0009
	};
	ENGINE_ASSERT_SZ(LaserSettings, 0x000A);
}
