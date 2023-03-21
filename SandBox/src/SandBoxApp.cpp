#include <Waku.h>

class SandBox : public Waku::Application {
public:
	SandBox(const Waku::ApplicationSpecification& specification)
		:Application(specification){}
	~SandBox() {}
};

Waku::Application* Waku::CreateApplication(ApplicationCommandLineArgs args) {
	ApplicationSpecification spec;
	spec.Name = "Sandbox";
	spec.CommandLineArgs = args;
	
	return new SandBox(spec);
}