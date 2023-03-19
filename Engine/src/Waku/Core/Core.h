#pragma once

#ifdef WK_PLATFORM_WINDOWS
	#ifdef WK_BUILD_DLL
		#define WAKU_API __declspec(dllexport)
	#else
		#define WAKU_API __declspec(dllimport)
	#endif
#else
	#error Waku only supports Windows!
#endif 