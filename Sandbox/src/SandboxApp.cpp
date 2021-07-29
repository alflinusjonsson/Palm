#include <Palm.h>

class Sandbox : public Palm::Application {
public:
	Sandbox() {
	}

	~Sandbox() {
	}
};

Palm::Application* Palm::CreateApplication() {
	return new Sandbox();
}