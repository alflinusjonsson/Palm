#pragma once

#include "Core.h"

namespace Palm {

	class PALM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}

