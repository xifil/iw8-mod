#include "common_core.hpp"
#include "utility/strings.hpp"

namespace Common::Utility::Strings {
	const char* va(const char* fmt, ...) {
		static thread_local VAProvider<8, 256> provider;

		va_list ap;
		va_start(ap, fmt);

		const char* result = provider.Get(fmt, ap);

		va_end(ap);
		return result;
	}

	std::vector<std::string> Split(const std::string& s, const char delim) {
		std::stringstream ss(s);
		std::string item;
		std::vector<std::string> elems;

		while (std::getline(ss, item, delim)) {
			elems.push_back(item); // elems.push_back(std::move(item)); // if C++11 (based on comment from @mchiasson)
		}

		return elems;
	}

	std::string ToLower(const std::string& text) {
		std::string result;
		std::ranges::transform(text, std::back_inserter(result), [](const unsigned char input) {
			return static_cast<char>(std::tolower(input));
		});

		return result;
	}

	std::string ToUpper(const std::string& text) {
		std::string result;
		std::ranges::transform(text, std::back_inserter(result), [](const unsigned char input) {
			return static_cast<char>(std::toupper(input));
		});

		return result;
	}

	bool StartsWith(const std::string& text, const std::string& substring) {
		return text.find(substring) == 0;
	}

	bool EndsWith(const std::string& text, const std::string& substring) {
		if (substring.size() > text.size()) return false;
		return std::equal(substring.rbegin(), substring.rend(), text.rbegin());
	}

	std::string DumpHex(const std::string& data, const std::string& separator) {
		std::string result;

		for (unsigned int i = 0; i < data.size(); ++i) {
			if (i > 0) {
				result.append(separator);
			}

			result.append(va("%02X", data[i] & 0xFF));
		}

		return result;
	}

	std::string GetClipboardData() {
		if (OpenClipboard(nullptr)) {
			std::string data;

			auto* const clipboard_data = ::GetClipboardData(1u);
			if (clipboard_data) {
				auto* const cliptext = static_cast<char*>(GlobalLock(clipboard_data));
				if (cliptext) {
					data.append(cliptext);
					GlobalUnlock(clipboard_data);
				}
			}
			CloseClipboard();

			return data;
		}
		return {};
	}

	void Strip(const char* in, char* out, size_t max) {
		if (!in || !out) {
			return;
		}

		max--;
		auto current = 0u;
		while (*in != 0 && current < max) {
			const auto color_index = (*(in + 1) - 48) >= 0xC ? 7 : (*(in + 1) - 48);

			if (*in == '^' && (color_index != 7 || *(in + 1) == '7')) {
				++in;
			}
			else {
				*out = *in;
				++out;
				++current;
			}

			++in;
		}

		*out = '\0';
	}

	std::string Convert(const std::wstring& wstr) {
		std::string result;
		result.reserve(wstr.size());

		for (const auto& chr : wstr) {
			result.push_back(static_cast<char>(chr));
		}

		return result;
	}

	std::wstring Convert(const std::string& str) {
		std::wstring result;
		result.reserve(str.size());

		for (const auto& chr : str) {
			result.push_back(static_cast<wchar_t>(chr));
		}

		return result;
	}

	std::string Replace(std::string str, const std::string& from, const std::string& to) {
		if (from.empty()) {
			return str;
		}

		size_t start_pos = 0;
		while ((start_pos = str.find(from, start_pos)) != std::string::npos) {
			str.replace(start_pos, from.length(), to);
			start_pos += to.length();
		}

		return str;
	}
}
