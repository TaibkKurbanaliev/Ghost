#pragma once

#include "../MainIncludes.h"

namespace Ghost
{
	class Log
	{
	public:
		static void Init();

		static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
	};
}

// Core log macros
#define GHOST_CORE_ERROR(...)		::Ghost::Log::GetCoreLogger()->error(__VA_ARGS__)
#define GHOST_CORE_WARN(...)		::Ghost::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define GHOST_CORE_TRACE(...)		::Ghost::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define GHOST_CORE_INFO(...)		::Ghost::Log::GetCoreLogger()->info(__VA_ARGS__)
#define GHOST_CORE_FATAL(...)		::Ghost::Log::GetCoreLogger()->fatal(__VA_ARGS__)

