#pragma once

/// Platform check
#ifndef BZ_PLATFORM_WINDOWS
  #error Buzaka supports only Windows!
#endif

#ifdef BZ_DEBUG
	#if defined(BZ_PLATFORM_WINDOWS)
		#define BZ_DEBUGBREAK() __debugbreak()
	#elif defined(BZ_PLATFORM_LINUX)
		#include <signal.h>
		#define BZ_DEBUGBREAK() raise(SIGTRAP)
	#else
		#error "Platform doesn't support debugbreak yet!"
	#endif
	#define BZ_ENABLE_ASSERTS
#else
	#define BZ_DEBUGBREAK()
#endif

#define BZ_BIND_EVENT_FUNC(func) std::bind(&func, this, std::placeholders::_1)