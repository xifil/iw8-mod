#include "Main.hpp"

#include <stdio.h>

#include "game_inc.h"
#include "debug_output.h"
#include "saved_settings.h"
#include "discord.h"
#include "structs.h"
#include "addr_utils.hpp"
#include "functions.hpp"

#include "common/utils/nt.hpp"

#include "engine/iw8/clientUIActive_t.hpp"
#include "game/game.hpp"
#include "hooks/hooks.hpp"

HMODULE g_Module = nullptr;

void MysteryFunctionDetour() {
	printf("[MysteryFunction] called, ignoring.\n");
}

void entry_point() {
	Hooks::Secondary();

	r_endframe.create(0x141966950_g, R_EndFrame_Detour);
	utils::hook::jump(0x141297580_g, Cmd_Exec_Internal);
	utils::hook::jump(0x1415E1340_g, CL_ScreenMP_DrawOverlay_Detour);
	utils::hook::jump(0x1413FD3A0_g, username_Detour);

	// # db_zones_performzoneload.create(0x140F677A0_g, DB_Zones_PerformZoneLoad_Detour);

	g_cmdsmp_clientcommand.create(0x14120B6A0_g, G_CmdsMP_ClientCommand_Detour);
	cl_inputmp_execbinding.create(0x1415E1AB0_g, CL_InputMP_ExecBinding_Detour);
	gscr_spawnbrcircle.create(0x141243AB0_g, GScr_SpawnBrCircle_Detour);
	cl_mainmp_localservers.create(0x1415EAC90_g, CL_MainMP_LocalServers_Detour);

	utils::hook::jump(0x140D6B7D0_g, CL_TransientsCollisionMP_SetTransientMode_Detour);

	printf("[Entry] hooked secondary functions\n");
}

extern "C" __declspec(dllexport) int DiscordCreate() {
	printf("[DiscordCreate] called.\n");
#	if !CLIENT_SHIP
		CreateThread(0, 0xA0, (LPTHREAD_START_ROUTINE)entry_point, 0, 0, 0);
		CreateThread(0, 0, (LPTHREAD_START_ROUTINE)DiscordThread, 0, 0, 0);
#	endif
	return 1;
}

bool s_ExecutedPostUnpack = false;
bool s_PatchedMysteryFunction = false;
void PostUnpack() {
#	if CLIENT_SHIP
		if (!s_PatchedMysteryFunction) {
			//utils::hook::jump(0x140383F80_g, MysteryFunctionDetour);
			utils::hook::set(0x143DF4548_g, MysteryFunctionDetour);
			s_PatchedMysteryFunction = true;
		}
		return;
#	else
		utils::hook::jump(0x1403061A0_g, MysteryFunctionDetour);
#	endif
	if (s_ExecutedPostUnpack) {
		return;
	}
	s_ExecutedPostUnpack = true;
	printf("[PostUnpack] called.\n");

	g_Pointers = std::make_unique<Game::Pointers>();
	printf("[PostUnpack] pointers initialized.\n");

	debug_output_init(nullptr);
	addCustomCmds();
	patchGame();

	printf("[PostUnpack] warning: this is a work in progress and bugs should be expected.\n");
}

DWORD_PTR WINAPI SetThreadAffinityMask_Detour(HANDLE hThread, DWORD_PTR dwThreadAffinityMask) {
	PostUnpack();
	return SetThreadAffinityMask(hThread, dwThreadAffinityMask);
}

HMODULE WINAPI LoadLibraryA_Detour(LPCSTR lpLibFileName) {
	PostUnpack();
	return LoadLibraryA(lpLibFileName);
}

