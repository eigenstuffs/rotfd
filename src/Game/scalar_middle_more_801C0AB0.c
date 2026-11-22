struct Handle {signed int tag:8;signed int index:24;};

struct HandleEntry {void *object;char pad[8];signed char tag;char tail[3];};

struct HandleManager {char pad[8];struct HandleEntry *entries;};

extern struct {char pad[0x118];struct HandleManager *manager;} lbl_801E9D24;

static inline void *resolve_manager(struct HandleManager *manager,const struct Handle *h) {struct HandleEntry *entry=&manager->entries[h->index];if(entry->tag==h->tag)return entry->object;return 0;}

signed char fn_801C0AB0(const struct Handle *a,const struct Handle *b) {struct HandleManager *manager=lbl_801E9D24.manager;void *first=resolve_manager(manager,a);void *second=resolve_manager(manager,b);return first==second;}
