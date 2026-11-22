/* This module provides the necessary stubs for when dynamic loading is
   not present. */

/* Python's importdl.h type (see Python/import.c). */
struct filedescr {
	char *suffix;
	char *mode;
	unsigned char type;
};

const struct filedescr _PyImport_DynLoadFiletab[] = {
	{0, 0}
};
