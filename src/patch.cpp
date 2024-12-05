#include "addr_utils.hpp"
#include "patch.h"

#include <stdio.h>

#include "game_inc.h"
#include "saved_settings.h"
#include "functions.hpp"

#include "engine/iw8/XUID.hpp"
#include "game/game.hpp"
#include "hooks/hooks.hpp"

int iTick = 0;
bool bFinished;
bool btoggle;

IW8::dvar_t* cl_textChatEnabled = reinterpret_cast<IW8::dvar_t*>(0x14EEB0738_g);

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
			DWORD flOldProtect;
			IW8::XUID xuid;
			xuid.RandomXUID();
			utils::hook::set<int>(0x144622BE0_g, 1);

			utils::hook::set<uintptr_t>(0x14E5C07C0_g, 0x11CB1243B8D7C31E | xuid.m_ID * xuid.m_ID);
			utils::hook::set<uintptr_t>(0x14F05ACE8_g, 0x11CB1243B8D7C31E | xuid.m_ID * xuid.m_ID);

			utils::hook::set<uintptr_t>(0x14E5C07E8_g, 0x11CB1243B8D7C31E | (xuid.m_ID * xuid.m_ID) / 6); // s_presenceData

			utils::hook::set<int>(0x14E371231_g, 1);
			utils::hook::set<int>(0x144622910_g, 2);
			utils::hook::set<int>(0x144622BE0_g, 1);

			utils::hook::set<char>(*reinterpret_cast<uintptr_t*>(0x14EE560B0_g) + 0x28, 0);
			utils::hook::set(0x14E5C0730_g, 2);

			auto get_bnet_class = reinterpret_cast<uintptr_t(*)()>(0x141660280_g);
			uintptr_t bnet_class = get_bnet_class();
			*(DWORD*)(bnet_class + 0x2F4) = 0x795230F0;
			*(DWORD*)(bnet_class + 0x2FC) = 0;
			*(BYTE*)(bnet_class + 0x2F8) = 31;

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

	// # process_script_file.create(0x141322350_g, ProcessScriptFile);
	utils::hook::jump(0x140DFE370_g, Load_ScriptFile_Detour);

	//utils::hook::jump(0x141BD3360_g, sub_141BD3360_Detour);

	//sub_141BD3360.create(0x141BD3360_g, sub_141BD3360_Detour);

	// utils::hook::copy(0x1530AD525_g, data_buf, 0x12856B); // Splash screen data

	// # sv_updateuserinfo_detour.create(0x14136d0c0_g, SV_UpdateUserinfo_f);

	db_findxassetheader.create(0x1411AA890_g, DB_FindXAssetHeader_Detour);
	db_getrawbufferinflate.create(0x1412C2AE0_g, DB_GetRawBufferInflate_Detour);
	// # ddl_setuint.create(0x1420529C0_g, DDL_SetUInt_Detour);
	// # db_pollfastfilestate.create(0x1411ADD00_g, DB_PollFastfileState_Detour);

	load_mapentsasset.create(0x140F61690_g, Load_MapEntsAsset_Detour);
	// # load_clipmapasset.create(0x140F60F40_g, Load_ClipMapAsset_Detour);
	load_xmodelasset.create(0x140F62290_g, Load_XModelAsset_Detour);
	//load_ttfasset.create(0x140F61F40_g, Load_TTFAsset_Detour);

	db_getrawbuffer.create(0x1412C29A0_g, DB_GetRawBuffer_Detour);

	utils::hook::jump(0x141528490_g, Live_IsUserSignedInToDemonware_Detour);
	utils::hook::jump(0x1417EC930_g, dwGetLogOnStatus_Detour);
	utils::hook::jump(0x1412A1EB0_g, LiveStorage_GetActiveStatsSource_Detour);
	utils::hook::jump(0x1419B96A0_g, LuaShared_LuaCall_IsDemoBuild_Detour);

	// # dvar_findvarbyname.create(0x1413E63A0_g, Dvar_FindVarByName_Detour);

	// # db_loadxfile.create(0x1411A79F0_g, DB_LoadXFile_Detour);
	CL_TransientsMP_ProcessLoadingQueue.create(0x1415F7BF0_g, CL_TransientsMP_ProcessLoadingQueue_Detour);

	lui_cod_registerdvars.create(0x1419D4500_g, LUI_CoD_RegisterDvars_Detour);
	// # net_outofbanddata.create(0x1412BB350_g, NET_OutOfBandData_Detour);
	cl_keys_event.create(0x1415BEB80_g, CL_Keys_Event_Detour);
	// # dvar_registerbool.create(0x1413E7670_g, Dvar_RegisterBool_Detour);
	// # dvar_registerstring.create(0x1413E7A70_g, Dvar_RegisterString_Detour);
	// # seh_stringed_getstring.create(0x1413CC2A0_g, SEH_StringEd_GetString_Detour);

	// # cl_createdevgui.create(0x1415B2080_g, CL_CreateDevGui_Detour);
	// # cg_mainmp_init.create(0x141792E60_g, CG_MainMP_Init_Detour);
	// # partyhost_startprivateparty.create(0x14119F0D0_g, PartyHost_StartPrivateParty_Detour);

	PM_WeaponUseAmmo.create(0x141155AF0_g, PM_WeaponUseAmmo_Detour);

	// # com_gamemode_supportsfeature.create(0x1410C8980_g, Com_GameMode_SupportsFeature_Detour);

	lui_cod_luacall_enginenotifyserver_detour_impl.create(0x1419F7160_g, LUI_CoD_LuaCall_EngineNotifyServer_Detour);

	utils::hook::jump(0x141609140_g, ProfanityFilter_IsBadWord_Detour);

	cg_overrideimpacteffecttype.create(0x141733CD0_g, CG_OverrideImpactEffectType_Detour);
	bg_getweapondismembermentenabled.create(0x141170C00_g, BG_GetWeaponDismembermentEnabled_Detour);

	// replacing Com_GameMode_GetActiveGameMode call with CheatsEnabled for jump_height dvar
	utils::hook::call(0x14110195A_g, CheatsEnabled);

	// remove FF Header version check
	// # db_checkxfileversion.create(0x1411A7840_g, DB_CheckXFileVersion_Detour);
	// utils::hook::jump(0x1411A7840_g, DB_CheckXFileVersion_Detour);
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

