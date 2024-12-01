#include "addr_utils.hpp"
#include "omnvars.h"
#include "structs.h"
#include "functions.hpp"

#include "engine/iw8/OmnvarData.hpp"
#include "engine/iw8/OmnvarDef.hpp"
#include "engine/iw8/enums/OmnvarType.hpp"
#include <game/game.hpp>

IW8::OmnvarType BG_Omnvar_GetType(IW8::OmnvarDef* ovDef)
{
	IW8::OmnvarType* type = (IW8::OmnvarType*)((char*)ovDef + 0x26);
	return *type;
}

void DumpOmnvars()
{
	auto G_Omnvar_GetData = reinterpret_cast<IW8::OmnvarData * (*)(unsigned int index, int clientNum, uintptr_t ps)>(0x140FC5110_g);
	auto BG_Omnvar_GetTypeString = reinterpret_cast<const char* (*)(IW8::OmnvarDef * omnvar)>(0x140CD5900_g);
	auto NetConstStrings_GetLuiStringIndex = reinterpret_cast<int(*)(const char* newValue, unsigned int*)>(0x1410F0F40_g);
	auto BG_Omnvar_GetValueString = reinterpret_cast<void(*)(IW8::OmnvarDef * ovDef, IW8::OmnvarData * ovData, char* retStr, unsigned int valueBufLen)>(0x140CD5980_g);

	uintptr_t psHost = ((uintptr_t)((*g_Pointers->m_g_entities) + 0x150));

	int s_omnvarDefCount = *(int*)(0x145C48518_g);
	IW8::OmnvarDef* OmnvarDefs = (IW8::OmnvarDef*)(0x145C48580_g);
	for (int i = 0; i < s_omnvarDefCount; ++i) {
		IW8::OmnvarDef* omnvar = &OmnvarDefs[i];
		IW8::OmnvarData* data = G_Omnvar_GetData(i, 0, psHost);
		const char* typeStr = BG_Omnvar_GetTypeString(omnvar);
		IW8::OmnvarType type = BG_Omnvar_GetType(omnvar);

		std::cout << "omnvar '" << omnvar->m_Name << "' (" << typeStr << ") ";
		if (type == IW8::OmnvarType::OMNVAR_TYPE_BOOL) {
			std::cout << "value(" << data->m_Current.m_Enabled << ") ";
		}
		else if (type == IW8::OmnvarType::OMNVAR_TYPE_FLOAT) {
			std::cout << "value(" << data->m_Current.m_Value << ") ";
		}
		else if (type == IW8::OmnvarType::OMNVAR_TYPE_INT) {
			std::cout << "value(" << data->m_Current.m_Integer << ") ";
		}
		else if (type == IW8::OmnvarType::OMNVAR_TYPE_UINT || type == IW8::OmnvarType::OMNVAR_TYPE_TIME) {
			std::cout << "value(" << data->m_Current.m_UnsignedInteger << ") ";
		}
		else if (type == IW8::OmnvarType::OMNVAR_TYPE_NCS_LUI) {
			char currentStr[100] = { NULL };
			BG_Omnvar_GetValueString(omnvar, data, currentStr, 100);

			std::cout << "value'" << currentStr << "' ";
		}
		else {
			std::cout << "value(" << data->m_Current.m_UnsignedInteger << ") ";
		}

		std::cout << std::endl;
	}
}

void Cmd_Omnvar_Set_f()
{
	char ovName[100];
	char newValue[100];

	auto BG_Omnvar_GetIndexByName = reinterpret_cast<unsigned int(*)(const char* name)>(0x140CD5870_g);
	auto BG_Omnvar_GetDef = reinterpret_cast<IW8::OmnvarDef * (*)(int index)>(0x140CD5830_g);
	auto G_Omnvar_GetData = reinterpret_cast<IW8::OmnvarData * (*)(unsigned int index, int clientNum, uintptr_t ps)>(0x140FC5110_g);
	auto BG_Omnvar_GetTypeString = reinterpret_cast<const char* (*)(IW8::OmnvarDef * omnvar)>(0x140CD5900_g);
	auto G_Omnvar_MarkChanged = reinterpret_cast<void(*)(IW8::OmnvarData * omnvar)>(0x140FC51B0_g);
	auto NetConstStrings_GetLuiStringIndex = reinterpret_cast<int(*)(const char* newValue, unsigned int*)>(0x1410F0F40_g);

	if (Cmd_Argc() != 3) {
		printf("setOmnvar usage: setOmnvar <omnvar_name> <value>\n");
		return;
	}

	Cmd_ArgvBuffer(1, ovName, 100);
	Cmd_ArgvBuffer(2, newValue, 100);

	unsigned int omnvarIndex = BG_Omnvar_GetIndexByName(ovName);
	if (omnvarIndex == -1) {
		printf("Omnvar %s not found\n", ovName);
		return;
	}
	IW8::OmnvarDef* ovDef = BG_Omnvar_GetDef(omnvarIndex);
	uintptr_t psHost = ((uintptr_t)((*g_Pointers->m_g_entities) + 0x150));
	IW8::OmnvarData* data = G_Omnvar_GetData(omnvarIndex, 0, psHost);
	const char* typeStr = BG_Omnvar_GetTypeString(ovDef);
	IW8::OmnvarType type = BG_Omnvar_GetType(ovDef);

	if (type == IW8::OmnvarType::OMNVAR_TYPE_BOOL) {
		char num = *newValue;
		if (num == '0' || num == '1') {
			(data->m_Current).m_Enabled = num == '1';
			G_Omnvar_MarkChanged(data);
		}
	}
	else if (type == IW8::OmnvarType::OMNVAR_TYPE_FLOAT) {
		float value = strToFloat(newValue);
		(data->m_Current).m_Value = value;
		G_Omnvar_MarkChanged(data);
	}
	else if (type == IW8::OmnvarType::OMNVAR_TYPE_INT) {
		int value = atoi(newValue);
		(data->m_Current).m_Integer = value;
		G_Omnvar_MarkChanged(data);
	}
	else if (type == IW8::OmnvarType::OMNVAR_TYPE_UINT) {
		int value = atoi(newValue);
		if ((ovDef->m_MaxValue > value) && (value > ovDef->m_MinValue)) {
			(data->m_Current).m_UnsignedInteger = value;
			G_Omnvar_MarkChanged(data);
		}
	}
	else if (type == IW8::OmnvarType::OMNVAR_TYPE_TIME) {
		int value = atoi(newValue);
		if (value < 0) {
			printf("Expected positive value for time omnvar %s\n", ovDef->m_Name);
			return;
		}
		(data->m_Current).m_Integer = value;
		G_Omnvar_MarkChanged(data);
	}
	else if (type == IW8::OmnvarType::OMNVAR_TYPE_NCS_LUI) {
		int ret = NetConstStrings_GetLuiStringIndex(newValue, &(data->m_Current).m_NCSString);
		if (ret == NULL) {
			printf("Invalid value '%s' for omnvar '%s'.\n", newValue, ovDef->m_Name);
		}
		else {
			G_Omnvar_MarkChanged(data);
		}
	}
}

void Cmd_Omnvars_Dump_f()
{
	DumpOmnvars();
}

IW8::OmnvarDef* BG_Omnvar_GetDef(unsigned int index)
{
	auto BG_Omnvar_GetDef_func = reinterpret_cast<IW8::OmnvarDef * (*)(int index)>(0x140CD5830_g);
	return BG_Omnvar_GetDef_func(index);

	/*OmnvarDef* OmnvarDefs = (OmnvarDef*)(0x145C48580_g);
	return OmnvarDefs + index;*/
}