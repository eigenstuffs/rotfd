#ifndef GAME_ENGINE_HANDLE_DISTINCT_H
#define GAME_ENGINE_HANDLE_DISTINCT_H

struct EngineDistinctHandle { signed int generation : 8; signed int index : 24; };
struct EngineDistinctStorage { char unknown00[8]; };
struct EngineDistinctObject : EngineDistinctStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void slot24(void*);
};
struct EngineDistinctEntry {
    EngineDistinctObject* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
    signed char getGeneration() const { return generation; }
};
struct EngineDistinctManager { char unknown00[8]; EngineDistinctEntry* entries; };
struct EngineDistinctOwner { char unknown00[0x20]; int count, capacity; EngineDistinctHandle* items; };
extern "C" {
extern struct { char unknown00[0x118]; EngineDistinctManager* manager; } lbl_801E9D24;
unsigned int fn_801F7EB8(const EngineDistinctHandle*);
}
static inline EngineDistinctObject* engineDistinctResolve(const EngineDistinctHandle& handle)
{
    int index = handle.index;
    EngineDistinctManager* manager = lbl_801E9D24.manager;
    int generation = manager->entries[index].getGeneration();
    return generation == handle.generation ? manager->entries[index].object : 0;
}

#endif
