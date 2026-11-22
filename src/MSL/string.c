static const unsigned int K1 = 0x80808080UL;
static const unsigned int K2 = 0xfefefeffUL;

unsigned long(strlen)(const char* s)
{
    unsigned long k = -1;
    unsigned char* p = (unsigned char*) s - 1;
    do {
        k++;
    } while (*++p);

    return k;
}

char* strcpy(char* dst, const char* src)
{
	register unsigned char *destb, *fromb;
	register unsigned long w, t, align;
	register unsigned int k1;
	register unsigned int k2;

	fromb = (unsigned char*)src;
	destb = (unsigned char*)dst;

	if ((align = ((int)fromb & 3)) != ((int)destb & 3)) {
		goto bytecopy;
	}

	if (align) {
		if ((*destb = *fromb) == 0) {
			return dst;
		}

		for (align = 3 - align; align; align--) {
			if ((*(++destb) = *(++fromb)) == 0) {
				return dst;
			}
		}
		++destb;
		++fromb;
	}

	k1 = K1;
	k2 = K2;

	w = *((int*)(fromb));

	t = w + k2;

	t &= k1;
	if (t) {
		goto bytecopy;
	}
	--((int*)(destb));

	do {
		*(++((int*)(destb))) = w;
		w                    = *(++((int*)(fromb)));

		t = w + k2;
		t &= k1;
		if (t) {
			goto adjust;
		}
	} while (1);

adjust:
	++((int*)(destb));

bytecopy:
	if ((*destb = *fromb) == 0) {
		return dst;
	}

	do {
		if ((*(++destb) = *(++fromb)) == 0) {
			return dst;
		}
	} while (1);

	return dst;
}

char* strncpy(char* dst, const char* src, unsigned long n)
{
    const unsigned char* p = (const unsigned char*) src - 1;
    unsigned char* q = (unsigned char*) dst - 1;

    n++;
    while (--n) {
        if (!(*++q = *++p)) {
            while (--n) {
                *++q = 0u;
            }
            break;
        }
    }
    return dst;
}

char *strcat(char *dst, const char *src)
{
    const unsigned char *p = (const unsigned char *)src - 1;
    unsigned char *q = (unsigned char *)dst - 1;
    while (*++q) ;
    --q;
    while (*++q = *++p) ;
    return dst;
}

int strcmp(const char* str1, const char* str2)
{
    /*
     *	strcmp routine designed to minimized the number of
     *	loads and stores.  We make sure that all the loads and
     *  stores are properly aligned.
     *
     */
    register unsigned char* left = (unsigned char*) str1;
    register unsigned char* right = (unsigned char*) str2;
    unsigned int k1, k2, align, l1, r1, x;
    int result;

    /*	Check the simple case of the first byte being different. */
    l1 = *left;
    r1 = *right;
    result = (int) l1 - (int) r1;
    if (result) {
        return result;
    }

    /*
     *	If either the destination or the source are not
     *	aligned on the same boundary, we do a byte copy.
     *	Otherwise we align them to a word boundary.
     */
    if ((align = ((unsigned int) left & 3u)) != ((unsigned int) right & 3u)) {
        goto bytecopy;
    }
    if (align) {
        /*	Continuation of test of first byte. */
        if (l1 == 0u) {
            return 0;
        }
        for (align = 3u - align; align; align--) {
            l1 = *(++left);
            r1 = *(++right);
            result = (int) l1 - (int) r1;
            if (result) {
                return result;
            }
            if (l1 == 0u) {
                return 0;
            }
        }
        left++;
        right++;
    }

    /*	Strings are word aligned */

    k1 = K1;
    k2 = K2;

    /*	Load a word from each string. */
    l1 = *(unsigned int*) left;
    r1 = *(unsigned int*) right;
    /*	See comments in strcpy function. */
    x = l1 + k2;
    if (x & k1) {
        goto adjust;
    }
    while (l1 == r1) {
        /*	Load a word and increment strings. */
        left += sizeof(unsigned int);
        l1 = *((unsigned int*) left);
        right += sizeof(unsigned int);
        r1 = *((unsigned int*) right);
        x = l1 + k2;
        if (x & k1) {
            goto adjust;
        }
    }

    if (l1 > r1) {
        return 1;
    } else {
        return -1;
    }

adjust:
    l1 = *left;
    r1 = *right;
    result = (int) l1 - (int) r1;
    if (result) {
        return (int) l1 - (int) r1;
    }
bytecopy:
    if (l1 == 0u) {
        return 0;
    }
    for (;;) {
        r1 = *(++left);
        l1 = *(++right);
        result = (int) r1 - (int) l1;
        if (result) {
            return result;
        }
        if (r1 == 0u) {
            return 0;
        }
    }
}

int strncmp(const char* str1, const char* str2, unsigned long n)
{
    const unsigned char* p1 = (unsigned char*) str1 - 1;
    const unsigned char* p2 = (unsigned char*) str2 - 1;
    unsigned long c1, c2;

    n++;
    while (--n) {
        if ((c1 = *++p1) != (c2 = *++p2)) {
            return ((int) c1 - (int) c2);
        } else {
            if (!c1) {
                break;
            }
        }
    }
    return 0;
}

char* strchr(const char* str, int chr)
{
    const unsigned char* p = (unsigned char*) str - 1;
    unsigned long int c = ((unsigned long int) chr & 0xffu);
    unsigned long int ch;
    while ((ch = *++p)) {
        if (ch == c) {
            return ((char*) p);
        }
    }
    return c ? 0 : (char*) p;
}

char *strrchr(const char *str, int chr)
{
    const unsigned char *p = (const unsigned char *)str - 1;
    unsigned long c = ((unsigned long)chr & 0xffu), ch;
    const unsigned char *found = 0;
    while ((ch = *++p)) {
        if (ch == c) found = p;
    }
    return found ? (char *)found : c ? 0 : (char *)p;
}

char* strstr(const char* str, const char* pat)
{
	const unsigned char* s1 = (const unsigned char*)str - 1;
	const unsigned char* p1 = (const unsigned char*)pat - 1;
	unsigned long firstc, c1, c2;

	if ((pat == 0) || (!(firstc = *++p1))) {
		return (char*)str;
	}

	while (c1 = *++s1) {
		if (c1 == firstc) {
			const unsigned char* s2 = s1 - 1;
			const unsigned char* p2 = p1 - 1;

			while ((c1 = *++s2) == (c2 = *++p2) && c1)
				;

			if (!c2)
				return (char*)s1;
		}
	}

	return 0;
}
