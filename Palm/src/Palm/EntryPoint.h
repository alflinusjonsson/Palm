#pragma once

#ifdef PM_PLATFORM_WINDOWS

extern Palm::Application* Palm::CreateApplication();

int main(int argc, char** argv) {
	Palm::Log::Init();
	PM_CORE_WARN("Initialized Log!");
	PM_INFO("Initialized Log!");

	auto app = Palm::CreateApplication();
	app->Run();
	delete app;
}

#endif