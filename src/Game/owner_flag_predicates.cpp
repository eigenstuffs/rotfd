struct PredicateHandle {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
};

struct PredicateEntry {
    char* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};

struct PredicateManager {
    int count, capacity;
    PredicateEntry* entries;
};

struct PredicateContext {
    char unknown00[0x118];
    PredicateManager* manager;
};

extern "C" PredicateContext lbl_801E9D24;

inline char* resolvePredicate(const PredicateHandle& handle)
{
    PredicateEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    if (entry->tag == handle.bits.tag)
        return entry->object;
    return 0;
}

struct PredicateFlags {
    char unknown00[0x30];
    unsigned long long flags;
};

struct PredicateResource {
    char unknown00[0x58];
    PredicateHandle handle;
};

struct PredicateQueryPrefix {
    int unknown00;
};

struct PredicateQuery : PredicateQueryPrefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual PredicateResource* getResource();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual const PredicateHandle* getHandle();
};

extern "C" unsigned short fn_800670B4(PredicateQuery* self)
{
    return *(unsigned long*)(resolvePredicate(*self->getHandle()) + 0x3D8);
}

extern "C" signed char fn_8006727C(PredicateQuery* self, signed char state)
{
    if (!(((PredicateFlags*)resolvePredicate(*self->getHandle()))->flags & 0x8000000000ULL))
        return state == 1;
    return state == 0;
}

extern "C" signed char fn_80067754(PredicateQuery* self, signed char state)
{
    if (!(*(unsigned long*)(resolvePredicate(self->getResource()->handle) + 0x120) & 0x10000))
        return state == 1;
    return state == 0;
}
