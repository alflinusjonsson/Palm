#pragma once

#ifdef PM_PLATFORM_WINDOWS
#ifdef PM_BUILD_DLL
#define PALM_API __declspec(dllexport)
#else
#define PALM_API __declspec(dllimport)
#endif
#else
#error Palm only supports Windows!
#endif

#define BIT(x) (1 << x)