#include "Main.hpp"
#include "hooks/hooks.hpp"

bool Hooks::NET_OutOfBandData_Detour(IW8::netsrc_t sock, IW8::netadr_t* adr, const unsigned __int8* format, int len) {
	return g_NET_OutOfBandData.stub<bool>(sock, adr, format, len);
}
