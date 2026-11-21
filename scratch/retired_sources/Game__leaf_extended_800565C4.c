/* Original scalar operations; provisional text-only ownership.
 * See docs/notes/game-leaf-extended.md. */
struct Entry_800565C4 { char pad[20]; unsigned char *bytes; char tail[8]; }; struct Record_800565C4 { char pad[44]; struct Entry_800565C4 *entries; char tail[100]; };

void fn_800565C4(void *object, unsigned int index) { (*(struct Record_800565C4 **)((char *)object + 0x138))[*(int *)((char *)object + 0xf0)].entries[*(unsigned int *)((char *)object + 0xf4)].bytes[index] = 0; }

/* Original scalar operations; provisional text-only ownership.
 * See docs/notes/game-leaf-extended.md. */
struct Entry_800565F4 { char pad[20]; unsigned char *bytes; char tail[8]; }; struct Record_800565F4 { char pad[44]; struct Entry_800565F4 *entries; char tail[100]; };

unsigned char fn_800565F4(void *object, unsigned int index) { return (*(struct Record_800565F4 **)((char *)object + 0x138))[*(int *)((char *)object + 0xf0)].entries[*(unsigned int *)((char *)object + 0xf4)].bytes[index]; }

/* Original scalar operations; provisional text-only ownership.
 * See docs/notes/game-leaf-extended.md. */
struct Record_80056620 { char pad[32]; unsigned char bytes[8]; char tail[108]; };

unsigned char fn_80056620(void *object, unsigned int index) { ++*(unsigned int *)((char *)object + 0x124); return (*(struct Record_80056620 **)((char *)object + 0x138))[*(int *)((char *)object + 0xf0)].bytes[index]; }

/* Original scalar operations; provisional text-only ownership.
 * See docs/notes/game-leaf-extended.md. */
struct Record_80056648 { char pad[32]; unsigned char bytes[8]; char tail[108]; };

void fn_80056648(void *object, unsigned int index) { (*(struct Record_80056648 **)((char *)object + 0x138))[*(int *)((char *)object + 0xf0)].bytes[index] = 0; }
