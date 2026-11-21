/* Original engine setup and record routines with private observed layouts.
 * See docs/notes/game-scalar-middle-more.md. */

struct Handle {signed int tag:8;signed int index:24;};

struct HandleEntry {void *object;char pad[8];signed char tag;char tail[3];};

struct HandleManager {char pad[8];struct HandleEntry *entries;};

extern struct {char pad[0x118];struct HandleManager *manager;} lbl_801E9D24;

static inline void *resolve_manager(struct HandleManager *manager,const struct Handle *h) {struct HandleEntry *entry=&manager->entries[h->index];if(entry->tag==h->tag)return entry->object;return 0;}

void fn_801C7F64(const void *object,const struct Handle *handle) {void *target=resolve_manager(lbl_801E9D24.manager,handle);*(float *)((char *)target+0x10)=*(const float *)((const char *)object+0x10);*(float *)((char *)target+0x14)=*(const float *)((const char *)object+0x14);*(float *)((char *)target+0x18)=*(const float *)((const char *)object+0x18);*(float *)((char *)target+0x1c)=*(const float *)((const char *)object+0x1c);}
