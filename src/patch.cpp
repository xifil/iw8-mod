#include "addr_utils.hpp"
#include "patch.h"

#include <stdio.h>

#include "game_inc.h"
#include "saved_settings.h"
#include "functions.hpp"

#include "engine/iw8/XUID.hpp"
#include "game/game.hpp"
#include "hooks/hooks.hpp"

#include "memory/memory.hpp"

int iTick = 0;
bool bFinished;
bool btoggle;

uintptr_t xuid_generated;
int collision_ticker;
void R_EndFrame_Detour() {
	if (strcmp(g_Pointers->m_Dvar_GetStringSafe("NSQLTTMRMP" /* ui_mapname */), "mp_donetsk") == 0) {
		*reinterpret_cast<int*>(0x14E385A68_g) = 80;
		*reinterpret_cast<int*>(0x14E385A78_g) = 80;
		if (collision_ticker == 60) {
			btoggle = !btoggle;
			*reinterpret_cast<int*>(0x145CC7555_g) = btoggle; // s_transientsCollisionMP_LobbyToGameStart
		}
		collision_ticker++;
	}
	else {
		*reinterpret_cast<int*>(0x14E385A68_g) = 1000;
		*reinterpret_cast<int*>(0x14E385A78_g) = 1000;
	}

	if (!bFinished) {
		if (iTick == 500) {
			utils::nt::library game{};
			IW8::XUID xuid;
			xuid.RandomXUID();

			/*
				0x144622BE0 - presumably token has been processed (looked at neighbouring string)
				0x144622910 - state?
				0x14E371231 - authed? leaving this at 0 causes a softlock at loading assets
			*/

			std::uint64_t xuidMagic = 0x11CB1243B8D7C31E;
			std::uint64_t xuidId = xuid.m_ID * xuid.m_ID;

			IW8::BNetClass* bnet = g_Pointers->m_Unk_GetBNetClass();

			bnet->m_FinishedAuth = true;

			//utils::hook::set<uintptr_t>(0x14E5C07C0_g, xuidMagic | xuidId);
			*Memory::SigScan("48 8D 3D ? ? ? ? 0F 1F 44 00 ? 48 63 C3", game.get_name(), "XUID Check #1").Add(3).Rip() // verified
				.As<std::uint64_t*>() = xuidMagic | xuidId;
			//utils::hook::set<uintptr_t>(0x14F05ACE8_g, xuidMagic | xuidId);
			*Memory::SigScan("48 8D 0D ? ? ? ? E8 ? ? ? ? 4C 8D 0D ? ? ? ? 48 89 44 24", game.get_name(), "XUID Check #2").Add(3).Rip()
				.As<std::uint64_t*>() = xuidMagic | xuidId;

			(*g_Pointers->m_s_presenceData)[0].m_Current.m_CrossTitlePresenceData.m_PlatformID = xuidMagic | xuidId / 6;

			//utils::hook::set<int>(0x14E371231_g, 1); // presumably is authed?
			*Memory::SigScan("80 3D ? ? ? ? ? 74 ? 48 89 7C 24", game.get_name(), "Auth Check #1").Add(2).Rip().Add(1)
				.As<int*>() = 1;
			bnet->m_State = 2;
			bnet->m_FinishedAuth = true;

			//IW8::dvar_t* DVARBOOL_xp_dec_dc = reinterpret_cast<IW8::dvar_t*>(0x14EE560B0_g);
			IW8::dvar_t* DVARBOOL_xp_dec_dc = Memory::SigScan("48 8B 05 ? ? ? ? 80 78 ? ? 74 ? 8B CE", game.get_name(), "DVARBOOL_xp_dec_dc").Add(3).Rip()
				.As<IW8::dvar_t*>();
			DVARBOOL_xp_dec_dc->m_Current.m_Enabled = false;

			//utils::hook::set(0x14E5C0730_g, 2);
			Memory::SigScan("4C 8D 35 ? ? ? ? 48 8B D8", game.get_name(), "Auth Check #2").Add(3).Rip()
				.As<int&>() = 2;

			bnet->m_Var3 = 0x795230F0;
			bnet->m_Var4 = 0x1F;
			bnet->m_Var5 = 0x00000000;

			printf("[R_EndFrame] patched battle.net -> loaded!\n");
			bFinished = true;
		}
		else {
			iTick += 1;
		}
	}

	r_endframe.stub<void>();
}

