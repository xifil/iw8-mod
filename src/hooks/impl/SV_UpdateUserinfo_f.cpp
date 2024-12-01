#include "Main.hpp"
#include "game/game.hpp"
#include "hooks/hooks.hpp"

void Hooks::SV_UpdateUserinfo_f_Detour(void* cl) {
	// more checks can be added here (it's patched in current mw19, vanguard, and mwii, could probably find the actual fix there)
	if (!strlen(g_Pointers->m_Info_ValueForKey(g_Pointers->m_SV_Cmd_Argv(1), "platform"))) {
		return;
	}

	g_SV_UpdateUserinfo_f.stub<void>(cl);
}
