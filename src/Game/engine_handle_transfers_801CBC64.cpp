/* Original engine lifetime and record routines.
 * See docs/notes/game-engine-handle-transfers.md. */
typedef unsigned int u32;
struct Entry_801CBC64 {
    void*object;
    u32 key;
    char unknown8[4];
    signed char generation;
    char padD[3];
    signed char getGeneration()const {
        return generation;
    }
};
struct Manager_801CBC64 {
    int count,capacity;
    Entry_801CBC64*entries;
};
struct Defaults_801CBC64;
struct Globals_801CBC64 {
    char unknown[0x118];
    Manager_801CBC64*manager;
    char unknown11C[0x30];
    Defaults_801CBC64*defaults;
};
extern "C" Globals_801CBC64 lbl_801E9D24;
extern "C" {
    void fn_801F86C8(void*,const void*,int);
    void*fn_801F7EB8(const void*);
}
struct Handle_801CBC64 {
    signed int generation:8;
    signed int index:24;
    template<class T>T*get()const {
        int i=index;
        Manager_801CBC64*m=lbl_801E9D24.manager;
        int gen=m->entries[i].getGeneration();
        return gen==generation?(T*)m->entries[i].object:0;
    }
    void assign(const Handle_801CBC64&v) {
        fn_801F86C8(lbl_801E9D24.manager,this,-1);
        *(u32*)this=*(const u32*)&v;
        fn_801F86C8(lbl_801E9D24.manager,&v,1);
    }
};
struct Vec3_801CBC64 {
    float x,y,z;
    void operator=(const Vec3_801CBC64&v) {
        x=v.x;
        y=v.y;
        z=v.z;
    }
};
struct Child_801CBC64 {
    char unknown[0x24];
    Handle_801CBC64 first,second;
    char unknown2C[0x58];
    Vec3_801CBC64 position,firstVector,secondVector;
};
struct Storage8_801CBC64 {
    char unknown[8];
};
struct Embedded_801CBC64:Storage8_801CBC64 {
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
    virtual void slot34(const Vec3_801CBC64*);
};
struct Owner_801CBC64 {
    char unknown[0x4C];
    Embedded_801CBC64 embedded;
    char unknown58[0x84];
    Vec3_801CBC64 firstVector,secondVector;
    char unknownF4[0x10];
    Handle_801CBC64 child,first,second;
};
struct Target_801CBC64 {
    char unknown[0x28];
    Handle_801CBC64 handle;
};
extern "C" void fn_801CBC64(Owner_801CBC64*self,Target_801CBC64*target) {
    Child_801CBC64*child=self->child.get<Child_801CBC64>();
    if(child) {
        const Handle_801CBC64&second=child->second;
        target->handle.assign(second);
        const Handle_801CBC64&first=child->first;
        self->first.assign(first);
        self->second.assign(self->first);
        Child_801CBC64*object=self->first.get<Child_801CBC64>();
        self->firstVector=object->firstVector;
        self->secondVector=object->secondVector;
        self->embedded.slot34(&object->position);
    }
}
