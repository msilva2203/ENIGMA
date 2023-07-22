#pragma once

#ifdef ENIGMA_PLATFORM_WINDOWS

extern Enigma::Application* Enigma::CreateApplication();

int main()
{
	printf("ENIGMA ENGINE");
	auto App = Enigma::CreateApplication();
	App->Run();

	delete App;

	return 0;
}

#endif