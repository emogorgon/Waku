#include "wkpch.h"
#include "WindowsWindow.h"

#include "Waku/Core/Assert.h"

namespace Waku
{
    static uint8_t s_GLFWWindowCount = 0;
    static void GLFWErrorCallback(int error, const char* description)
    {
        WK_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
    }
    
    WindowsWindow::WindowsWindow(const WindowProps& props)
    {
        Init(props);
    }
    
    WindowsWindow::~WindowsWindow()
    {
        Shutdown();
    }

    void WindowsWindow::OnUpdate()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Window);
    }

    void WindowsWindow::SetVSync(bool enabled)
    {
        if (enabled)
            glfwSwapInterval(1);
        else
            glfwSwapInterval(0);

        m_Data.VSync = enabled;
    }

    bool WindowsWindow::IsVSync() const
    {
        return m_Data.VSync;
    }

    void WindowsWindow::Init(const WindowProps& props)
    {
        m_Data.Title = props.Title;
        m_Data.Height = props.Height;
        m_Data.Width = props.Width;

        if (s_GLFWWindowCount == 0)
        {
            WK_CORE_INFO("Creating window {0} ({1}, {2})", m_Data.Title, m_Data.Height, m_Data.Width);
            const int success = glfwInit();
            WK_CORE_ASSERT(success, "Failed to initialize GLFW")
            glfwSetErrorCallback(GLFWErrorCallback);
        }

        {
            m_Window = glfwCreateWindow((int)props.Width, (int)props.Height, m_Data.Title.c_str(), nullptr, nullptr);
            s_GLFWWindowCount++;
        }
        glfwMakeContextCurrent(m_Window);
        glfwSetWindowUserPointer(m_Window, &m_Data);
        SetVSync(true);

    }

    void WindowsWindow::Shutdown()
    {
        glfwDestroyWindow(m_Window);
        s_GLFWWindowCount--;

        if (s_GLFWWindowCount == 0)
        {
            glfwTerminate();
        }
    }
}
