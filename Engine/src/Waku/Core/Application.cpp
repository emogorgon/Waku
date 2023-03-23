#include "wkpch.h"
#include "Application.h"
#include "glad/glad.h"

namespace Waku {
	Application* Application::s_Instance = nullptr;

	
	Application::Application(const ApplicationSpecification& specification)
	{
		s_Instance = this;

		m_Window = Window::Create(WindowProps(m_Specification.Name));
		m_Window->SetEventCallback(WK_BIND_EVENT_FN(Application::OnEvent));
	}

	Application::~Application() {
	
	}

	void Application::OnEvent(Event& e)
	{
		//WK_CORE_TRACE("{0}",e.ToString());
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>(WK_BIND_EVENT_FN(Application::OnWindowClose));
		dispatcher.Dispatch<WindowResizeEvent>(WK_BIND_EVENT_FN(Application::OnWindowResize));
	}

	void Application::Close()
	{
		m_Running = false;

	}

	void Application::Run() {
		while (m_Running) {
			glClearColor(1, 0, 1, 1);
			glClear(GL_COLOR_BUFFER_BIT);
			m_Window->OnUpdate();
		}
	}

	bool Application::OnWindowClose(WindowCloseEvent& e)
	{
		m_Running = false;
		return true;
	}

	bool Application::OnWindowResize(WindowResizeEvent& e)
	{
		glViewport(0, 0, e.GetWidth(), e.GetHeight());
		return true;
	}
}
