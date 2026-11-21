struct StateHandle {
    union {
        unsigned long value;
        struct { signed int tag : 8; signed int index : 24; } bits;
    };
};

struct StateEntry {
    char* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};

struct StateManager {
    int count, capacity;
    StateEntry* entries;
};

struct StateContext {
    char unknown00[0x118];
    StateManager* manager;
};

extern "C" {
extern StateContext lbl_801E9D24;
void fn_80063290(void*, int);
unsigned long fn_8009F170(void*);
}

inline char* resolveState(const StateHandle& handle)
{
    StateEntry* entry = &lbl_801E9D24.manager->entries[handle.bits.index];
    if (entry->tag == handle.bits.tag)
        return entry->object;
    return 0;
}

struct StateFlags {
    char unknown00[0x30];
    unsigned long long flags;
};

struct StateOwner {
    char unknown00[0x70];
    StateHandle handle;
};

extern "C" void fn_80065A70(StateOwner* self, int argument)
{
    ((StateFlags*)resolveState(self->handle))->flags |= 0x400ULL;
    ((StateFlags*)resolveState(self->handle))->flags |= 0x1000000000ULL;
    fn_80063290(self, argument);
}

struct StateQueryPrefix {
    int unknown00;
};

struct StateQuery : StateQueryPrefix {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
    virtual const StateHandle* getHandle();
};

extern "C" int fn_8006653C(StateQuery* self, unsigned char state)
{
    if (state == *(int*)(resolveState(*self->getHandle()) + 0x320))
        return 1;
    return 0;
}

extern "C" int fn_80066AB0(StateQuery* self, unsigned long value)
{
    unsigned long actual = fn_8009F170(resolveState(*self->getHandle()));
    if (actual == value)
        return 1;
    return 0;
}
