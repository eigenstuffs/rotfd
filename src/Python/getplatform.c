/* Runtime identification in GSQE78, derived from CPython 2.1
 * Python/getplatform.c. License: reference/cpython-2.1/LICENSE. */
#define PLATFORM "GAMECUBE"


#ifndef PLATFORM
#define PLATFORM "unknown"
#endif

const char *
Py_GetPlatform(void)
{
	return PLATFORM;
}
