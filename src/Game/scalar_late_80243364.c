/* Original scalar operations with private observed layouts.
 * See docs/notes/game-scalar-late.md. */


int fn_80243364(const void *object,int *out) { int value=*(const int *)((const char *)object+132); if (value==0) return 0; *out=value; return 1; }

int fn_80243384(const void *object,int *out) { int value=*(const int *)((const char *)object+128); if (value==0) return 0; *out=value; return 1; }

int fn_802433A4(const void *object,void **out) { void *value=*(void *const *)((const char *)object+0xf0); if (value) { *out=value;return 1; } return 0; }
