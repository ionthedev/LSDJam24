#pragma once

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/string_cast.hpp>

#include <spdlog/spdlog.h>
#include "spdlog/fmt/ostr.h"

class Log
{
    public:
		static void Init();
		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
};

template<typename OStream, glm::length_t L, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::vec<L, T, Q>& vector)
{
	return os << glm::to_string(vector);
}

template<typename OStream, glm::length_t C, glm::length_t R, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, const glm::mat<C, R, T, Q>& matrix)
{
	return os << glm::to_string(matrix);
}

template<typename OStream, typename T, glm::qualifier Q>
inline OStream& operator<<(OStream& os, glm::qua<T, Q> quaternion)
{
	return os << glm::to_string(quaternion);
}

// Core log macros
#define PH_CORE_TRACE(...)    ::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PH_CORE_INFO(...)     ::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PH_CORE_WARN(...)     ::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PH_CORE_ERROR(...)    ::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PH_CORE_CRITICAL(...) ::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define PH_TRACE(...)         ::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PH_INFO(...)          ::Log::GetClientLogger()->info(__VA_ARGS__)
#define PH_WARN(...)          ::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PH_ERROR(...)         ::Log::GetClientLogger()->error(__VA_ARGS__)
#define PH_CRITICAL(...)      ::Log::GetClientLogger()->critical(__VA_ARGS__)
