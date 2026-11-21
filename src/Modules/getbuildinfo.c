/* Build identification in GSQE78, derived from CPython 2.1
 * Modules/getbuildinfo.c. License: reference/cpython-2.1/LICENSE. */
#define DATE "Oct 16 2002"
#define TIME "20:28:05"
#define BUILD 0
extern int sprintf(char *, const char *, ...);

#ifdef macintosh
#endif

#ifndef DONT_HAVE_STDIO_H
#endif

#ifndef DATE
#ifdef __DATE__
#define DATE __DATE__
#else
#define DATE "xx/xx/xx"
#endif
#endif

#ifndef TIME
#ifdef __TIME__
#define TIME __TIME__
#else
#define TIME "xx:xx:xx"
#endif
#endif

#ifndef BUILD
#define BUILD 0
#endif


const char *
Py_GetBuildInfo(void)
{
	static char buildinfo[50];
	sprintf(buildinfo, "#%d, %.20s, %.9s", BUILD, DATE, TIME);
	return buildinfo;
}
