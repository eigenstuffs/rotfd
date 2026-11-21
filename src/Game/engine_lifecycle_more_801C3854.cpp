/* Original engine lifetime and record routines.
 * See docs/notes/game-engine-lifecycle-more.md. */
struct Handle_801C3854{
    signed int tag:8;
    signed int index:24;
};
struct Entry_801C3854{
    void *object;
    char pad[8];
    signed char tag;
    char tail[3];
};
struct Manager_801C3854{
    char pad[8];
    Entry_801C3854 *entries;
};
extern "C" {
    extern struct Globals_801C3854{
        char pad[0x110];
        void *state;
        char pad114[4];
        Manager_801C3854 *manager;
    }lbl_801E9D24;
    void fn_801F86C8(Manager_801C3854 *,const void *,int);
    void *fn_801F7EB8(const void *);
}
static inline void *resolve(const Handle_801C3854 *h){
    Entry_801C3854 *entry=&lbl_801E9D24.manager->entries[h->index];
    if(entry->tag==h->tag)return entry->object;
    return 0;
}
struct Storage_801C3854 {
    char pad[8];
};
struct Object_801C3854:Storage_801C3854{
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
    char padC[0x10];
    float value1C;
    char pad20[4];
    Handle_801C3854 owner;
    char pad28[4];
    unsigned char flags;
};
extern "C" {
    extern const float lbl_8037A3C0;
    extern char lbl_802ACA88[];
    void fn_80213A18(void *);
    void fn_801FA014(void *,const char *,...);
}
extern "C" int fn_801C3854(Object_801C3854 *self,const Handle_801C3854 *owner){
    fn_801F86C8(lbl_801E9D24.manager,&self->owner,-1);
    self->owner=*owner;
    fn_801F86C8(lbl_801E9D24.manager,owner,1);
    if(fn_801F7EB8(&self->owner)){
        self->slot40();
        self->flags|=2;
        self->value1C=lbl_8037A3C0;
        fn_80213A18(self);
        fn_801FA014(lbl_801E9D24.state,lbl_802ACA88);
        return 1;
    }return 0;
}
