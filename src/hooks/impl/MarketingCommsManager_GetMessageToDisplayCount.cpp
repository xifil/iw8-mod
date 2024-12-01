#include "Main.hpp"
#include "hooks/hooks.hpp"

std::uint32_t Hooks::MarketingCommsManager_GetMessageToDisplayCount_Detour(void* _this, int messageType) {
	std::uint32_t og = g_MarketingCommsManager_GetMessageToDisplayCount.stub<std::uint32_t>(_this, messageType);

	bool found = false;
	std::uint32_t count = 0;
	nlohmann::json crm = nlohmann::json::parse(MOTD::g_CRMPatched);
	for (auto& [jMessageType, data] : crm.items()) {
		if (strcmp(jMessageType.c_str(), std::to_string(messageType).c_str()) != 0) {
			continue;
		}

		found = true;
		for (auto& messageData : data) {
			count++;
		}
	}

	if (found) {
		return count - 1;
	}

	return og;
}
