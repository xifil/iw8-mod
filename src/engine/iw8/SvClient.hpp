#pragma once
#include "engine/engine_common.hpp"
#include "engine/iw8/gentity_s.hpp"
#include "engine/iw8/msg_t.hpp"
#include "engine/iw8/usercmd_s.hpp"
#include "engine/iw8/enums/SvClientConnectionState.hpp"
#include "engine/iw8/enums/svscmd_type.hpp"

namespace IW8 {
	class SvClient {
	public:
		virtual ~SvClient() = 0;
		virtual void SendServerCommand(svscmd_type, const char*) = 0;
		virtual void SendServerCommandMsg(svscmd_type, const msg_t*) = 0;
		virtual void ResetSnapshotFramesMyChanges() = 0;
		virtual bool IsLocalClient() = 0;
		virtual bool IsTestClient() = 0;

		SvClientConnectionState m_state;	// 0x0008
	private:
		char pad_0009[0x0007];				// 0x0009
	public:
		usercmd_s m_lastUsercmd;			// 0x0010
		gentity_s* m_gentity;				// 0x0118
	};
	ENGINE_ASSERT_SZ(SvClient, 0x0120);
}
