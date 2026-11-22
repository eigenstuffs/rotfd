struct Handle {signed int tag:8; signed int index:24;};struct Entry {void *object;char pad[8];signed char tag;char tail[3];};struct Manager {char pad[8];struct Entry *entries;};extern struct {char pad[0x118];struct Manager *manager;} lbl_801E9D24;static inline void *resolve(const struct Handle *h) {struct Entry *entry=&lbl_801E9D24.manager->entries[h->index];if(entry->tag==h->tag)return entry->object;return 0;}

void fn_802534EC(const void *object) {*((unsigned char *)resolve((const struct Handle *)((const char *)object+0x48))+0x131)=1;}
