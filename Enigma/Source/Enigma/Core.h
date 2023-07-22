#pragma once

#ifdef ENIGMA_PLATFORM_WINDOWS
	#ifdef ENIGMA_BUILD
		#define ENIGMA_API __declspec(dllexport)
	#else
		#define ENIGMA_API __declspec(dllimport)
	#endif
#else
	#error Platform is not supported
#endif
