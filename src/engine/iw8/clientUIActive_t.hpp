#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/MigrationPers.hpp"
#include "engine/iw8/enums/clientMigState_t.hpp"
#include "engine/iw8/enums/connstate_t.hpp"
#include "engine/iw8/enums/MigrationVerboseState.hpp"
#include "engine/iw8/enums/UIInputType.hpp"

namespace IW8 {
	class clientUIActive_t {
	public:
		bool m_Active;									// 0x0000
		bool m_IsRunning;								// 0x0001
	private:
		char pad_0002[0x0002];							// 0x0002
	public:
		int m_KeyCatchers;								// 0x0004
		connstate_t m_ConnectionState;					// 0x0008
		int m_NextScrollTime[2];						// 0x000C
		int m_DPadNextTime;								// 0x0014
		int m_DPadLatestKey;							// 0x0018
		int m_HoldKeyNextTime;							// 0x001C
		int m_HoldKeyLatest;							// 0x0020
		std::uint8_t m_FrontEndSceneState[1];			// 0x0024
		bool m_CGameInitialized;						// 0x0025
		bool m_CGameInitCalled;							// 0x0026
	private:
		char pad_0027[0x0001];							// 0x0027
	public:
		UIInputType m_LastInputType;					// 0x0028
		clientMigState_t m_MigrationState;				// 0x002C
		MigrationPers m_MigrationPers;					// 0x0030
		MigrationVerboseState m_VerboseMigrationState;	// 0x01A8
		int m_VerboseMigrationNewHost;					// 0x01AC
		int m_VerboseMigrationData;						// 0x01B0
		bool m_Invited;									// 0x01B4
	private:
		char pad_01B5[0x0003];							// 0x01B5
	};
	ENGINE_ASSERT_SZ(clientUIActive_t, 0x01B8);
}
