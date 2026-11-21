#ifndef GAME_RESOURCE_STATE_FORWARD_VIEWS_H
#define GAME_RESOURCE_STATE_FORWARD_VIEWS_H

struct ForwardHandle {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
};

struct ForwardEntry {
    void* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};

struct ForwardManager {
    int count, capacity;
    ForwardEntry* entries;
};

struct ForwardContext {
    char unknown00[0x118];
    ForwardManager* manager;
};

extern "C" ForwardContext lbl_801E9D24;

inline void* resolveForward(const ForwardHandle& handle)
{
    ForwardEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    if (entry->tag == handle.bits.tag)
        return entry->object;
    return 0;
}

struct ForwardResource {
    char unknown00[0x58];
    ForwardHandle handle;
};

struct ForwardPrefix {
    int unknown00;
};

struct ForwardQuery : ForwardPrefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual ForwardResource* getResource();
};

extern "C" {
signed char fn_80069CA8(ForwardQuery*, void*, signed char);
signed char fn_8006B220(ForwardQuery*, void*, signed char);
signed char fn_8006B470(ForwardQuery*, void*, unsigned char);
}

#endif
