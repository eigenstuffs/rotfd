/* Python path configuration in the GSQE78 platform port.
 * Public getters derived from CPython 2.1 Modules/getpath.c.
 * Copyright (c) 2001 Python Software Foundation; all rights reserved.
 * Upstream license: reference/cpython-2.1/LICENSE.
 * Target behavior: all four paths lazily point to the empty string.
 */
static char *prefix;
static char *exec_prefix;
static char *progpath;
static char *module_search_path;

static inline void
calculate_path(void)
{
    module_search_path = "";
    prefix = "";
    exec_prefix = "";
    progpath = "";
}

/* External interface */

char *
Py_GetPath(void)
{
    if (!module_search_path)
        calculate_path();
    return module_search_path;
}

char *
Py_GetPrefix(void)
{
    if (!module_search_path)
        calculate_path();
    return prefix;
}

char *
Py_GetExecPrefix(void)
{
    if (!module_search_path)
        calculate_path();
    return exec_prefix;
}

char *
Py_GetProgramFullPath(void)
{
    if (!module_search_path)
        calculate_path();
    return progpath;
}
