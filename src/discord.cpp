#include "discord.h"
#include "discord_rpc.h"

#include "Main.hpp"

#include "addr_utils.hpp"
#include "functions.hpp"
#include "game/game.hpp"

struct DiscordInfo {
	const char* mapName;
	const char* gameType;
	int partySize;
	int partyMax;
	const char* largeImageKey;
	const char* smallImageKey;
};

bool discordInitalized;

void DiscordInitialize() {
	DiscordEventHandlers handlers;
	memset(&handlers, 0, sizeof(handlers));
	Discord_Initialize("1315310787010498592", &handlers, 1, NULL);
	discordInitalized = true;
}

time_t startTime;
void Discord_UpdateStatus_Internal(DiscordInfo info) {
	DiscordRichPresence rpc;
	memset(&rpc, 0, sizeof(rpc));
	rpc.details = info.mapName;
	rpc.state = info.gameType;
	rpc.partySize = info.partySize;
	rpc.partyMax = info.partyMax;
	rpc.startTimestamp = startTime;
	//rpc.endTimestamp = 1507665886;
	rpc.largeImageKey = info.largeImageKey;
	rpc.largeImageText = info.mapName;
	rpc.smallImageKey = info.smallImageKey;
	rpc.smallImageText = info.gameType;
	//rpc.partyId = "";
	//rpc.joinSecret = "";
	Discord_UpdatePresence(&rpc);
}

void DiscordUpdate() {
	if (discordInitalized) {
		DiscordInfo info;
		startTime = std::time(nullptr);
#		if CLIENT_SHIP
			info.partySize = 7; // placeholder
#		else
			info.partySize = *(int*)(0x14C7B0958_g);
#		endif
		info.partyMax = g_Pointers->m_Dvar_GetIntSafe("OOTQKOTRM" /* party_maxplayers */);
		if (*g_Pointers->m_s_luaInFrontend) {
			info.mapName = "In Menus";
			info.gameType = "Waiting";
			info.largeImageKey = "mw";
			info.smallImageKey = "";
		}
		else {
			const char* ui_mapname = g_Pointers->m_Dvar_GetStringSafe("NSQLTTMRMP" /* ui_mapname */);
			const char* ui_gametype = g_Pointers->m_Dvar_GetStringSafe("MOLPOSLOMO" /* ui_gametype */);

			info.mapName = GetMapName(ui_mapname);
			info.gameType = GetGameTypeName(ui_gametype);
			info.largeImageKey = ui_mapname;
			info.smallImageKey = ui_gametype;
		}
		Discord_UpdateStatus_Internal(info);
		printf("[DiscordUpdate] called.\n");
	}
}

void DiscordThread() {
	printf("[DiscordThread] initializing discord rpc...\n");
	DiscordInitialize();

	if (discordInitalized == false) {
		printf("[DiscordThread] failed to initialize discord rpc.\n");
	}
	else {
		printf("[DiscordThread] successfully initialized discord rpc.\n");
		DiscordUpdate();
	}

	while (discordInitalized) {
		bool inFrontend = *g_Pointers->m_s_luaInFrontend;

		Sleep(5000);

		if (inFrontend != *g_Pointers->m_s_luaInFrontend) {
			DiscordUpdate();
		}
	}
}