/* Original engine record and output routines.
 * See docs/notes/game-engine-record-output.md. */
typedef unsigned int u32;
struct Entry_801C6C94 {
    void*object;
    u32 unknown[2];
    signed char generation;
    char padD[3];
    signed char getGeneration()const {
        return generation;
    }
};
struct Manager_801C6C94 {
    int count,capacity;
    Entry_801C6C94*entries;
};
struct Globals_801C6C94 {
    char unknown[0x118];
    Manager_801C6C94*manager;
};
extern "C" Globals_801C6C94 lbl_801E9D24;
struct Handle_801C6C94 {
    signed int generation:8;
    signed int index:24;
    template<class T>T*get()const {
        int i=index;
        Manager_801C6C94*m=lbl_801E9D24.manager;
        int gen=m->entries[i].getGeneration();
        return gen==generation?(T*)m->entries[i].object:0;
    }
};
struct IndexRecord_801C6C94 {
    int index;
    char unknown[0x10];
};
struct Resource_801C6C94 {
    char unknown[0x3C];
    int count,capacity;
    IndexRecord_801C6C94*records;
};
struct Target_801C6C94 {
    char unknown[0xC];
    u32 flags;
};
struct Node_801C6C94 {
    char unknown[0x20];
    Handle_801C6C94 related;
};
struct Record_801C6C94 {
    char unknown[0x10];
    Handle_801C6C94 handle;
    char unknown14[8];
};
struct Owner_801C6C94 {
    char unknown[0x40];
    Record_801C6C94*records;
    Handle_801C6C94 resource;
};
extern "C" void fn_802139D8(Owner_801C6C94*);
extern "C" void fn_801C6C94(Owner_801C6C94*self) {
    Resource_801C6C94*resource=self->resource.get<Resource_801C6C94>();
    if(resource) {
        fn_802139D8(self);
        for(int i=0; i<resource->count; ++i)self->records[resource->records[i].index].handle.get<Node_801C6C94>()->related.get<Target_801C6C94>()->flags|=1;
    }
}