void patchGame()
{
	hooks();

	// patch ui_maxclients limit
	utils::hook::nop(0x140F30210_g, 5);
	utils::hook::nop(0x14119E51D_g, 5);
	utils::hook::nop(0x14136B8F8_g, 5);
	utils::hook::nop(0x1416029F0_g, 5);
	utils::hook::nop(0x1419E19A3_g, 5);

	// patch party_maxplayers limit
	utils::hook::nop(0x140F252EE_g, 5);
	utils::hook::nop(0x14119D23F_g, 5);
	utils::hook::nop(0x1410769B9_g, 5);
	utils::hook::set(0x1410769B9_g, 0xC3);
	utils::hook::nop(0x140F24B4B_g, 5);
	utils::hook::set(0x140F24B4B_g, 0xC3);
	utils::hook::nop(0x1416029E2_g, 5);
	utils::hook::nop(0x14119E52B_g, 5);
	utils::hook::nop(0x140f252EE_g, 5);
	utils::hook::nop(0x14119F13A_g, 5);
	utils::hook::nop(0x1410D32E2_g, 5);

	// removes "Services aren't ready yet." print
	utils::hook::nop(0x141504374_g, 5);

	// enable tweaking of jump_slowdownEnable dvar
	utils::hook::nop(0x1411014F5_g, 2);
	utils::hook::nop(0x141101B12_g, 2);
	utils::hook::nop(0x141101C6C_g, 2);
	utils::hook::nop(0x141101D3C_g, 2);
	utils::hook::nop(0x141101EE5_g, 2);

	// fixes lost connection issue?
	utils::hook::nop(0x14165E97E_g, 5);
	utils::hook::nop(0x14165E660_g, 5);
	utils::hook::nop(0x141665289_g, 5);
	utils::hook::nop(0x14166567D_g, 5);

	// enable functionality for jump_height dvar
	utils::hook::set<byte>(0x141101946_g, 0xEB);

	// enable friction dvar
	utils::hook::set(0x14112141E_g, (int8_t)2);

	// remove FF Header version check
	// utils::hook::set<byte>(0x1411A776B_g, 0xEB);
}