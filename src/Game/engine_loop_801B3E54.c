struct Handle {signed int tag:8;signed int index:24;};

struct HandleEntry {void *object;char pad[8];signed char tag;char tail[3];};

struct HandleManager {char pad[8];struct HandleEntry *entries;};

struct Manager {char pad[8];struct HandleEntry *entries;char gap[0xb8];void *lookup;};

extern void fn_80208BFC(unsigned int *,unsigned int);

extern signed char fn_802082E8(void *,unsigned int *,int **);

extern void fn_801F86C8(void *,void *,int);

static inline void refresh(struct Manager *manager,struct Handle *out) {int *found;unsigned int key;fn_80208BFC(&key,*(unsigned int *)out);if(fn_802082E8(manager->lookup,&key,&found) && manager->entries[*found].object){out->index=*found;out->tag=((signed char *)manager->entries)[*found*16+12];fn_801F86C8(manager,out,1);}else *(unsigned int *)out=0;}

void fn_801B3E54(struct Manager *manager,struct Handle *out) {refresh(manager,out);}

void fn_801B3F0C(struct Manager *manager,struct Handle *out,unsigned int key) {*(unsigned int *)out=key;refresh(manager,out);}
