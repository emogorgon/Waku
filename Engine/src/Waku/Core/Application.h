#pragma once

#include "Layer/Layer.h"
#include "Layer/LayerStack.h"
#include "Waku/Core/Base.h"

#include "Waku/Core/Window.h"
#include "Waku/Events/Event.h"
#include "Waku/Events/ApplicationEvent.h"
#include "Waku/ImGui/ImGuiLayer.h"

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

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		ImGuiLayer* GetImGuiLayer() { return m_ImGuiLayer; }

		
		Window& GetWindow() { return *m_Window; }

		void Close();
		
		static Application& Get() { return *s_Instance; }

		const ApplicationSpecification& GetSpecification() const { return m_Specification; }

		void Run();

	private:
		bool OnWindowClose(WindowCloseEvent& e);
		bool OnWindowResize(WindowResizeEvent& e);

		ApplicationSpecification m_Specification;
		Scope<Window> m_Window;
		bool m_Running = true;

		LayerStack m_LayerStack;
		ImGuiLayer* m_ImGuiLayer;
		static Application* s_Instance;
	};

	// To be defined in CLIENT
	Application* CreateApplication(ApplicationCommandLineArgs args);

}