#include <format>
LONG WINAPI TopLevelExceptionFilter(EXCEPTION_POINTERS* inf) {
	const char* exceptionCodeName = "<unknown>";
	switch (inf->ExceptionRecord->ExceptionCode) {
	case EXCEPTION_ACCESS_VIOLATION:
		exceptionCodeName = "Access violation";
		break;
	case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
		exceptionCodeName = "Array bounds exceeded";
		break;
	case EXCEPTION_BREAKPOINT:
		exceptionCodeName = "Breakpoint";
		break;
	case EXCEPTION_DATATYPE_MISALIGNMENT:
		exceptionCodeName = "Data type misalignment";
		break;
	case EXCEPTION_FLT_DENORMAL_OPERAND:
		exceptionCodeName = "Float denormal operand";
		break;
	case EXCEPTION_FLT_DIVIDE_BY_ZERO:
		exceptionCodeName = "Float / 0";
		break;
	case EXCEPTION_FLT_INEXACT_RESULT:
		exceptionCodeName = "Float inexact result";
		break;
	case EXCEPTION_FLT_INVALID_OPERATION:
		exceptionCodeName = "Float invalid operation";
		break;
	case EXCEPTION_FLT_OVERFLOW:
		exceptionCodeName = "Float overflow";
		break;
	case EXCEPTION_FLT_STACK_CHECK:
		exceptionCodeName = "Float stack check";
		break;
	case EXCEPTION_FLT_UNDERFLOW:
		exceptionCodeName = "Float underflow";
		break;
	case EXCEPTION_ILLEGAL_INSTRUCTION:
		exceptionCodeName = "Illegal instruction";
		break;
	case EXCEPTION_IN_PAGE_ERROR:
		exceptionCodeName = "In-page error";
		break;
	case EXCEPTION_INT_DIVIDE_BY_ZERO:
		exceptionCodeName = "Int / 0";
		break;
	case EXCEPTION_INT_OVERFLOW:
		exceptionCodeName = "Integer overflow";
		break;
	case EXCEPTION_INVALID_DISPOSITION:
		exceptionCodeName = "Invalid disposition";
		break;
	case EXCEPTION_NONCONTINUABLE_EXCEPTION:
		exceptionCodeName = "Non-continuable exception";
		break;
	case EXCEPTION_PRIV_INSTRUCTION:
		exceptionCodeName = "Private instruction";
		break;
	case EXCEPTION_SINGLE_STEP:
		exceptionCodeName = "Single step";
		break;
	case EXCEPTION_STACK_OVERFLOW:
		exceptionCodeName = "Stack overflow";
		break;
	}

	const auto relLoc = [](std::size_t address) {
		utils::nt::library assignedLib = utils::nt::library::get_by_address(reinterpret_cast<void*>(address));
		if (assignedLib) {
			return std::format(" ({}+0x{:08X})", assignedLib.get_name(), address - reinterpret_cast<std::size_t>(assignedLib.get_ptr()));
		}
		return std::string("");
		};
#	define AND_REL(a) a, relLoc(a)

	utils::nt::library gameLib = utils::nt::library();
	utils::nt::library modLib = utils::nt::library(g_Module);

	std::string message = "Unhandled exception caught. Instead of giving you absolutely nothing:\n";
	message += std::format("{} region: 0x{:08X} -> 0x{:08X}\n", gameLib.get_name(),
		reinterpret_cast<std::size_t>(gameLib.get_ptr()), reinterpret_cast<std::size_t>(gameLib.get_ptr()) + gameLib.get_optional_header()->SizeOfImage);
	message += std::format("{} region: 0x{:08X} -> 0x{:08X}\n", modLib.get_name(),
		reinterpret_cast<std::size_t>(modLib.get_ptr()), reinterpret_cast<std::size_t>(modLib.get_ptr()) + modLib.get_optional_header()->SizeOfImage);
	message += "---- Exception Record ----\n";
	message += std::format("Exception code: {} (0x{:08X})\n", exceptionCodeName, inf->ExceptionRecord->ExceptionCode);
	message += std::format("Exception flags: 0x{:08X}\n", inf->ExceptionRecord->ExceptionFlags);
	message += std::format("Exception address: 0x{:016X}{}\n", AND_REL(reinterpret_cast<DWORD>(inf->ExceptionRecord->ExceptionAddress)));
	message += std::format("Number of parameters: {}\n", inf->ExceptionRecord->NumberParameters);
	for (auto x = 0ul; x < std::min(inf->ExceptionRecord->NumberParameters, 15ul /*EXCEPTION_MAXIMUM_PARAMETERS*/); x++) {
		message += std::format(" > Parameter {}: 0x{:016X}\n", x, inf->ExceptionRecord->ExceptionInformation[x]);
	}
	message += "----- Context Record -----\n";
	message += std::format("Context flags: 0x{:08X}\n", inf->ContextRecord->ContextFlags);
	message += std::format("P1Home: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->P1Home));
	message += std::format("P2Home: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->P2Home));
	message += std::format("P3Home: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->P3Home));
	message += std::format("P4Home: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->P4Home));
	message += std::format("P5Home: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->P5Home));
	message += std::format("P6Home: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->P6Home));
	
	message += std::format("ContextFlags: 0x{:08X}{}\n", AND_REL(inf->ContextRecord->ContextFlags));
	message += std::format("MxCsr: 0x{:08X}{}\n", AND_REL(inf->ContextRecord->MxCsr));
	
	message += std::format("SegCs: 0x{:04X}{}\n", AND_REL(inf->ContextRecord->SegCs));
	message += std::format("SegDs: 0x{:04X}{}\n", AND_REL(inf->ContextRecord->SegDs));
	message += std::format("SegEs: 0x{:04X}{}\n", AND_REL(inf->ContextRecord->SegEs));
	message += std::format("SegFs: 0x{:04X}{}\n", AND_REL(inf->ContextRecord->SegFs));
	message += std::format("SegGs: 0x{:04X}{}\n", AND_REL(inf->ContextRecord->SegGs));
	message += std::format("SegSs: 0x{:04X}{}\n", AND_REL(inf->ContextRecord->SegSs));
	message += std::format("EFlags: 0x{:08X}{}\n", AND_REL(inf->ContextRecord->EFlags));

	message += std::format("Dr0: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->Dr0));
	message += std::format("Dr1: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->Dr1));
	message += std::format("Dr2: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->Dr2));
	message += std::format("Dr3: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->Dr3));
	message += std::format("Dr6: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->Dr6));
	message += std::format("Dr7: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->Dr7));

	message += std::format("Rax: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->Rax));
	message += std::format("Rcx: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->Rcx));
	message += std::format("Rdx: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->Rdx));
	message += std::format("Rbx: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->Rbx));
	message += std::format("Rsp: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->Rsp));
	message += std::format("Rbp: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->Rbp));
	message += std::format("Rsi: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->Rsi));
	message += std::format("Rdi: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->Rdi));
	message += std::format("R8: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->R8));
	message += std::format("R9: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->R9));
	message += std::format("R10: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->R10));
	message += std::format("R11: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->R11));
	message += std::format("R12: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->R12));
	message += std::format("R13: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->R13));
	message += std::format("R14: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->R14));
	message += std::format("R15: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->R15));

	message += std::format("Rip: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->Rip));

	message += std::format("VectorControl: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->VectorControl));

	message += std::format("DebugControl: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->DebugControl));
	message += std::format("LastBranchToRip: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->LastBranchToRip));
	message += std::format("LastBranchFromRip: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->LastBranchFromRip));
	message += std::format("LastExceptionToRip: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->LastExceptionToRip));
	message += std::format("LastExceptionFromRip: 0x{:016X}{}\n", AND_REL(inf->ContextRecord->LastExceptionFromRip));

	MessageBoxA(nullptr, message.c_str(), "iw8-mod exception hnandler", MB_OK);
	return EXCEPTION_EXECUTE_HANDLER;
}

LPTOP_LEVEL_EXCEPTION_FILTER WINAPI SetUnhandledExceptionFilter_Detour(LPTOP_LEVEL_EXCEPTION_FILTER lpTopLevelExceptionFilter) {
	PostUnpack();
	printf("[SetUnhandledExceptionFilter] setting tlef...\n");
	return SetUnhandledExceptionFilter(TopLevelExceptionFilter);
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD Reason, LPVOID lpVoid) {
	initAddrUtils();
	g_Module = hModule;
	if (Reason == DLL_PROCESS_ATTACH) {
		AllocConsole();
		FILE* Dummy;
		freopen_s(&Dummy, "CONOUT$", "w", stdout);
		freopen_s(&Dummy, "CONIN$", "r", stdin);
		SetConsoleTitleA("iw8-mod (fork of Donetsk)");

		// todo: extract blizzard compressed data
		//utils::hook::jump(0x1403061A0_g, MysteryFunctionDetour); // Mystery function 1
		//utils::hook::jump(0x1403061A0_g, MysteryFunctionDetour); // Mystery function 1

		utils::nt::library game{};
		//utils::hook::set(game.get_iat_entry("kernel32.dll", "SetThreadAffinityMask"), SetThreadAffinityMask_Detour);
		//utils::hook::set(game.get_iat_entry("kernel32.dll", "LoadLibraryA"), LoadLibraryA_Detour);
		utils::hook::set(game.get_iat_entry("kernel32.dll", "SetUnhandledExceptionFilter"), SetUnhandledExceptionFilter_Detour);

		// ultrakill dev is based
		printf("\"Culture shouldn't exist only for those who can afford it\"\n");
		printf("  - @HakitaDev\n\n");

		printf("[DllMain] base of %s is 0x%p\n", game.get_name().c_str(), game.get_ptr());

		if (utils::nt::is_wine()) {
			printf("[DllMain] you are running Modern Warfare 2019 in wine, you "
				"obviously know this already. I won't stop you, but I will say one thing: "
				"may God be with you.\n");
		}

		// prevents tact error E_REPAIR (28) from happening
		remove("Data/data/CASCRepair.mrk");
	}

	return TRUE;
}

menu_variables vars;
