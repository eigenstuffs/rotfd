/* Original array and scalar routines with private observed layouts.
 * See docs/notes/game-scalar-early-more.md. */

struct Handle {signed int tag:8;signed int index:24;};

struct HandleEntry {void *object;char pad[8];signed char tag;char tail[3];};

struct HandleManager {char pad[8];struct HandleEntry *entries;};

struct Slots {char pad[0x60];struct Handle selected;};

struct SlotRoot {char pad[0x15058];struct Slots *slots;};

extern struct {char pad[0x118];struct HandleManager *manager;char tail[8];struct SlotRoot *root;} lbl_801E9D24;

static inline void *resolve(const struct Handle *h) {struct HandleEntry *entry=&lbl_801E9D24.manager->entries[h->index];if(entry->tag==h->tag)return entry->object;return 0;}

int fn_800774AC(void *object) {if(*(int *)((char *)object+0x17c)!=0 && *(int *)((char *)object+0xd0)==0)if(*(signed char *)((char *)resolve(&lbl_801E9D24.root->slots->selected)+0x3d)==0 && *(signed char *)((char *)object+0x1dc)==0)return 1;return 0;}
