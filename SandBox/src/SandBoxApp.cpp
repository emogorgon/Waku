#include <Waku.h>

class SandBox : public Waku::Application {
public:
	SandBox() {

	}
	~SandBox() {

	}
	
};
Waku::Application* Waku::CreateApplication() {
	return new SandBox();
}