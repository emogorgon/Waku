#pragma once
#include "Core.h"
#include <spdlog/spdlog.h>
#include <memory>

namespace Waku{

    class WAKU_API Log
    {
    public:
        static void Init();

        static std::shared_ptr<spdlog::logger>& GetCoreLogger() {return s_CoreLogger;}
        static std::shared_ptr<spdlog::logger>& GetClientLogger() {return s_ClientLogger;}
    private:
        static std::shared_ptr<spdlog::logger> s_CoreLogger;
        static std::shared_ptr<spdlog::logger> s_ClientLogger;
    };
}

//core log macros
#define WK_CORE_ERROR(...)    ::Waku::Log::GetCoreLogger()->error(__VA_ARGS__)
#define WK_CORE_WARN(...)     ::Waku::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define WK_CORE_INFO(...)     ::Waku::Log::GetCoreLogger()->info(__VA_ARGS__)
#define WK_CORE_TRACE(...)    ::Waku::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define WK_CORE_FATAL(...)    ::Waku::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client log macros
#define WK_CLIENT_ERROR(...)  ::Waku::Log::GetClientLogger()->error(__VA_ARGS__)
#define WK_CLIENT_WARN(...)   ::Waku::Log::GetClientLogger()->warn(__VA_ARGS__)
#define WK_CLIENT_INFO(...)   ::Waku::Log::GetClientLogger()->info(__VA_ARGS__)
#define WK_CLIENT_TRACE(...)  ::Waku::Log::GetClientLogger()->trace(__VA_ARGS__)
#define WK_CLIENT_FATAL(...)  ::Waku::Log::GetClientLogger()->fatal(__VA_ARGS__)
