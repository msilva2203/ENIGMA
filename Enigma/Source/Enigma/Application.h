#pragma once

#include "Core.h"

namespace Enigma
{

	class ENIGMA_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();

}
