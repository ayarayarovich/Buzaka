#pragma once

#include "Base.h"
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/fmt/ostr.h>

namespace Buzaka {
  class Log
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
#define BZ_CORE_TRACE(...)    ::Buzaka::Log::GetCoreLogger()->trace(__VA_ARGS__);
#define BZ_CORE_INFO(...)     ::Buzaka::Log::GetCoreLogger()->info(__VA_ARGS__);
#define BZ_CORE_WARN(...)     ::Buzaka::Log::GetCoreLogger()->warn(__VA_ARGS__);
#define BZ_CORE_ERROR(...)    ::Buzaka::Log::GetCoreLogger()->error(__VA_ARGS__);
#define BZ_CORE_CRITICAL(...) ::Buzaka::Log::GetCoreLogger()->critical(__VA_ARGS__);

// Client log macros
#define BZ_TRACE(...)         ::Buzaka::Log::GetClientLogger()->trace(__VA_ARGS__);
#define BZ_INFO(...)          ::Buzaka::Log::GetClientLogger()->info(__VA_ARGS__);
#define BZ_WARN(...)          ::Buzaka::Log::GetClientLogger()->warn(__VA_ARGS__);
#define BZ_ERROR(...)         ::Buzaka::Log::GetClientLogger()->error(__VA_ARGS__);
#define BZ_CRITICAL(...)      ::Buzaka::Log::GetClientLogger()->critical(__VA_ARGS__);