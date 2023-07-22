#pragma once

#include "Core.h"
#include "spdlog/spdlog.h"

#include <memory.h>

namespace Enigma
{

	class ENIGMA_API Log
	{
	public:
		static void Init();

		static inline std::shared_ptr<spdlog::logger>& GetCoreLogger() { return CoreLogger; }
		static inline std::shared_ptr<spdlog::logger>& GetClientLogger() { return ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> CoreLogger;
		static std::shared_ptr<spdlog::logger> ClientLogger;

	};

}

#ifndef ENIGMA_CONFIG_DIST

// Core Logging
	#define ENIGMA_CORE_TRACE(...)     Enigma::Log::GetCoreLogger()->trace(__VA_ARGS__)
	#define ENIGMA_CORE_INFO(...)      Enigma::Log::GetCoreLogger()->info(__VA_ARGS__)
	#define ENIGMA_CORE_WARNING(...)   Enigma::Log::GetCoreLogger()->warn(__VA_ARGS__)
	#define ENIGMA_CORE_ERROR(...)     Enigma::Log::GetCoreLogger()->error(__VA_ARGS__)
	#define ENIGMA_CORE_FATAL(...)     Enigma::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client Logging
	#define ENIGMA_TRACE(...)          Enigma::Log::GetClientLogger()->trace(__VA_ARGS__)
	#define ENIGMA_INFO(...)           Enigma::Log::GetClientLogger()->info(__VA_ARGS__)
	#define ENIGMA_WARNING(...)        Enigma::Log::GetClientLogger()->warn(__VA_ARGS__)
	#define ENIGMA_ERROR(...)          Enigma::Log::GetClientLogger()->error(__VA_ARGS__)
	#define ENIGMA_FATAL(...)          Enigma::Log::GetClientLogger()->fatal(__VA_ARGS__)

#else
	#define ENIGMA_CORE_TRACE(...)     
	#define ENIGMA_CORE_INFO(...)      
	#define ENIGMA_CORE_WARNING(...)   
	#define ENIGMA_CORE_ERROR(...)     
	#define ENIGMA_CORE_FATAL(...)     

	#define ENIGMA_TRACE(...)      
	#define ENIGMA_INFO(...)       
	#define ENIGMA_WARNING(...)    
	#define ENIGMA_ERROR(...)      
	#define ENIGMA_FATAL(...)      
#endif