#include "Main.hpp"
#include "hooks/hooks.hpp"

int Hooks::DB_PollFastfileState_Detour(const char* zoneName) {
	if (strcmp(zoneName, "mp_donetsk_cg_ls_tr") == 0) {
		return 2;
	}

	//printf("%s\n", zoneName);

	return g_DB_PollFastfileState.stub<int>(zoneName);
}
