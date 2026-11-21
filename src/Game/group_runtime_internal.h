// Private recovered layouts shared by the bounded group query/update fragments.
#ifndef ROTFD_GROUP_RUNTIME_INTERNAL_H
#define ROTFD_GROUP_RUNTIME_INTERNAL_H

typedef unsigned long u32;
struct Handle {
    union {
        u32 value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
};
struct HandleList { int count, capacity; Handle* data; };
struct ObjectStorage { char unknown[8]; };
struct Object : ObjectStorage {
    // MW vtable metadata precedes these methods; slot5 is at +0x1C.
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void slot18();
    virtual void slot19();
    virtual void slot20();
    virtual void slot21();
    virtual void slot22();
    virtual void slot23();
    virtual void slot24();
    virtual void slot25();
    virtual void slot26();
    virtual void slot27();
    virtual Handle* get(int);

    Handle related;
    char unknown10[0x20 - 0x10];
    int identifier;
    char unknown24[0x90 - 0x24];
    HandleList second;
    char unknown9C[0xDC - 0x9C];
    int maximum, current, state;
};
struct Group {
    Handle fixed[4];
    char flags[4];
    HandleList entries;
    char paused;
};
struct GameStorage { char unknown[0x278]; };
struct Game : GameStorage {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual void slot8();
    virtual void slot9();
    virtual void slot10();
    virtual void slot11();
    virtual void slot12();
    virtual void slot13();
    virtual void slot14();
    virtual void slot15();
    virtual void slot16();
    virtual void slot17();
    virtual void reset();
};
struct ResourceEntry {
    Object* object;
    u32 unused[2];
    signed char generation;
    char padding[3];
};
struct Manager { u32 unused[2]; ResourceEntry* entries; };
struct Globals {
    char unknown[0x114];
    Game* game;
    Manager* manager;
    u32 unused;
    void* updateContext;
};
extern "C" {
extern Globals lbl_801E9D24;
u32 fn_801F7EB8(Handle*);
void fn_8023AAAC(void*);
void fn_8020349C(Object*, float);
}
static inline Object* resolve(const Handle& handle) {
    ResourceEntry* entry = lbl_801E9D24.manager->entries + handle.bits.index;
    return entry->generation == handle.bits.generation ? entry->object : 0;
}

#endif
