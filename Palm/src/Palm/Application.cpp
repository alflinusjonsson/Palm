#include "pmcph.h"
#include "Application.h"

#include "Palm/Events/ApplicationEvent.h"
#include "Palm/Log.h"

namespace Palm {
	Application::Application() {
	}

	Application::~Application() {
	}

	void Application::Run() {
		WindowResizeEvent e(1280, 720);
		PM_TRACE(e);

		while (true);
	}
}