/* Original scalar operations; provisional text-only ownership.
 * See docs/notes/game-leaf-extended.md. */
struct Entry_80056490 { char pad[24]; unsigned char *bytes; char tail[4]; }; struct Record_80056490 { char pad[44]; struct Entry_80056490 *entries; char tail[100]; };

void fn_80056490(void *object, unsigned int index) { (*(struct Record_80056490 **)((char *)object + 0x138))[*(int *)((char *)object + 0xf0)].entries[*(unsigned int *)((char *)object + 0xf4)].bytes[index] = 0; }

/* Original scalar operations; provisional text-only ownership.
 * See docs/notes/game-leaf-extended.md. */
struct Entry_800564C0 { char pad[24]; unsigned char *bytes; char tail[4]; }; struct Record_800564C0 { char pad[44]; struct Entry_800564C0 *entries; char tail[100]; };

unsigned char fn_800564C0(void *object, unsigned int index) { return (*(struct Record_800564C0 **)((char *)object + 0x138))[*(int *)((char *)object + 0xf0)].entries[*(unsigned int *)((char *)object + 0xf4)].bytes[index]; }
