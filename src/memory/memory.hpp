#pragma once
#include "Main.hpp"
#include "memory/scanned_result.hpp"

namespace Memory {
    MODULEINFO GetModuleInfo(HMODULE peModule) {
        MODULEINFO mInfo{ 0 };
        HINSTANCE hInst = peModule;

        if (!hInst)
            return mInfo;

        GetModuleInformation(GetCurrentProcess(), hInst, &mInfo, sizeof MODULEINFO);
        return mInfo;
    }

    MODULEINFO GetModuleInfo(std::string peModule) {
        return GetModuleInfo(GetModuleHandleA(peModule.c_str()));
    }

    struct MaskedSignature {
        std::vector<std::uint8_t> data{};
        std::vector<std::uint8_t> mask{};
    };

    template <typename T = void*>
    inline std::enable_if_t<std::is_pointer_v<T>, ScannedResult<std::remove_pointer_t<T>>> MaskedSigScan(MaskedSignature sig, std::string peModule) {
        std::size_t patLen = sig.mask.size();
        MODULEINFO modInfo = GetModuleInfo(peModule);
        std::size_t modBase = (std::size_t)(modInfo.lpBaseOfDll);
        std::size_t modLen = (std::size_t)(modInfo.SizeOfImage);

        for (std::size_t ix = 0; ix < modLen - patLen; ix++) {
            bool found = true;

            for (std::size_t jx = 0; jx < patLen; jx++) {
                if (sig.mask[jx] != '?' && sig.data[jx] != *(std::uint8_t*)(modBase + ix + jx)) {
                    found = false;
                    break;
                }
            }

            if (found) {
                return ScannedResult<std::remove_pointer_t<T>>((void*)(modBase + ix));
            }
        }

        return ScannedResult<std::remove_pointer_t<T>>(nullptr);
    }

    template <typename T = void*>
    inline std::enable_if_t<std::is_pointer_v<T>, ScannedResult<std::remove_pointer_t<T>>> SigScan(std::string pattern, std::string peModule, std::string name = "<unknown>") {
        MaskedSignature sig{};

        char* base = const_cast<char*>(pattern.c_str());

        for (char* cur = base; cur < base + pattern.length(); cur++) {
            if ('\?' != *cur) { // check is ?
                sig.data.push_back((std::uint8_t)(strtoul(cur, &cur, 16)));
                sig.mask.push_back('x');
                continue;
            }

            cur++;
            if ('\?' == *cur) { // check is double ?
                cur++;
            }

            sig.data.push_back((std::uint8_t)'\xFF');
            sig.mask.push_back('?');
        }

        ScannedResult<std::remove_pointer_t<T>> res = MaskedSigScan<T>(sig, peModule);
        if (res) {
            printf("[Scanner] found '%s' %s+0x%X\n", name.c_str(), peModule.c_str(), res.As<std::size_t>() - reinterpret_cast<std::size_t>(GetModuleHandleA(peModule.c_str())));
        }
        else {
            printf("[Scanner] warning: failed to find '%s' in %s (%s)\n", name.c_str(), peModule.c_str(), pattern.c_str());
        }
        return res;
    }

    template <typename T = void*>
    inline std::enable_if_t<std::is_pointer_v<T>, ScannedResult<std::remove_pointer_t<T>>> GetExport(std::string exportName, std::string peModule) {
        HMODULE mod = GetModuleHandleA(peModule.c_str());
        if (!mod) {
            printf("[Scanner] warning: failed to find module '%s' while trying to find '%s'\n", peModule.c_str(), exportName.c_str());
            return ScannedResult<std::remove_pointer_t<T>>(nullptr);
        }

        ScannedResult<std::remove_pointer_t<T>> res = ScannedResult<std::remove_pointer_t<T>>(reinterpret_cast<void*>(GetProcAddress(mod, exportName.c_str())));
        if (res) {
            printf("[Scanner] found '%s' %s+0x%X\n", exportName.c_str(), peModule.c_str(), res.As<std::size_t>() - reinterpret_cast<std::size_t>(mod));
        }
        else {
            printf("[Scanner] warning: failed to find export '%s' in %s\n", exportName.c_str(), peModule.c_str());
        }
        return res;
    }
}
