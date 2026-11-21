/* Original engine nested handle query.
 * See docs/notes/game-engine-handle-flags.md. */
typedef unsigned int u32;
struct Entry_801D7CDC {
    void*object;
    u32 unknown[2];
    signed char generation;
    char padD[3];
    signed char getGeneration()const {
        return generation;
    }
};
struct Manager_801D7CDC {
    int count,capacity;
    Entry_801D7CDC*entries;
};
struct Globals_801D7CDC {
    char unknown[0x118];
    Manager_801D7CDC*manager;
};
extern "C" Globals_801D7CDC lbl_801E9D24;
struct Handle_801D7CDC {
    signed int generation:8;
    signed int index:24;
    template<class T>T*get()const {
        int i=index;
        Manager_801D7CDC*m=lbl_801E9D24.manager;
        int gen=m->entries[i].getGeneration();
        return gen==generation?(T*)m->entries[i].object:0;
    }
};
struct Target_801D7CDC {
    char unknown[0x18];
    float value;
};
struct Resource_801D7CDC {
    char unknown[0xB8];
    Handle_801D7CDC child;
};
struct Record_801D7CDC {
    char unknown[0x88];
    Handle_801D7CDC handle;
    u32 unknown8C;
};
struct Owner_801D7CDC {
    char unknown[0xA4];
    int count,capacity;
    Record_801D7CDC*records;
};
extern "C" {
    void*fn_801F7EB8(const Handle_801D7CDC*);
    extern const float lbl_8037A4B8;
}
extern "C" float fn_801D7CDC(Owner_801D7CDC*self) {
    for(int i=0; i<self->count; ++i) {
        if(fn_801F7EB8(&self->records[i].handle))return self->records[i].handle.get<Resource_801D7CDC>()->child.get<Target_801D7CDC>()->value;
    }
    return lbl_8037A4B8;
}