const char* username_Detour() {
	if (Dvars::player_name) {
		if (strcmp(saved_settings::g_player_name.c_str(), Dvars::player_name->m_Current.m_String) != 0) {
			saved_settings::g_player_name = Dvars::player_name->m_Current.m_String;
			saved_settings::Save();
		}
		return Dvars::player_name->m_Current.m_String;
	}
	else {
		return "Unknown Soldier";
	}
}

void GScr_SpawnBrCircle_Detour(uintptr_t scrContext) {
	if (Dvars::spawn_br_gas->m_Current.m_Enabled) {
		gscr_spawnbrcircle.stub<void>(scrContext);
	}
}

bool Live_IsUserSignedInToDemonware_Detour() {
	return true;
}

int dwGetLogOnStatus_Detour() {
	return 2;
}

int LiveStorage_GetActiveStatsSource_Detour() {
	return 1;
}

bool ProfanityFilter_IsBadWord_Detour() {
	return false;
}

void hooks() {
	Hooks::Essential();

	// utils::hook::jump(0x141BD3360_g, sub_141BD3360_Detour);
	// sub_141BD3360.create(0x141BD3360_g, sub_141BD3360_Detour);
	// utils::hook::copy(0x1530AD525_g, data_buf, 0x12856B); // Splash screen data
	// load_ttfasset.create(0x140F61F40_g, Load_TTFAsset_Detour);
	// remove FF Header version check
	// utils::hook::jump(0x1411A7840_g, DB_CheckXFileVersion_Detour);

#	if !CLIENT_SHIP
		bg_getweapondismembermentenabled.create(0x141170C00_g, BG_GetWeaponDismembermentEnabled_Detour);
		cg_overrideimpacteffecttype.create(0x141733CD0_g, CG_OverrideImpactEffectType_Detour);
		cl_keys_event.create(0x1415BEB80_g, CL_Keys_Event_Detour);
		CL_TransientsMP_ProcessLoadingQueue.create(0x1415F7BF0_g, CL_TransientsMP_ProcessLoadingQueue_Detour);
		db_findxassetheader.create(0x1411AA890_g, DB_FindXAssetHeader_Detour);
		db_getrawbuffer.create(0x1412C29A0_g, DB_GetRawBuffer_Detour);
		db_getrawbufferinflate.create(0x1412C2AE0_g, DB_GetRawBufferInflate_Detour);
		load_mapentsasset.create(0x140F61690_g, Load_MapEntsAsset_Detour);
		load_xmodelasset.create(0x140F62290_g, Load_XModelAsset_Detour);
		lui_cod_luacall_enginenotifyserver_detour_impl.create(0x1419F7160_g, LUI_CoD_LuaCall_EngineNotifyServer_Detour);
		lui_cod_registerdvars.create(0x1419D4500_g, LUI_CoD_RegisterDvars_Detour);
		PM_WeaponUseAmmo.create(0x141155AF0_g, PM_WeaponUseAmmo_Detour);

		utils::hook::jump(0x1417EC930_g, dwGetLogOnStatus_Detour);
		utils::hook::jump(0x141528490_g, Live_IsUserSignedInToDemonware_Detour);
		utils::hook::jump(0x1412A1EB0_g, LiveStorage_GetActiveStatsSource_Detour);
		utils::hook::jump(0x140DFE370_g, Load_ScriptFile_Detour);
		utils::hook::jump(0x1419B96A0_g, LuaShared_LuaCall_IsDemoBuild_Detour);
		utils::hook::jump(0x141609140_g, ProfanityFilter_IsBadWord_Detour);

		// replacing Com_GameMode_GetActiveGameMode call with CheatsEnabled for jump_height dvar
		utils::hook::call(0x14110195A_g, CheatsEnabled);
#	endif
}

