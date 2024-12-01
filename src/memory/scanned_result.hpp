#pragma once
#include "Main.hpp"

namespace Memory {
	template <typename T>
	class ScannedResult {
	public:
		ScannedResult(void* pointer)
			: m_Pointer(pointer)
		{}

		ScannedResult(std::uintptr_t pointer)
			: m_Pointer(reinterpret_cast<void*>(pointer))
		{}

		template <typename S>
		std::enable_if_t<std::is_pointer_v<S>, S> As() {
			return static_cast<S>(this->m_Pointer);
		}

		template <typename S>
		std::enable_if_t<std::is_lvalue_reference_v<S>, S> As() {
			return *static_cast<std::add_pointer_t<std::remove_reference_t<S>>>(this->m_Pointer);
		}

		template <typename S>
		std::enable_if_t<std::is_same_v<S, std::uintptr_t>, S> As() {
			return reinterpret_cast<std::uintptr_t>(this->m_Pointer);
		}

		T* Get() {
			return this->As<T*>();
		}

		template <typename S>
		void Apply(S** result) {
			*result = static_cast<S*>(this->Get());
		}

		template <typename S>
		ScannedResult<T> Add(S offset) {
			return ScannedResult<T>(this->As<std::uintptr_t>() + offset);
		}

		template <typename S>
		ScannedResult<T> Sub(S offset) {
			return ScannedResult<T>(this->As<std::uintptr_t>() - offset);
		}

		ScannedResult<T> Rip() {
			return this->Add(this->As<std::int32_t&>()).Add(4);
		}

		ScannedResult<T> Rel() {
			return ScannedResult<T>(*this->As<void**>());
		}

		explicit operator bool() {
			return this->m_Pointer != nullptr;
		}
	private:
		void* m_Pointer;
	};
}
