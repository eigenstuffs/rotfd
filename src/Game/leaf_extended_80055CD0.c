/* Original scalar operations; provisional text-only ownership.
 * See docs/notes/game-leaf-extended.md. */
struct Record_80055CD0 { char pad[4]; unsigned int value; char tail[140]; };

unsigned int fn_80055CD0(const void *object, int index) { if (index == -1) index = *(const int *)((const char *)object + 0xf0); return (*(struct Record_80055CD0 *const *)((const char *)object + 0x138))[index].value; }

/* Original scalar operations; provisional text-only ownership.
 * See docs/notes/game-leaf-extended.md. */
struct Record_80055CF0 { char pad[8]; unsigned int value; char tail[136]; };

unsigned int fn_80055CF0(const void *object, int index) { if (index == -1) index = *(const int *)((const char *)object + 0xf0); return (*(struct Record_80055CF0 *const *)((const char *)object + 0x138))[index].value; }

/* Original scalar operations; provisional text-only ownership.
 * See docs/notes/game-leaf-extended.md. */
struct Record_80055D10 { char pad[12]; unsigned int value; char tail[132]; };

unsigned int fn_80055D10(const void *object, int index) { if (index == -1) index = *(const int *)((const char *)object + 0xf0); return (*(struct Record_80055D10 *const *)((const char *)object + 0x138))[index].value; }

/* Original scalar operations; provisional text-only ownership.
 * See docs/notes/game-leaf-extended.md. */
struct Record_80055D30 { char pad[20]; unsigned int value; char tail[124]; };

unsigned int fn_80055D30(const void *object, int index) { if (index == -1) index = *(const int *)((const char *)object + 0xf0); return (*(struct Record_80055D30 *const *)((const char *)object + 0x138))[index].value; }

/* Original scalar operations; provisional text-only ownership.
 * See docs/notes/game-leaf-extended.md. */
struct Record_80055D50 { char pad[24]; unsigned int value; char tail[120]; };

unsigned int fn_80055D50(const void *object, int index) { if (index == -1) index = *(const int *)((const char *)object + 0xf0); return (*(struct Record_80055D50 *const *)((const char *)object + 0x138))[index].value; }

/* Original scalar operations; provisional text-only ownership.
 * See docs/notes/game-leaf-extended.md. */
struct Record_80055D70 { char pad[28]; unsigned int value; char tail[116]; };

unsigned int fn_80055D70(const void *object, int index) { if (index == -1) index = *(const int *)((const char *)object + 0xf0); return (*(struct Record_80055D70 *const *)((const char *)object + 0x138))[index].value; }
