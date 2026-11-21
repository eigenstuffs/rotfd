/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-late.md. */


int fn_80257C58(const void *object,int *out) { int value=*(const int *)((const char *)object+108); if (value==0) return 0; *out=value; return 1; }
