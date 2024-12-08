#include "Main.hpp"
#include "game/game.hpp"
#include "hooks/hooks.hpp"

#include "functions.hpp"
#include "game_inc.h"

void Hooks::PartyHost_StartPrivateParty_Detour(int localClientNum, int localControllerIndex, bool currentlyActive, int hostType) {
	g_PartyHost_StartPrivateParty.stub<void>(localClientNum, localControllerIndex, currentlyActive, hostType);

	static bool autoExec = false;
	if (!autoExec) {
		Cbuf_AddText("exec autoexec.cfg");
		g_Pointers->m_LUI_OpenMenu(IW8::LocalClientNum_t::LOCAL_CLIENT_0, "CRMContainer", FALSE, FALSE, FALSE);
		LoadInventory();

		// skips Tutorial stuff
		Cbuf_AddText("setRankedPlayerData mpTutorialLevel -2147463171");
		Cbuf_AddText("setRankedPlayerData mpTutorialLevel2 28671");
		Cbuf_AddText("setRankedPlayerData mpTutorialLevel - 2147454979");
		Cbuf_AddText("setRankedPlayerData mpTutorialLevel2 61439");

		autoExec = true;
	}
}
