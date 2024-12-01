#pragma once
#include "Main.hpp"
#include "engine/iw8/enums/keyNum_t.hpp"

inline utils::hook::detour cl_keys_event;
void CL_Keys_Event_Detour(int localClientNum, IW8::keyNum_t key, bool down, unsigned int time, int virtualKey, int controllerIndex);

inline utils::hook::detour cl_inputmp_execbinding;
void CL_InputMP_ExecBinding_Detour(int localClientNum, int kb, IW8::keyNum_t key, int forceNotify);