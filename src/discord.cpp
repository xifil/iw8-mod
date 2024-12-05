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
	Discord_Initialize("1183441008168534016", &handlers, 1, NULL);
	discordInitalized = true;
}

__int64 startTime;
void Discord_UpdateStatus_Internal(DiscordInfo info) {
	DiscordRichPresence discordPresence;
	memset(&discordPresence, 0, sizeof(discordPresence));
	discordPresence.details = info.mapName;
	discordPresence.state = info.gameType;
	discordPresence.partySize = info.partySize;
	discordPresence.partyMax = info.partyMax;
	discordPresence.startTimestamp = startTime;
	//discordPresence.endTimestamp = 1507665886;
	discordPresence.largeImageKey = info.largeImageKey;
	discordPresence.largeImageText = info.mapName;
	discordPresence.smallImageKey = info.smallImageKey;
	discordPresence.smallImageText = info.gameType;
	/*discordPresence.partyId = "";
	discordPresence.joinSecret = "";*/
	Discord_UpdatePresence(&discordPresence);
}

void DiscordUpdate() {
	if (discordInitalized) {
		DiscordInfo info;
		bool inFrontend = *g_Pointers->m_s_luaInFrontend;
		const char* dvarMap = g_Pointers->m_Dvar_GetStringSafe("NSQLTTMRMP" /* ui_mapname */);
		const char* dvarMode = g_Pointers->m_Dvar_GetStringSafe("MOLPOSLOMO" /* ui_gametype */);
		startTime = std::time(0);
		//info.partySize = *(int*)(0x14C7B0958_g);
		info.partySize = 7;
		info.partyMax = Dvar_GetIntSafe("OOTQKOTRM" /* party_maxplayers */);
		if (inFrontend) {
			info.mapName = "In Menus";
			info.gameType = "Waiting";
			info.largeImageKey = "mw";
			info.smallImageKey = "";
		}
		else {
			info.mapName = GetMapName(dvarMap);
			info.gameType = GetGametypeName(dvarMode);
			info.largeImageKey = dvarMap;
			info.smallImageKey = dvarMode;
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