/* File modification-time query in the GSQE78 platform port.
 * Interface derived from CPython 2.1 Python/getmtime.c.
 * Copyright (c) 2001 Python Software Foundation; all rights reserved.
 * Upstream license: reference/cpython-2.1/LICENSE.
 * The original target returns 1 for every path and stream.
 */
typedef long time_t;
typedef struct { unsigned char reserved[80]; } FILE;

time_t
PyOS_GetLastModificationTime(char *path, FILE *fp)
{
    return 1;
}
