/* Original scalar operations; provisional text-only ownership.
 * See docs/notes/game-leaf-extended.md. */
struct Entry_80056540 { char pad[28]; unsigned char *bytes; char tail[0]; }; struct Record_80056540 { char pad[44]; struct Entry_80056540 *entries; char tail[100]; };

void fn_80056540(void *object, unsigned int index) { (*(struct Record_80056540 **)((char *)object + 0x138))[*(int *)((char *)object + 0xf0)].entries[*(unsigned int *)((char *)object + 0xf4)].bytes[index] = 0; }
