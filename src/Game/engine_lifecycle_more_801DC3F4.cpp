struct Handle_801DC3F4{
    signed int tag:8;
    signed int index:24;
};
struct Entry_801DC3F4{
    void *object;
    char pad[8];
    signed char tag;
    char tail[3];
};
struct Manager_801DC3F4{
    char pad[8];
    Entry_801DC3F4 *entries;
};
extern "C" {
    extern struct Globals_801DC3F4{
        char pad[0x110];
        void *state;
        char pad114[4];
        Manager_801DC3F4 *manager;
    }lbl_801E9D24;
    void fn_801F86C8(Manager_801DC3F4 *,const void *,int);
    void *fn_801F7EB8(const void *);
}
static inline void *resolve(const Handle_801DC3F4 *h){
    Entry_801DC3F4 *entry=&lbl_801E9D24.manager->entries[h->index];
    if(entry->tag==h->tag)return entry->object;
    return 0;
}
struct Object_801DC3F4{
    char pad[0x188];
    Handle_801DC3F4 owner;
};
extern "C" void fn_801DC3F4(Object_801DC3F4 *self){
    if(fn_801F7EB8(&self->owner)){
        Handle_801DC3F4 *replacement=(Handle_801DC3F4 *)((char *)resolve(&self->owner)+0xb8);
        fn_801F86C8(lbl_801E9D24.manager,&self->owner,-1);
        self->owner=*replacement;
        fn_801F86C8(lbl_801E9D24.manager,replacement,1);
    }
}
