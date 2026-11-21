/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-late.md. */


int fn_8025BAD4(const void *object,int *out) { int value=*(const int *)((const char *)object+124); if (value==0) return 0; *out=value; return 1; }

int fn_8025BAF4(const void *object,int *out) { int value=*(const int *)((const char *)object+120); if (value==0) return 0; *out=value; return 1; }
