/* Original engine array and lifetime routines with private observed layouts.
 * See docs/notes/game-engine-loops.md. */

struct Handle {signed int tag:8;signed int index:24;};

struct HandleEntry {void *object;char pad[8];signed char tag;char tail[3];};

struct HandleManager {char pad[8];struct HandleEntry *entries;};

extern struct {char pad[0x118];struct HandleManager *manager;} lbl_801E9D24;

static inline void *resolve_manager(struct HandleManager *manager,const struct Handle *h) {struct HandleEntry *entry=&manager->entries[h->index];if(entry->tag==h->tag)return entry->object;return 0;}

struct Node {char pad[0x88];struct Handle handle;char tail[4];};

struct Nodes {char pad[0xa4];int count;char gap[4];struct Node *nodes;};

extern void *fn_801F7EB8(void *);

void fn_801D7DE8(struct Nodes *object,float value) {int i;for(i=0;i<object->count;++i)if(fn_801F7EB8(&object->nodes[i].handle)){struct HandleManager *manager=lbl_801E9D24.manager;void *first=resolve_manager(manager,&object->nodes[i].handle);void *second=resolve_manager(manager,(const struct Handle *)((char *)first+0xb8));*(float *)((char *)second+0x18)=value;}}
