struct Handle {signed int tag:8;signed int index:24;};

struct HandleEntry {void *object;char pad[8];signed char tag;char tail[3];};

struct HandleManager {char pad[8];struct HandleEntry *entries;};

extern struct {char pad[0x118];struct HandleManager *manager;} lbl_801E9D24;

static inline void *resolve(const struct Handle *h) {struct HandleEntry *entry=&lbl_801E9D24.manager->entries[h->index];if(entry->tag==h->tag)return entry->object;return 0;}

static inline void set3(float *out,float x,float y,float z) {out[0]=x;out[1]=y;out[2]=z;}

void fn_80072B28(void *object,short index,void *value,void *node) {const float *position;*(short *)object=index;*(void **)((char *)object+4)=node;position=(const float *)*(void **)((char *)resolve((const struct Handle *)((char *)node+0x58))+0x124);set3((float *)((char *)object+8),position[12],position[13],position[14]);*(short *)((char *)node+0x92)=index;*(short *)((char *)node+0x90)=index;*(void **)((char *)node+0x94)=value;}
