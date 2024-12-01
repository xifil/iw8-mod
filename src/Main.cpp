#include "Main.hpp"

#include <stdio.h>

#include "game_inc.h"
#include "debug_output.h"
#include "saved_settings.h"
#include "discord.h"
#include "structs.h"
#include "addr_utils.hpp"
#include "functions.hpp"

#include "common/utils/nt.hpp"

#include "engine/iw8/clientUIActive_t.hpp"
#include "game/game.hpp"
#include "hooks/hooks.hpp"

void MysteryFunctionDetour() {
	printf("[MysteryFunction] called, ignoring.\n");
}

void entry_point() {
	Hooks::Secondary();

	r_endframe.create(0x141966950_g, R_EndFrame_Detour);
	utils::hook::jump(0x141297580_g, Cmd_Exec_Internal);
	utils::hook::jump(0x1415E1340_g, CL_ScreenMP_DrawOverlay_Detour);
	utils::hook::jump(0x1413FD3A0_g, username_Detour);

	// # db_zones_performzoneload.create(0x140F677A0_g, DB_Zones_PerformZoneLoad_Detour);

	g_cmdsmp_clientcommand.create(0x14120B6A0_g, G_CmdsMP_ClientCommand_Detour);
	cl_inputmp_execbinding.create(0x1415E1AB0_g, CL_InputMP_ExecBinding_Detour);
	gscr_spawnbrcircle.create(0x141243AB0_g, GScr_SpawnBrCircle_Detour);
	cl_mainmp_localservers.create(0x1415EAC90_g, CL_MainMP_LocalServers_Detour);

	utils::hook::jump(0x140D6B7D0_g, CL_TransientsCollisionMP_SetTransientMode_Detour);

	printf("[Entry] hooked secondary functions\n");
}

extern "C" __declspec(dllexport) int DiscordCreate() {
	CreateThread(0, 0xA0, (LPTHREAD_START_ROUTINE)entry_point, 0, 0, 0);
	CreateThread(0, 0, (LPTHREAD_START_ROUTINE)DiscordThread, 0, 0, 0);
	return 1;
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD Reason, LPVOID lpVoid) {
	initAddrUtils();
	utils::hook::jump(0x1403061A0_g, MysteryFunctionDetour); // Mystery function 1
	if (Reason == DLL_PROCESS_ATTACH) {
		AllocConsole();
		FILE* Dummy;
		freopen_s(&Dummy, "CONOUT$", "w", stdout);
		freopen_s(&Dummy, "CONIN$", "r", stdin);
		SetConsoleTitleA("iw8-mod (fork of Donetsk)");

		// todo: extract blizzard compressed data

		utils::nt::library game{};

		// ultrakill dev is based
		printf("\"Culture shouldn't exist only for those who can afford it\"\n");
		printf("  - @HakitaDev\n\n");

		printf("[DllMain] base of %s is 0x%p\n", game.get_name().c_str(), game.get_ptr());

		if (utils::nt::is_wine()) {
			printf("[DllMain] you are running Modern Warfare 2019 in wine, you "
				"obviously know this already. I won't stop you, but I will say one thing: "
				"may God be with you.\n");
		}

		// prevents tact error E_REPAIR (28) from happening
		remove("Data/data/CASCRepair.mrk");

		g_Pointers = std::make_unique<Game::Pointers>();
		printf("[DllMain] pointers initialized.\n");

		debug_output_init(nullptr);
		addCustomCmds();
		patchGame();

		printf("[DllMain] warning: this is a work in progress and bugs should be expected.\n");
	}

	return TRUE;
}

menu_variables vars;
