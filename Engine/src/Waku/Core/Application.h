#pragma once

#include "Waku/Core/Base.h"

#include "Waku/Core/Window.h"
#include "Waku/Events/Event.h"
#include "Waku/Events/ApplicationEvent.h"

namespace Waku {

	struct ApplicationCommandLineArgs
	{
		int Count = 0;
		char** Args = nullptr;

		const char* operator[](int index) const
		{
			return Args[index];
		}
	};

	struct ApplicationSpecification
	{
		std::string Name = "Waku Application";
		ApplicationCommandLineArgs CommandLineArgs;
	};

	class WAKU_API Application
	{
	public:
		Application(const ApplicationSpecification& specification);
		virtual ~Application();

		void OnEvent(Event& e);

		Window& GetWindow() { return *m_Window; }

		void Close();
		
		static Application& Get() { return *s_Instance; }

		const ApplicationSpecification& GetSpecification() const { return m_Specification; }

		void Run();

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		
		ApplicationSpecification m_Specification;
		Scope<Window> m_Window;
		bool m_Running = true;

		static Application* s_Instance;
		//friend int ::main(int argc, char** argv);
	};

	// To be defined in CLIENT
	Application* CreateApplication(ApplicationCommandLineArgs args);

}
