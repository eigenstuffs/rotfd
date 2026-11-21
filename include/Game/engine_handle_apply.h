#ifndef GAME_ENGINE_HANDLE_APPLY_H
#define GAME_ENGINE_HANDLE_APPLY_H

struct EngineHandleApplyHandle { signed int generation : 8; signed int index : 24; };
struct EngineHandleApplyStorage { char unknown00[8]; };
struct EngineHandleApplyObject : EngineHandleApplyStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
};
struct EngineHandleApplyEntry {
    EngineHandleApplyObject* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
};
struct EngineHandleApplyManager { char unknown00[8]; EngineHandleApplyEntry* entries; };
struct EngineHandleApplyPrimary { char unknown00[0x20]; int count, capacity; EngineHandleApplyHandle* items; };
struct EngineHandleApplySecondary { char unknown00[0xBC]; int count, capacity; EngineHandleApplyHandle* items; };
struct EngineHandleApplyFixed {
    char unknown00[0x88];
    EngineHandleApplyHandle fixed[10];
    char unknownB0[0x28];
    int firstCount, firstCapacity;
    EngineHandleApplyHandle* first;
    int secondCount, secondCapacity;
    EngineHandleApplyHandle* second;
};
extern "C" {
extern struct { char unknown00[0x118]; EngineHandleApplyManager* manager; } lbl_801E9D24;
unsigned int fn_801F7EB8(const EngineHandleApplyHandle*);
signed char slot1C__12BaseObject_ZFv(void*);
}
static inline EngineHandleApplyObject* engineHandleApplyResolve(const EngineHandleApplyHandle& handle)
{
    EngineHandleApplyEntry* entry = &lbl_801E9D24.manager->entries[handle.index];
    return entry->generation == handle.generation ? entry->object : 0;
}

#endif
