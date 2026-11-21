/* MSL retained absolute-value routines. See docs/notes/msl-arith.md. */

int abs(int n) {
    if (n < 0)
        return (-n);
    else
        return (n);
}

long labs(long x) {
	if (x < 0)
		return -x;
	else
		return x;
}

