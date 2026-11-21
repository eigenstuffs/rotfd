/* Original engine lifetime and record routines.
 * See docs/notes/game-engine-handle-transfers.md. */
typedef unsigned int u32;
struct Entry_801CA1E8 {
    void*object;
    u32 key;
    char unknown8[4];
    signed char generation;
    char padD[3];
    signed char getGeneration()const {
        return generation;
    }
};
struct Manager_801CA1E8 {
    int count,capacity;
    Entry_801CA1E8*entries;
};
struct Defaults_801CA1E8;
struct Globals_801CA1E8 {
    char unknown[0x118];
    Manager_801CA1E8*manager;
    char unknown11C[0x30];
    Defaults_801CA1E8*defaults;
};
extern "C" Globals_801CA1E8 lbl_801E9D24;
extern "C" {
    void fn_801F86C8(void*,const void*,int);
    void*fn_801F7EB8(const void*);
}
struct Handle_801CA1E8 {
    signed int generation:8;
    signed int index:24;
    template<class T>T*get()const {
        int i=index;
        Manager_801CA1E8*m=lbl_801E9D24.manager;
        int gen=m->entries[i].getGeneration();
        return gen==generation?(T*)m->entries[i].object:0;
    }
    void assign(const Handle_801CA1E8&v) {
        fn_801F86C8(lbl_801E9D24.manager,this,-1);
        *(u32*)this=*(const u32*)&v;
        fn_801F86C8(lbl_801E9D24.manager,&v,1);
    }
};
struct Defaults_801CA1E8 {
    char unknown[0x28C];
    Handle_801CA1E8 handle;
};
struct Storage8_801CA1E8 {
    char unknown[8];
};
struct Child_801CA1E8:Storage8_801CA1E8 {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20(Child_801CA1E8*,int);
};
struct Owner_801CA1E8 {
    char unknown[0x1C];
    Handle_801CA1E8 first,second,third;
};
extern "C" void fn_801CA1E8(Owner_801CA1E8*self) {
    Child_801CA1E8*first=self->second.get<Child_801CA1E8>();
    Child_801CA1E8*second=self->first.get<Child_801CA1E8>();
    if(first)first->slot20(second,0);
    if(!fn_801F7EB8(&self->third))self->third.assign(lbl_801E9D24.defaults->handle);
}
