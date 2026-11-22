struct Handle {signed int tag:8;signed int index:24;};

struct HandleEntry {void *object;char pad[8];signed char tag;char tail[3];};

struct HandleManager {char pad[8];struct HandleEntry *entries;};

extern struct {char pad[0x118];struct HandleManager *manager;} lbl_801E9D24;

static inline void *resolve(const struct Handle *h) {struct HandleEntry *entry=&lbl_801E9D24.manager->entries[h->index];if(entry->tag==h->tag)return entry->object;return 0;}

void fn_800810B0(void *object) {*(unsigned long long *)((char *)resolve((const struct Handle *)((char *)*(void **)((char *)object+8)+0x24))+0x38)&=~0x20000ULL;}
