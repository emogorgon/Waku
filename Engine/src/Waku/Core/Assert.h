﻿#pragma once

#include "Waku/Core/Base.h"
#include "Waku/Core/Log.h"
#include <filesystem>

#ifdef WK_ENABLE_ASSERTS

    // Alteratively we could use the same "default" message for both "WITH_MSG" and "NO_MSG" and
    // provide support for custom formatting by concatenating the formatting string instead of having the format inside the default message
    #define WK_INTERNAL_ASSERT_IMPL(type, check, msg, ...) { if(!(check)) { WK##type##ERROR(msg, __VA_ARGS__); WK_DEBUGBREAK(); } }
    #define WK_INTERNAL_ASSERT_WITH_MSG(type, check, ...) WK_INTERNAL_ASSERT_IMPL(type, check, "Assertion failed: {0}", __VA_ARGS__)
    #define WK_INTERNAL_ASSERT_NO_MSG(type, check) WK_INTERNAL_ASSERT_IMPL(type, check, "Assertion '{0}' failed at {1}:{2}", WK_STRINGIFY_MACRO(check), std::filesystem::path(__FILE__).filename().string(), __LINE__)

    #define WK_INTERNAL_ASSERT_GET_MACRO_NAME(arg1, arg2, macro, ...) macro
    #define WK_INTERNAL_ASSERT_GET_MACRO(...) WK_EXPAND_MACRO( WK_INTERNAL_ASSERT_GET_MACRO_NAME(__VA_ARGS__, WK_INTERNAL_ASSERT_WITH_MSG, WK_INTERNAL_ASSERT_NO_MSG) )

    // Currently accepts at least the condition and one additional parameter (the message) being optional
    #define WK_ASSERT(...) WK_EXPAND_MACRO( WK_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_, __VA_ARGS__) )
    #define WK_CORE_ASSERT(...) WK_EXPAND_MACRO( WK_INTERNAL_ASSERT_GET_MACRO(__VA_ARGS__)(_CORE_, __VA_ARGS__) )
#else
    #define WK_ASSERT(...)
    #define WK_CORE_ASSERT(...)
#endif