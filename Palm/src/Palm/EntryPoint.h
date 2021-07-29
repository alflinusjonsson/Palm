#pragma once

#ifdef PM_PLATFORM_WINDOWS

extern Palm::Application* Palm::CreateApplication();

int main(int argc, char** argv) {
	printf("Palm Engine\n");
	auto app = Palm::CreateApplication();
	app->Run();
	delete app;
}

#endif