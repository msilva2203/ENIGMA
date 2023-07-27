#pragma once

#ifdef ENIGMA_PLATFORM_WINDOWS

extern Enigma::Application* Enigma::CreateApplication();

int main()
{
	Enigma::Log::Init();
	ENIGMA_CORE_TRACE("WELCOME TO ENIGMA ENGINE");
	ENIGMA_INFO("Welcome to the application");

	auto App = Enigma::CreateApplication();
	App->Run();

	delete App;
}

#endif