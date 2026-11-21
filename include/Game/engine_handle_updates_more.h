#ifndef GAME_ENGINE_HANDLE_UPDATES_MORE_H
#define GAME_ENGINE_HANDLE_UPDATES_MORE_H

struct EngineHandleUpdateHandle { signed int generation : 8; signed int index : 24; };
struct EngineHandleUpdateStorage { char unknown00[8]; };
struct EngineHandleUpdateObject : EngineHandleUpdateStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
};
struct EngineHandleUpdateEntry {
    EngineHandleUpdateObject* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
};
struct EngineHandleUpdateManager { char unknown00[8]; EngineHandleUpdateEntry* entries; };
struct EngineHandleUpdatePair {
    char unknown00[0x20];
    EngineHandleUpdateHandle first;
    int unknown24;
    EngineHandleUpdateHandle second;
};
struct EngineHandleUpdateFixed {
    char unknown00[0x44];
    EngineHandleUpdateHandle first, last;
    int unknown4C;
    EngineHandleUpdateHandle second, fixed[3];
};
struct EngineHandleUpdateTriple {
    char unknown00[0x2C];
    int firstCount, firstCapacity;
    EngineHandleUpdateHandle* first;
    char unknown38[0x28];
    int secondCount, secondCapacity;
    EngineHandleUpdateHandle* second;
    int thirdCount, thirdCapacity;
    EngineHandleUpdateHandle* third;
};
extern "C" {
extern struct { char unknown00[0x118]; EngineHandleUpdateManager* manager; } lbl_801E9D24;
unsigned int fn_801F7EB8(const EngineHandleUpdateHandle*);
signed char slot1C__12BaseObject_ZFv(void*);
}
static inline EngineHandleUpdateObject* engineHandleUpdateResolve(const EngineHandleUpdateHandle& handle)
{
    EngineHandleUpdateEntry* entry = &lbl_801E9D24.manager->entries[handle.index];
    return entry->generation == handle.generation ? entry->object : 0;
}

#endif
