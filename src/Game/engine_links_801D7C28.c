typedef unsigned short U16;
typedef struct Handle{
    signed int tag:8;
    signed int index:24;
}Handle;
typedef struct Entry{
    void *object;
    char pad[8];
    signed char tag;
    char tail[3];
}Entry;
typedef struct Manager{
    char pad[8];
    Entry *entries;
}Manager;
typedef struct Record{
    char pad[0x60];
    U16 link;
    char tail[6];
}Record;
typedef struct ListEntry{
    Handle owner;
    U16 record;
    char pad[2];
    U16 next,prev;
}ListEntry;
typedef struct List{
    char pad[4];
    int count;
    int capacity;
    char *entries;
}List;
typedef struct Object{
    char pad[0x20];
    U16 link;
    char pad22[2];
    int count;
    int capacity;
    char *records;
}Object;
extern struct Globals{
    char pad[0x118];
    Manager *manager;
    char pad11c[0x10];
    List *list;
    List *list2;
}lbl_801E9D24;
extern void fn_801F7914(void *,const void *);
static inline ListEntry *at(List*self,int index){
    return (ListEntry*)(self->entries+index*12);
}
static inline void *resolve(const Handle *h){
    Entry *e=&lbl_801E9D24.manager->entries[h->index];
    if(e->tag==h->tag)return e->object;
    return 0;
}
extern void *fn_801F7EB8(const void *);
typedef struct OtherObject{
    char pad[0xd0];
    char *records;
}OtherObject;
U16 fn_801D7C28(List *self,const char *source,int record){
    int index=(U16)(at(self,self->count-1)->next-1);
    ListEntry *entry=at(self,index+1);
    if(entry->record!=0xffff){
        OtherObject *object=(OtherObject*)fn_801F7EB8(&entry->owner);
        *(U16*)(object->records+entry->record*0x68+0x60)=0xffff;
    }entry->record=record;
    fn_801F7914(&entry->owner,source+4);
    return index;
}
