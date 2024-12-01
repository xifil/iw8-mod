#include "engine/engine_common.hpp"
#include "engine/iw8/XUID.hpp"

#include "addr_utils.hpp"
#include "functions.hpp"
#include "game/game.hpp"

namespace IW8 {
	std::uint64_t MSG_ReadInt64(const msg_t* msg) {
		return reinterpret_cast<std::uint64_t(*)(const msg_t*)>(0x1412B9270_g)(msg);
	}

	void MSG_WriteInt64(const msg_t* msg, const std::uint64_t value) {
		reinterpret_cast<void(*)(const msg_t*, const std::uint64_t)>(0x1412BA7F0_g)(msg, value);
	}

	void XUID::Deserialize(const msg_t* msg) {
		this->m_ID = MSG_ReadInt64(msg);
	}

	void XUID::Serialize(const msg_t* msg) {
		MSG_WriteInt64(msg, this->m_ID);
	}

	XUID* XUID::FromHexString(const char* xuidString) {
		this->m_ID = I_atoui64_hex(xuidString);
		return this;
	}

	XUID* XUID::FromMsg(const msg_t* msg) {
		this->m_ID = MSG_ReadInt64(msg);
		return this;
	}

	XUID* XUID::FromString(const char* xuidString) {
		this->m_ID = I_atoui64(xuidString);
		return this;
	}

	XUID* XUID::FromUInt64(std::uint64_t id) {
		this->m_ID = id;
		return this;
	}

	XUID* XUID::FromUniversalId(std::uint64_t id) {
		this->m_ID = id;
		return this;
	}

	std::uint64_t XUID::GetUniversalId() {
		return this->m_ID;
	}

	bool XUID::IsNull() {
		return this->m_ID == 0;
	}

	bool XUID::IsValid() {
		return this->m_ID != 0;
	}

	XUID* XUID::NullXUID() {
		this->m_ID = 0;
		return this;
	}

	XUID* XUID::RandomXUID() {
		std::uint32_t* randSeed;
		std::uint32_t backupRandSeed;
		this->m_ID = 0;
		randSeed = GetRandSeed();
		backupRandSeed = *randSeed;
		*randSeed = Sys_Microseconds();
		this->m_ID = I_irand(1, 0x7FFFFFFF);
		*randSeed = backupRandSeed;
		return this;
	}

	const char* XUID::ToDevString() {
		return g_Pointers->m_j_va("%zu", this->m_ID);
	}

	const char* XUID::ToHexString() {
		return g_Pointers->m_j_va("%zx", this->m_ID);
	}

	const char* XUID::ToString() {
		return g_Pointers->m_j_va("%zu", this->m_ID);
	}

	bool XUID::operator !=(const XUID* xuid) {
		return this->m_ID != xuid->m_ID;
	}

	XUID* XUID::operator =(const XUID* xuid) {
		this->m_ID = xuid->m_ID;
		return this;
	}

	bool XUID::operator ==(const XUID* xuid) {
		return this->m_ID == xuid->m_ID;
	}
}
