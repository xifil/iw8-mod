#pragma once
#include <Windows.h>
#include <winternl.h>
#include <iostream>
#include <fstream>
#include <string>

#include <dxgi1_5.h>
#include <d3d12.h>
#include <intrin.h>
#include <Psapi.h>


#include "common/utils/hook.hpp"
#include "common/utils/hardware_breakpoint.hpp"

#include "ini.h"
#include "json.hpp"

#pragma warning(disable : 4996)
#pragma comment(lib, "Gdi32.lib")
#pragma comment(lib, "user32.lib")
#pragma comment(lib, "ws2_32.lib")

#define CLIENT_SHIP 0


struct menu_variables {
	bool bInitiateMenu;
	bool bMenuOpen;

};
extern menu_variables vars;

struct DvarPair
{
	const char* m_key;
	const char* m_value;
};
inline bool IsBadPointer(uintptr_t* ptr)
{
	__try
	{
		volatile auto result = *ptr;
	}
	__except (EXCEPTION_EXECUTE_HANDLER)
	{
		return true;
	}
	return false;
}

struct DvarMap
{
	DvarPair m_pairs[10000];
};
extern int g_dvarmapcount;
extern DvarPair g_dvarmap[6821];

struct shaderOverride_t
{
	float scrollRateX;
	float scrollRateY;
	float scrollRateR;
	float tilingX;
	float tilingY;
	float rotation;
	float alpha;
	float emissive;
	float atlasTime;
};

struct GfxSceneHudOutlineInfo
{
	unsigned int color;
	float scopeStencil;
	bool drawOccludedPixels;
	bool drawNonOccludedPixels;
	bool fill;
	bool useAlternateColor;
	bool forSpectator;
	bool specialActive;
	unsigned __int8 renderMode;
	unsigned __int8 lineWidth;
	unsigned __int8 temperatureSet;
	unsigned int mapEntLookup;
	float temperatureBase;
	float temperatureScale;
	float characterEVOffset;
};

namespace MOTD {
	inline const char* g_CRMPatched =
R"({
	"1": [
		{
			"message_index": 0,
			"title": "^1Welcome to iw8-mod!^7",
			"content_long": "This mod is a work-in-progress and should not be demonstrated as a finished product.\\n\\nAny bugs or errors found should be reported to ^4@lifix^7 or ^4@xifil^7 on Discord.\\n\\n^7https://discord.gg/dPzJajt",
			"checksum": "motd-30112024",
			"layout_type": 0,
			"location_id": 1,
			"message_id": "1"
		}
	],
	"2": [
		{
			"message_index": 0,
			"title": "Connecting with friends",
			"content_long": "Radmin VPN or Hamachi is still currently required as there is no working server browser or master server. After connecting with other players through this software, you will see their lobbies in your server list.",
			"checksum": "msg-0",
			"layout_type": 0,
			"location_id": 1,
			"message_id": "1"
		}
	],
	"8": [
		{
			"message_index": 0,
			"title": "30/11/24 Changelog",
			"content_short": "- added motd and patch notes\\n- added json parsing for said motd and patch notes\\n- fixed map image on server list",
			"checksum": "cl-30112024",
			"layout_type": 0,
			"location_id": 1,
			"message_id": "1"
		}
	]
})";
}
