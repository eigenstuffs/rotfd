typedef unsigned int u32;
struct Handle_801C7FD0 {
    signed int generation:8;
    signed int index:24;
    template<class T>T*get()const;
};
struct Entry_801C7FD0 {
    void*object;
    u32 key;
    char unknown8[4];
    signed char generation;
    char unknownD[3];
    signed char getGeneration()const {
        return generation;
    }
};
struct Manager_801C7FD0 {
    int count,capacity;
    Entry_801C7FD0*entries;
};
struct Globals_801C7FD0 {
    char unknown[0x118];
    Manager_801C7FD0*manager;
};
extern "C" Globals_801C7FD0 lbl_801E9D24;
template<class T>inline T*Handle_801C7FD0::get()const {
    int i=index;
    Manager_801C7FD0*m=lbl_801E9D24.manager;
    int gen=m->entries[i].getGeneration();
    return gen==generation?(T*)m->entries[i].object:0;
}
struct BaseObject_Z {
    signed char slot1C();
};
struct ChildStorage_801C7FD0 {
    char unknown[8];
};
struct Child_801C7FD0:ChildStorage_801C7FD0 {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
};
template<class T>struct Array_801C7FD0 {
    int count,capacity;
    T*data;
};
struct Record_801C7FD0 {
    char unknown[0x10];
    Handle_801C7FD0 handle;
    char unknown14[8];
};
struct Owner_801C7FD0 {
    char unknown[0x20];
    Array_801C7FD0<Handle_801C7FD0> first,second;
    Array_801C7FD0<Record_801C7FD0> third;
    Handle_801C7FD0 last;
};
extern "C" void*fn_801F7EB8(const Handle_801C7FD0*);
extern "C" signed char fn_801C7FD0(Owner_801C7FD0*self) {
    if(!((BaseObject_Z*)self)->BaseObject_Z::slot1C())return 0;
    int i;
    for(i=0; i<self->first.count; ++i)self->first.data[i].get<Child_801C7FD0>()->slot1C();
    for(i=0; i<self->second.count; ++i)self->second.data[i].get<Child_801C7FD0>()->slot1C();
    for(i=0; i<self->third.count; ++i)if(fn_801F7EB8(&self->third.data[i].handle))self->third.data[i].handle.get<Child_801C7FD0>()->slot1C();
    if(fn_801F7EB8(&self->last))self->last.get<Child_801C7FD0>()->slot1C();
    return 1;
}
