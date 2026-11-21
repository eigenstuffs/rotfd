#ifndef GAME_ENGINE_RECORD_DISPATCH_H
#define GAME_ENGINE_RECORD_DISPATCH_H

// Observed prefixes. Original implementations and virtual tables retain their owners.
struct EngineDispatchVector {
    float x, y, z;
};

struct EngineDispatchHandle {
    union {
        unsigned int value;
        struct {
            signed int tag : 8;
            signed int index : 24;
        } bits;
    };
};

struct EngineDispatchStorage {
    unsigned int unknown00, identity;
};

struct EngineDispatchTarget : EngineDispatchStorage {
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
};

struct EngineDispatchEntry {
    EngineDispatchTarget* object;
    char unknown04[8];
    signed char tag;
    char unknown0D[3];
};

struct EngineDispatchManager {
    char unknown00[8];
    EngineDispatchEntry* entries;
};

struct EngineDispatchState {
    EngineDispatchTarget* active;
    float age, weight;
    char unknown0C[6];
    unsigned short flags;
    char unknown14[0x60];
};

struct EngineDispatchLargeOwner {
    char unknown00[0x18];
    signed char flag18;
    char unknown19[7];
    EngineDispatchState states[4];
    EngineDispatchHandle first, second, target0, target1;
};

struct EngineDispatchSmallOwner {
    char unknown00[0x24];
    EngineDispatchHandle target0, target1;
};

struct EngineDispatchController : EngineDispatchStorage {
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
    virtual void slot50(int, float);
    virtual void slot54(int);
    char unknown0C[0x20];
    EngineDispatchVector position;
};

struct EngineDispatchEvent {
    int command;
};

extern "C" {
extern struct {
    char unknown00[0x118];
    EngineDispatchManager* manager;
} lbl_801E9D24;
EngineDispatchTarget* fn_801F7EB8(const EngineDispatchHandle*);
signed char slot1C__12BaseObject_ZFv(void*);
void fn_8023475C(EngineDispatchLargeOwner*, int, float);
void fn_8024C338(EngineDispatchTarget*);
void fn_8023D400(EngineDispatchTarget*, int);
void slot18__11Activable_ZFv(EngineDispatchLargeOwner*);
void fn_80213920(EngineDispatchLargeOwner*, int);
void __ct__15Handle_801F7F10Fv(EngineDispatchHandle*);
void __dt__15Handle_801F7F10Fv(EngineDispatchHandle*, int);
void fn_801F86C8(EngineDispatchManager*, const EngineDispatchHandle*, short);
void fn_8024C5D4(EngineDispatchTarget*);
extern EngineDispatchVector game_vec3_zero;
extern const float lbl_8037B1E0, lbl_8037B1E8;
}

static inline EngineDispatchTarget* engineDispatchResolve(const EngineDispatchHandle& h)
{
    EngineDispatchEntry* e = &lbl_801E9D24.manager->entries[h.bits.index];
    return e->tag == h.bits.tag ? e->object : 0;
}

typedef char EngineDispatchStateSize[sizeof(EngineDispatchState) == 0x74 ? 1 : -1];
typedef char EngineDispatchHandleSize[sizeof(EngineDispatchHandle) == 4 ? 1 : -1];
typedef char EngineDispatchLargeOwnerSize[sizeof(EngineDispatchLargeOwner) == 0x200 ? 1 : -1];

#endif
