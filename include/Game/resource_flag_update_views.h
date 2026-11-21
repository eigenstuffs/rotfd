#ifndef GAME_RESOURCE_FLAG_UPDATE_VIEWS_H
#define GAME_RESOURCE_FLAG_UPDATE_VIEWS_H

struct ResourceUpdateHandle {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
};

struct ResourceUpdateEntry {
    char* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};

struct ResourceUpdateManager {
    int count, capacity;
    ResourceUpdateEntry* entries;
};

struct ResourceUpdateContext {
    char unknown00[0x118];
    ResourceUpdateManager* manager;
};

extern "C" ResourceUpdateContext lbl_801E9D24;
extern "C" signed char fn_8009FABC(void*, short);

inline char* resolveResourceUpdate(const ResourceUpdateHandle& handle)
{
    ResourceUpdateEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    if (entry->tag == handle.bits.tag)
        return entry->object;
    return 0;
}

struct ResourceUpdateResource {
    char unknown00[0x38];
    unsigned long long flags;
    char unknown40[0x18];
    ResourceUpdateHandle handle;
};

struct ResourceUpdatePrefix {
    int unknown00;
};

struct ResourceUpdateQuery : ResourceUpdatePrefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual ResourceUpdateResource* getResource();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual const ResourceUpdateHandle* getHandle();
};

#endif
