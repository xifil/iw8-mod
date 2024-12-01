#pragma once
#include "main.hpp"

namespace IW8 {
	class ClassHelper {
	public:
		uintptr_t At(int num) {
			return (uintptr_t)(this) + num;
		}

		template<typename T> T Get(int num) {
			return *reinterpret_cast<T*>((uintptr_t)(this) + num);
		}

		template<typename T> void Set(int num, T value) {
			*reinterpret_cast<T*>((uintptr_t)(this) + num) = value;
		}

		template<typename T> void Inc(int num, T value) {
			*reinterpret_cast<T*>((uintptr_t)(this) + num) += value;
		}
	};
}

#define ENGINE_ASSERT_SZ(cls, sz) static_assert(sizeof(cls) == sz, #cls " is not " #sz " bytes in size.")
