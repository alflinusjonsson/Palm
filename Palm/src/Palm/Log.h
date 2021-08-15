#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Palm {
	class PALM_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define PM_CORE_TRACE(...)    ::Palm::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PM_CORE_INFO(...)     ::Palm::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PM_CORE_WARN(...)     ::Palm::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PM_CORE_ERROR(...)    ::Palm::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PM_CORE_FATAL(...)    ::Palm::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define PM_TRACE(...)         ::Palm::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PM_INFO(...)          ::Palm::Log::GetClientLogger()->info(__VA_ARGS__)
#define PM_WARN(...)          ::Palm::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PM_ERROR(...)         ::Palm::Log::GetClientLogger()->error(__VA_ARGS__)
#define PM_FATAL(...)         ::Palm::Log::GetClientLogger()->fatal(__VA_ARGS__)


