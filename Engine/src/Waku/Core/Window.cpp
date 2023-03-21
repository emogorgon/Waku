#include "wkpch.h"

#ifdef WK_PLATFORM_WINDOWS
    #include "Platform/Windows/WindowsWindow.h"
#endif

namespace Waku
{
    Scope<Window> Window::Create(const WindowProps& props)
    {
#ifdef WK_PLATFORM_WINDOWS
        return CreateScope<WindowsWindow>(props);
#else
        WK_CORE_ASSERT(false, "Unknown platform!");
        return nullptr;
#endif
    }

}