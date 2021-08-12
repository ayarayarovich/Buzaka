#pragma once

#include "Buzaka/Core/Base.h"
#include "Buzaka/Core/Log.h"

#ifdef BZ_ENABLE_ASSERTS
	#define BZ_ASSERT(x,...) { if(!(x)) { BZ_ERROR("Assertion Failed: {0}", __VA_ARGS__); BZ_DEBUGBREAK(); } }
	#define BZ_CORE_ASSERT(x,...) { if(!(x)) { BZ_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); BZ_DEBUGBREAK(); } }
#else
	#define BZ_ASSERT(...)
	#define BZ_CORE_ASSERT(...)
#endif