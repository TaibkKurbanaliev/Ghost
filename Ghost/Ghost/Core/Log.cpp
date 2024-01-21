#include "Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "../MainIncludes.h"

namespace Ghost
{
	std::shared_ptr<spdlog::logger> Ghost::Log::s_CoreLogger;

	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		s_CoreLogger = spdlog::stdout_color_mt("GHOST");
		s_CoreLogger->set_level(spdlog::level::trace);
	}
}

