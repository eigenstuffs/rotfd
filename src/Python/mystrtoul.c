/* Adapted from CPython v2.1 Python/mystrtoul.c.
 * Copyright (c) 2001 Python Software Foundation; All Rights Reserved.
 * License: reference/cpython-2.1/LICENSE (retained with the reference source).
 * Changes: recovered MSL ctype declarations and lowercase helper.
 * Original text: 0x8019F914..0x8019FBA0.
 */
extern const unsigned char __ctype_map[];
extern const unsigned char __lower_map[];
extern int errno;
#define ERANGE 34
#define isspace(c) (__ctype_map[(unsigned char)(c)] & 6)
#define isdigit(c) (__ctype_map[(unsigned char)(c)] & 0x10)
#define isupper(c) (__ctype_map[(unsigned char)(c)] & 0x80)
static inline int tolower(int c)
{
    return c == -1 ? -1 : __lower_map[(unsigned char)c];
}

#if defined(__sgi) && defined(WITH_THREAD) && !defined(_SGI_MP_SOURCE)
#define _SGI_MP_SOURCE
#endif

/* Convert a possibly signed character to a nonnegative int */
/* XXX This assumes characters are 8 bits wide */
#ifdef __CHAR_UNSIGNED__
#define Py_CHARMASK(c)		(c)
#else
#define Py_CHARMASK(c)		((c) & 0xff)
#endif

/* strtol and strtoul, renamed to avoid conflicts */

/*
**	strtoul
**		This is a general purpose routine for converting
**		an ascii string to an integer in an arbitrary base.
**		Leading white space is ignored.  If 'base' is zero
**		it looks for a leading 0, 0x or 0X to tell which
**		base.  If these are absent it defaults to 10.
**		Base must be 0 or between 2 and 36 (inclusive).
**		If 'ptr' is non-NULL it will contain a pointer to
**		the end of the scan.
**		Errors due to bad pointers will probably result in
**		exceptions - we don't check for them.
*/



unsigned long
PyOS_strtoul(register char *str, char **ptr, int base)
{
    register unsigned long	result;	/* return value of the function */
    register int		c;	/* current input character */
    register unsigned long	temp;	/* used in overflow testing */
    int				ovf;	/* true if overflow occurred */

    result = 0;
    ovf = 0;

/* catch silly bases */
    if (base != 0 && (base < 2 || base > 36))
    {
	if (ptr)
	    *ptr = str;
	return 0;
    }

/* skip leading white space */
    while (*str && isspace(Py_CHARMASK(*str)))
	str++;

/* check for leading 0 or 0x for auto-base or base 16 */
    switch (base)
    {
    case 0:		/* look for leading 0, 0x or 0X */
	if (*str == '0')
	{
	    str++;
	    if (*str == 'x' || *str == 'X')
	    {
		str++;
		base = 16;
	    }
	    else
		base = 8;
	}
	else
	    base = 10;
	break;

    case 16:	/* skip leading 0x or 0X */
	if (*str == '0' && (*(str+1) == 'x' || *(str+1) == 'X'))
	    str += 2;
	break;
    }

/* do the conversion */
    while ((c = Py_CHARMASK(*str)) != '\0')
    {
	if (isdigit(c) && c - '0' < base)
	    c -= '0';
	else
	{
	    if (isupper(c))
		c = tolower(c);
	    if (c >= 'a' && c <= 'z')
		c -= 'a' - 10;
	    else	/* non-"digit" character */
		break;
	    if (c >= base)	/* non-"digit" character */
		break;
	}
	temp = result;
	result = result * base + c;
#ifndef MPW
	if(base == 10) {
		if(((long)(result - c) / base != (long)temp))	/* overflow */
			ovf = 1;
	}
	else {
		if ((result - c) / base != temp)	/* overflow */
			ovf = 1;
	}
#endif
	str++;
    }

/* set pointer to point to the last character scanned */
    if (ptr)
	*ptr = str;
    if (ovf)
    {
	result = (unsigned long) ~0L;
	errno = ERANGE;
    }
    return result;
}

long
PyOS_strtol(char *str, char **ptr, int base)
{
	long result;
	char sign;
	
	while (*str && isspace(Py_CHARMASK(*str)))
		str++;
	
	sign = *str;
	if (sign == '+' || sign == '-')
		str++;
	
	result = (long) PyOS_strtoul(str, ptr, base);
	
	/* Signal overflow if the result appears negative,
	   except for the largest negative integer */
	if (result < 0 && !(sign == '-' && result == -result)) {
		errno = ERANGE;
		result = 0x7fffffff;
	}
	
	if (sign == '-')
		result = -result;
	
	return result;
}
