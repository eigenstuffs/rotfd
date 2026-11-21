#ifndef GAME_ENGINE_TRANSFORM_RECORDS_H
#define GAME_ENGINE_TRANSFORM_RECORDS_H

struct EngineTransformHandle {
    signed int generation : 8;
    signed int index : 24;
};
struct EngineTransformNodeStorage {
    char unknown00[8];
};
struct EngineTransformNode : EngineTransformNodeStorage {
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
    virtual void slot34();
    virtual void slot38();
    virtual void slot3C();
    virtual void slot40();
    virtual void slot44();
    virtual void slot48();
    virtual void slot4C();
    virtual void slot50();
    virtual void slot54();
    char unknown0C[0xAC];
    float x, y, z;
    unsigned int unknownC4;
    float qx, qy, qz, qw, sx, sy, sz;
    char unknownE4[0x3C];
    unsigned int flags;
};
struct EngineTransformEntry {
    EngineTransformNode* object;
    char unknown04[8];
    signed char generation;
    char unknown0D[3];
};
struct EngineTransformManager {
    char unknown00[8];
    EngineTransformEntry* entries;
};
struct EngineTransformGroup {
    int count, capacity;
    EngineTransformHandle* items;
    int unknown0C, unknown10;
};
struct EngineTransformGroups {
    char unknown00[0xB8];
    EngineTransformGroup* items;
};
struct EngineTransformContext {
    char unknown00[0x118];
    EngineTransformManager* manager;
    char unknown11C[0x28];
    EngineTransformGroups* groups;
};
struct EngineTransformRecord {
    char unknown00[0x20];
    int count20, capacity24;
    EngineTransformHandle* items28;
    EngineTransformHandle single;
    int count30, capacity34;
    EngineTransformHandle* items38;
    int group;
    char unknown40[0x24];
    int count, capacity;
    EngineTransformHandle* items;
};

extern "C" {
extern EngineTransformContext lbl_801E9D24;
signed char slot1C__12BaseObject_ZFv(EngineTransformRecord*);
unsigned int fn_801F7EB8(const EngineTransformHandle*);
}

static inline EngineTransformNode* engineTransformResolve(const EngineTransformHandle& handle)
{
    EngineTransformEntry* entry = &lbl_801E9D24.manager->entries[handle.index];
    return entry->generation == handle.generation ? entry->object : 0;
}

static inline EngineTransformNode* engineTransformResolveWithManager(EngineTransformManager* manager, const EngineTransformHandle& handle)
{
    EngineTransformEntry* entry = &manager->entries[handle.index];
    return entry->generation == handle.generation ? entry->object : 0;
}

#endif
