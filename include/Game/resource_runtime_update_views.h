#ifndef GAME_RESOURCE_RUNTIME_UPDATE_VIEWS_H
#define GAME_RESOURCE_RUNTIME_UPDATE_VIEWS_H

struct ResourceRuntimeHandle {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
};

struct ResourceRuntimeEntry {
    char* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};

struct ResourceRuntimeManager {
    int count, capacity;
    ResourceRuntimeEntry* entries;
};

struct ResourceRuntimeContext {
    char unknown00[0x118];
    ResourceRuntimeManager* manager;
};

extern "C" ResourceRuntimeContext lbl_801E9D24;

inline char* resolveResourceRuntime(const ResourceRuntimeHandle& handle)
{
    ResourceRuntimeEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    if (entry->tag == handle.bits.tag)
        return entry->object;
    return 0;
}

struct ResourceRuntimeResource {
    char unknown00[0x38];
    unsigned long long flags;
    char unknown40[0x18];
    ResourceRuntimeHandle handle;
};

struct ResourceRuntimePrefix {
    int unknown00;
};

struct ResourceRuntimeQuery : ResourceRuntimePrefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual ResourceRuntimeResource* getResource();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual const ResourceRuntimeHandle* getHandle();
};


struct RuntimeQuery : ResourceRuntimeQuery {
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
    virtual void activate();
    virtual void deactivate();
    char unknown08[0x14B];
    signed char state;
};

struct RuntimeOwner {
    char unknown00[0x3E8];
    signed char option;
    char unknown3E9[11];
    union {
        unsigned char byte;
        signed char sentinel;
    };
};

struct RuntimeRegistration {
    char unknown00[0x88];
    RuntimeQuery* active;
};

struct RuntimeGlobalPrefix {
    char unknown00[0x60];
};

struct RuntimeGlobalBase {
    char unknown00[0x30];
};

struct RuntimeGlobalOwner : RuntimeGlobalPrefix, RuntimeGlobalBase {
    char unknown90[0x168];
    RuntimeRegistration* registration;
};

extern "C" RuntimeGlobalBase* lbl_803776B8;

#endif
