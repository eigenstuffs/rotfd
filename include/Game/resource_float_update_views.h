#ifndef GAME_RESOURCE_FLOAT_UPDATE_VIEWS_H
#define GAME_RESOURCE_FLOAT_UPDATE_VIEWS_H

struct ResourceFloatHandle {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
};

struct ResourceFloatEntry {
    char* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};

struct ResourceFloatManager {
    int count, capacity;
    ResourceFloatEntry* entries;
};

struct ResourceFloatContext {
    char unknown00[0x118];
    ResourceFloatManager* manager;
};

extern "C" ResourceFloatContext lbl_801E9D24;

inline char* resolveResourceFloat(const ResourceFloatHandle& handle)
{
    ResourceFloatEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    if (entry->tag == handle.bits.tag)
        return entry->object;
    return 0;
}

struct ResourceFloatResource {
    char unknown00[0x38];
    unsigned long long flags;
    char unknown40[0x18];
    ResourceFloatHandle handle;
};

struct ResourceFloatPrefix {
    int unknown00;
};

struct ResourceFloatQuery : ResourceFloatPrefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual ResourceFloatResource* getResource();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual const ResourceFloatHandle* getHandle();
};


struct ResourceFloatOwner {
    char unknown00[0x36C];
    float field36C;
    char unknown370[0x40];
    float field3B0, field3B4, field3B8, field3BC, field3C0;
    char unknown3C4[0x1C];
    float field3E0, field3E4;
};

#endif