void CL_MainMP_LocalServers_Detour(int localClientNum) {
	printf("[CL_MainMP_LocalServers] called.\n");
	cl_mainmp_localservers.stub(localClientNum); // add actual local servers first

	// this (below) was freestyle
	// iw7 looks like a good base for this though, it is the previous Infinity Ward game after all
	
	/*int* numLocalServers = reinterpret_cast<std::int32_t*>(0x14EEB1220_g);
	ClServerInfo* localServers = reinterpret_cast<ClServerInfo*>(0x14EEB1224_g);

	*numLocalServers += 1; // make room for an example server

	ClServerInfo localServerInstance;
	//XNADDR m_XNAddr;				// 0x0000
	//XSECURITY_INFO m_XNInfo;		// 0x0054
	localServerInstance.m_Addr.m_Type = netadrtype_t::NA_IP;
	localServerInstance.m_Addr.m_IP[0] = 192;
	localServerInstance.m_Addr.m_IP[1] = 168;
	localServerInstance.m_Addr.m_IP[2] = 0;
	localServerInstance.m_Addr.m_IP[3] = 134;
	localServerInstance.m_Addr.m_Port = 26016;
	localServerInstance.m_Addr.m_Flags = 1;
	localServerInstance.m_Addr.m_LocalNetID = netsrc_t::NS_MAXCLIENTS;
	localServerInstance.m_Addr.m_AddrHandleIndex = 0xFFFFFFFF;
	localServerInstance.m_Clients = 14;
	localServerInstance.m_MaxClients = 69;
	localServerInstance.m_MinPing = 1;
	localServerInstance.m_MaxPing = 250;
	localServerInstance.m_Ping = 14;
	localServerInstance.m_IsDedicated = true;
	localServerInstance.m_IsLobby = 0;
	std::strcpy(localServerInstance.m_HostName, "^1example ^2server ^7wow");
	std::strcpy(localServerInstance.m_MapName, "mp_rust");
	std::strcpy(localServerInstance.m_GameType, "dm");

	std::memcpy(localServers + (((*numLocalServers) - 1) * sizeof(ClServerInfo)), &localServerInstance, sizeof(ClServerInfo));
	
	/*
	*reinterpret_cast<std::int32_t*>(0x14EEB121C_g) = 0;
	*reinterpret_cast<std::int32_t*>(0x14EEB1220_g) = 5;
	
	std::size_t localServersAddr = 0x14EEB1224_g;
	ClServerInfo* localServers = reinterpret_cast<ClServerInfo*>(localServersAddr);

	// example servers
	ClServerInfo localServerInstance;
	//XNADDR m_XNAddr;				// 0x0000
	//XSECURITY_INFO m_XNInfo;		// 0x0054
	localServerInstance.m_Addr.m_Type = netadrtype_t::NA_IP;
	localServerInstance.m_Addr.m_IP[0] = ; // there was an external
	localServerInstance.m_Addr.m_IP[1] = ; // ip here but it was removed
	localServerInstance.m_Addr.m_IP[2] = ; // for privacy concerns.
	localServerInstance.m_Addr.m_IP[3] = ;
	localServerInstance.m_Addr.m_Port = 26016;
	localServerInstance.m_Addr.m_Flags = 1;
	localServerInstance.m_Addr.m_LocalNetID = netsrc_t::NS_MAXCLIENTS;
	localServerInstance.m_Addr.m_AddrHandleIndex = 0xFFFFFFFF;
	localServerInstance.m_Clients = 14;
	localServerInstance.m_MaxClients = 69;
	localServerInstance.m_MinPing = 1;
	localServerInstance.m_MaxPing = 250;
	localServerInstance.m_Ping = 14;
	localServerInstance.m_IsDedicated = true;
	localServerInstance.m_IsLobby = 0;
	std::strcpy(localServerInstance.m_HostName, "no");
	std::strcpy(localServerInstance.m_MapName, "mp_shipment"); // my absolute favourite map totally not overrated
	std::strcpy(localServerInstance.m_GameType, "dm"); // ffa

	std::size_t offset = 0;
	for (int x = 0; x < *reinterpret_cast<std::int32_t*>(0x14EEB1220_g); x++) {
		localServerInstance.m_Addr.m_IP[3] -= 1;
		localServerInstance.m_Addr.m_AddrHandleIndex -= 1;
		std::strcpy(localServerInstance.m_HostName, va("epic example server (%d)", x + 1));
		std::memcpy(localServers + offset, &localServerInstance, sizeof(ClServerInfo));
		offset += sizeof(ClServerInfo);
	}*/
}

