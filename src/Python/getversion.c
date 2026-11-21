/* Runtime identification in GSQE78, derived from CPython 2.1
 * Python/getversion.c. License: reference/cpython-2.1/LICENSE. */
#define PY_VERSION "2.1"
extern int sprintf(char *, const char *, ...);
extern const char *Py_GetBuildInfo(void);
extern const char *Py_GetCompiler(void);

/* Return the full version string. */



const char *
Py_GetVersion(void)
{
	static char version[250];
	sprintf(version, "%.80s (%.80s) %.80s", PY_VERSION,
		Py_GetBuildInfo(), Py_GetCompiler());
	return version;
}
