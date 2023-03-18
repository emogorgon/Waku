#pragma once
#include "Core.h"
namespace Waku {
	class WAKU_API Application
	{
	public:
		Application();
		virtual ~Application();
		void Run();
	};
	//To be defined by client
	Application* CreateApplication();
	
}