void patchGame() {
	utils::nt::library game{};
	std::string mod = game.get_name();

	hooks();

	// patch ui_maxclients limit
#	if !CLIENT_SHIP
		utils::hook::nop(0x140F30210_g, 5);
		utils::hook::nop(0x14119E51D_g, 5);
		utils::hook::nop(0x14136B8F8_g, 5);
		utils::hook::nop(0x1416029F0_g, 5);
		utils::hook::nop(0x1419E19A3_g, 5);
#	endif

	// patch party_maxplayers limit
#	if !CLIENT_SHIP
		utils::hook::nop(0x140F252EE_g, 5);
		utils::hook::nop(0x14119D23F_g, 5);
		utils::hook::nop(0x1410769B9_g, 5);
		utils::hook::set(0x1410769B9_g, 0xC3);
		utils::hook::nop(0x140F24B4B_g, 5);
		utils::hook::set(0x140F24B4B_g, 0xC3);
		utils::hook::nop(0x1416029E2_g, 5);
		utils::hook::nop(0x14119E52B_g, 5);
		utils::hook::nop(0x140F252EE_g, 5);
		utils::hook::nop(0x14119F13A_g, 5);
		utils::hook::nop(0x1410D32E2_g, 5);
#	endif

	// removes "Services aren't ready yet." print
#	if !CLIENT_SHIP
		utils::hook::nop(0x141504374_g, 5);
#	endif

	// enable tweaking of jump_slowdownEnable dvar
#	if !CLIENT_SHIP
		utils::hook::nop(0x1411014F5_g, 2);
		utils::hook::nop(0x141101B12_g, 2);
		utils::hook::nop(0x141101C6C_g, 2);
		utils::hook::nop(0x141101D3C_g, 2);
		utils::hook::nop(0x141101EE5_g, 2);
#	endif

	// fixes lost connection issue?
#	if !CLIENT_SHIP
		utils::hook::nop(Memory::SigScan("E8 ? ? ? ? 8B 0D ? ? ? ? 8B 15", mod, "Lost Connection Fix #1").Get(), 5);
		utils::hook::nop(Memory::SigScan("E8 ? ? ? ? 80 3D ? ? ? ? ? 75 ? C6 05 ? ? ? ? ? E8", mod, "Lost Connection Fix #2").Get(), 5);
		utils::hook::nop(Memory::SigScan("E8 ? ? ? ? 33 D2 48 8D 4D ? 41 B8 ? ? ? ? E8 ? ? ? ? E8", mod, "Lost Connection Fix #3").Get(), 5);
		utils::hook::nop(Memory::SigScan("E8 ? ? ? ? 4C 8B 77 ? 48 C7 C6", mod, "Lost Connection Fix #4").Get(), 5);
#	endif

	// enable functionality for jump_height dvar
#	if !CLIENT_SHIP
		utils::hook::set(0x141101946_g, '\xEB');
#	endif

	// enable friction dvar
#	if !CLIENT_SHIP
		utils::hook::set(0x14112141E_g, '\x02');
#	endif

	// remove FF Header version check
	// utils::hook::set(0x1411A776B_g, '\xEB');
}