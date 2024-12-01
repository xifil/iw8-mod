#include "Main.hpp"
#include "functions.hpp"
#include "hooks/hooks.hpp"

void Hooks::CG_MainMP_Init_Detour(int localClientNum, int serverMessageNum, int serverCommandSequence, int clientNum, void* hunkUser) {
	g_CG_MainMP_Init.stub<void>(localClientNum, serverMessageNum, serverCommandSequence, clientNum, hunkUser);
	Cbuf_AddText("set cl_textChatEnabled 1");
}
