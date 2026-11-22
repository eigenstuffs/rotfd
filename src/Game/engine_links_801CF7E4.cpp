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
extern "C" struct Globals{
    char pad[0x118];
    Manager *manager;
    char pad11c[0x10];
    List *list;
    List *list2;
}lbl_801E9D24;
extern "C" void fn_801F7914(void *,const void *);
static inline ListEntry *at(List*self,int index){
    return (ListEntry*)(self->entries+index*12);
}
static inline void *resolve(const Handle *h){
    Entry *e=&lbl_801E9D24.manager->entries[h->index];
    if(e->tag==h->tag)return e->object;
    return 0;
}
extern "C" void *fn_801F7EB8(const void *);
struct Prefix_801CF7E4{
    char pad[8];
};
struct OtherObject_801CF7E4:Prefix_801CF7E4{
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24();
    virtual void slot28();
    virtual void slot2C();
    virtual void slot30();
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
};
extern "C" U16 fn_801CF7E4(List *self,const char *source,int record){
    int index=(U16)(at(self,self->count-1)->next-1);
    ListEntry *entry=at(self,index+1);
    if(entry->record!=0xffff){
        OtherObject_801CF7E4 *object=(OtherObject_801CF7E4*)resolve(&entry->owner);
        object->slot54();
    }entry->record=record;
    fn_801F7914(&entry->owner,source+4);
    return index;
}
