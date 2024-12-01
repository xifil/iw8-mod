#include "Main.hpp"
#include "hooks/hooks.hpp"

#include "functions.hpp"
#include "game_inc.h"

void Hooks::PartyHost_StartPrivateParty_Detour(int localClientNum, int localControllerIndex, bool currentlyActive, int hostType) {
	g_PartyHost_StartPrivateParty.stub<void>(localClientNum, localControllerIndex, currentlyActive, hostType);

	static bool autoExec = false;
	if (!autoExec) {
		auto LUI_OpenMenu = reinterpret_cast<void(*)(int localClientNum, const char* menuName, int isPopup, int isModal, int isExclusive)>(0x141B9BDB0_g);

		Cbuf_AddText("exec autoexec.cfg");
		LUI_OpenMenu(0, "CRMContainer", 0, 0, 0);
		LoadInventory();

		// skips Tutorial stuff
		Cbuf_AddText("setRankedPlayerData mpTutorialLevel -2147463171");
		Cbuf_AddText("setRankedPlayerData mpTutorialLevel2 28671");
		Cbuf_AddText("setRankedPlayerData mpTutorialLevel - 2147454979");
		Cbuf_AddText("setRankedPlayerData mpTutorialLevel2 61439");

		autoExec = true;
	}
}
