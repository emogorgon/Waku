#pragma once
#ifdef WK_PLATFORM_WINDOWS



int main(int argc,char** argv) {
	Waku::Log::Init();
	const auto app = Waku::CreateApplication();
	app->Run();
	delete app;
}

#endif