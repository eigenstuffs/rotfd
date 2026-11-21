/* Original array and scalar routines with private observed layouts.
 * See docs/notes/game-scalar-early-more.md. */

struct Handle {signed int tag:8;signed int index:24;};

struct HandleEntry {void *object;char pad[8];signed char tag;char tail[3];};

struct HandleManager {char pad[8];struct HandleEntry *entries;};

struct Holder {char pad[0x1c];struct Handle *handle;};

extern struct {char pad[0x118];struct HandleManager *manager;char tail[0x20];struct Holder *holder;} lbl_801E9D24;

static inline void *resolve_manager(struct HandleManager *manager,const struct Handle *h) {struct HandleEntry *entry=&manager->entries[h->index];if(entry->tag==h->tag)return entry->object;return 0;}

void *fn_8005E90C(void) {struct HandleManager *manager=lbl_801E9D24.manager;void *first=resolve_manager(manager,lbl_801E9D24.holder->handle);return resolve_manager(manager,*(const struct Handle **)((char *)first+0xa4));}
