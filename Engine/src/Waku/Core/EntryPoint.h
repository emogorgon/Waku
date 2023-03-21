#pragma once
#ifdef WK_PLATFORM_WINDOWS

extern Waku::Application* Waku::CreateApplication(ApplicationCommandLineArgs args);


int main(int argc,char** argv) {
	Waku::Log::Init();
	const auto app = Waku::CreateApplication({argc, argv});
	app->Run();
	delete app;
}

#endif