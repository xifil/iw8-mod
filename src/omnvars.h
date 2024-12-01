#pragma once
#include "Main.hpp"
#include "engine/iw8/OmnvarDef.hpp"
#include "engine/iw8/enums/OmnvarType.hpp"

IW8::OmnvarType BG_Omnvar_GetType(IW8::OmnvarDef* ovDef);

void DumpOmnvars();

void Cmd_Omnvar_Set_f();

void Cmd_Omnvars_Dump_f();

IW8::OmnvarDef* BG_Omnvar_GetDef(unsigned int index);