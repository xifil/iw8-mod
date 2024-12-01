#include "Main.hpp"
#include "hooks/hooks.hpp"

bool Hooks::DDL_SetUInt_Detour(const IW8::DDLState* state, IW8::DDLContext* ddlContext, unsigned int val) {
	//ddlContext->obfuscated = false;
	//printf("%p - %p\n", state->offset, (uintptr_t)(ddlContext->buff) + state->offset);

	return g_DDL_SetUInt.stub<bool>(state, ddlContext, val);
}