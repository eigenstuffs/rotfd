/* Original array and scalar routines with private observed layouts.
 * See docs/notes/game-scalar-early-more.md. */

struct Handle {signed int tag:8;signed int index:24;};

struct HandleEntry {void *object;char pad[8];signed char tag;char tail[3];};

struct HandleManager {char pad[8];struct HandleEntry *entries;};

extern struct {char pad[0x118];struct HandleManager *manager;} lbl_801E9D24;

static inline void *resolve(const struct Handle *h) {struct HandleEntry *entry=&lbl_801E9D24.manager->entries[h->index];if(entry->tag==h->tag)return entry->object;return 0;}

extern const float lbl_80379048,lbl_8037905C,lbl_80379060;

void fn_800AB1FC(void *object) {*(void **)((char *)object+0xc)=resolve((const struct Handle *)((char *)*(void **)((char *)object+8)+0x24));*((unsigned char *)*(void **)((char *)*(void **)((char *)object+0xc)+0x94)+0x70)=1;*(float *)((char *)object+0x14)=*(float *)((char *)*(void **)((char *)object+0xc)+0xa8);*(float *)((char *)object+0x18)=lbl_80379048;if(*((signed char *)*(void **)((char *)*(void **)((char *)object+0xc)+0x94)+0x71))*(float *)((char *)object+0x1c)=lbl_8037905C;else *(float *)((char *)object+0x1c)=lbl_80379060;}
