typedef unsigned int u32;
struct Handle_801D9ED0 {
    signed int generation:8;
    signed int index:24;
    template<class T>T*get()const;
};
struct Entry_801D9ED0 {
    void*object;
    u32 key;
    char unknown8[4];
    signed char generation;
    char unknownD[3];
    signed char getGeneration()const {
        return generation;
    }
};
struct Manager_801D9ED0 {
    int count,capacity;
    Entry_801D9ED0*entries;
};
struct Globals_801D9ED0 {
    char unknown[0x118];
    Manager_801D9ED0*manager;
};
extern "C" Globals_801D9ED0 lbl_801E9D24;
template<class T>inline T*Handle_801D9ED0::get()const {
    int i=index;
    Manager_801D9ED0*m=lbl_801E9D24.manager;
    int gen=m->entries[i].getGeneration();
    return gen==generation?(T*)m->entries[i].object:0;
}
struct BaseObject_Z {
    signed char slot1C();
};
struct ChildStorage_801D9ED0 {
    char unknown[8];
};
struct Child_801D9ED0:ChildStorage_801D9ED0 {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
};
struct Record_801D9ED0 {
    char unknown[0x88];
    Handle_801D9ED0 handle;
    u32 unknown8C;
};
struct Owner_801D9ED0 {
    char unknown[0xA4];
    int count,capacity;
    Record_801D9ED0*records;
};
extern "C" void*fn_801F7EB8(const Handle_801D9ED0*);
extern "C" signed char fn_801D9ED0(Owner_801D9ED0*self) {
    if(!((BaseObject_Z*)self)->BaseObject_Z::slot1C())return 0;
    for(int i=0; i<self->count; ++i) {
        if(fn_801F7EB8(&self->records[i].handle))self->records[i].handle.get<Child_801D9ED0>()->slot1C();
    }
    return 1;
}
