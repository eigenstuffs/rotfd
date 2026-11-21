/* Original array and scalar routines with private observed layouts.
 * See docs/notes/game-scalar-early-more.md. */

struct Handle {signed int tag:8;signed int index:24;};

struct HandleEntry {void *object;char pad[8];signed char tag;char tail[3];};

struct HandleManager {char pad[8];struct HandleEntry *entries;};

extern struct {char pad[0x118];struct HandleManager *manager;} lbl_801E9D24;

static inline void *resolve_manager(struct HandleManager *manager,const struct Handle *h) {struct HandleEntry *entry=&manager->entries[h->index];if(entry->tag==h->tag)return entry->object;return 0;}

unsigned int fn_8009FD38(void *object) {struct HandleManager *manager=lbl_801E9D24.manager;void *first=resolve_manager(manager,(const struct Handle *)((char *)object+0x24));void *second=resolve_manager(manager,(const struct Handle *)((char *)first+0x58));unsigned int bit=(*(unsigned int *)((char *)second+0x120)>>7)&1;*((unsigned char *)object+0x3dc)=bit;return bit;}
