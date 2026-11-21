#include "Game/named_owner_property_copy.h"

typedef unsigned long NamedOwnerCopyWord;

struct Handle_801F7F10 {
    union {
        NamedOwnerCopyWord value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};

struct NamedOwnerCopyName {
    NamedOwnerCopyWord value;
    NamedOwnerCopyName(const char*);
};

struct NamedOwnerCopyPoint {
    float x, y, z;
    void operator=(const NamedOwnerCopyPoint& point)
    {
        x = point.x;
        y = point.y;
        z = point.z;
    }
};

struct NamedOwnerCopyPair {
    float x, y;
    void operator=(const NamedOwnerCopyPair& pair)
    {
        x = pair.x;
        y = pair.y;
    }
};

struct NamedOwnerCopyStorage { NamedOwnerCopyWord unknown00[2]; };

struct NamedOwnerCopyObject : NamedOwnerCopyStorage {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual void slot1C();
    virtual void slot20();
    virtual void commit();

    NamedOwnerCopyPoint position;
    float field18;
    NamedOwnerCopyPoint scale;
    float field28;
    char unknown2C[0x24];
    float field50;
    NamedOwnerCopyPair pair54, pair5C;
    NamedOwnerCopyWord field64, field68, field6C;
    char unknown70[4];
    Handle_801F7F10 handles[2];
};

struct NamedOwnerCopySource {
    NamedOwnerCopyName name;
    char unknown04[8];
    NamedOwnerCopyPoint position;
    float field18;
    NamedOwnerCopyPoint scale;
    float field28;
    char unknown2C[0x24];
    float field50;
    NamedOwnerCopyPair pair54, pair5C;
    NamedOwnerCopyWord field64, field68, field6C;
    char unknown70[4];
    Handle_801F7F10 handles[2];
};

struct NamedOwnerCopyEntry {
    NamedOwnerCopyObject* object;
    NamedOwnerCopyWord unknown04[2];
    signed char generation;
    char unknown0D[3];
};

struct NamedOwnerCopyManager {
    NamedOwnerCopyWord unknown00[2];
    NamedOwnerCopyEntry* entries;
};

struct NamedOwnerCopyGlobals {
    char unknown00[0x118];
    NamedOwnerCopyManager* manager;
};

extern "C" {
extern NamedOwnerCopyGlobals lbl_801E9D24;
extern const char lbl_802AEA90[];
NamedOwnerCopyWord fn_801F948C(void*, const char*);
Handle_801F7F10 fn_801B550C(NamedOwnerCopyManager*,
    const NamedOwnerCopyName&, const NamedOwnerCopyName&);
void fn_801F86C8(NamedOwnerCopyManager*, const Handle_801F7F10*, short);
void fn_802072D4(NamedOwnerCopyObject*, NamedOwnerCopySource*, int);
}

inline NamedOwnerCopyName::NamedOwnerCopyName(const char* text)
{
    value = fn_801F948C(this, text);
}

struct NamedOwnerCopyZero : Handle_801F7F10 {
    NamedOwnerCopyZero() { value = 0; }
};

struct NamedOwnerCopyOwned : NamedOwnerCopyZero {
    NamedOwnerCopyOwned(const Handle_801F7F10& handle)
    {
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};

static inline void assign(Handle_801F7F10& target, const Handle_801F7F10& source)
{
    fn_801F86C8(lbl_801E9D24.manager, &target, -1);
    target.value = source.value;
    fn_801F86C8(lbl_801E9D24.manager, &source, 1);
}

static inline NamedOwnerCopyObject* resolve(const Handle_801F7F10& handle)
{
    NamedOwnerCopyEntry* entry =
        &lbl_801E9D24.manager->entries[handle.bits.index];
    return entry->generation == handle.bits.generation ? entry->object : 0;
}

extern "C" void fn_80238F64(NamedOwnerCopySource* self, Handle_801F7F10& target)
{
    assign(target, NamedOwnerCopyOwned(fn_801B550C(lbl_801E9D24.manager,
        NamedOwnerCopyName(lbl_802AEA90), self->name)));
    fn_802072D4(resolve(target), self, 0);

    const Handle_801F7F10* source;
    NamedOwnerCopySource* current = self;
    int offset;
    int i = 0;
    offset = 0;
    for (; i < 2; ++i) {
        source = &current->handles[0];
        NamedOwnerCopyObject* destination =
            (NamedOwnerCopyObject*)((char*)resolve(target) + offset);
        assign(destination->handles[0], *source);
        current = (NamedOwnerCopySource*)((char*)current + 4);
        offset += 4;
    }

    resolve(target)->pair54 = self->pair54;
    resolve(target)->pair5C = self->pair5C;
    resolve(target)->field50 = self->field50;
    resolve(target)->position = self->position;
    resolve(target)->scale = self->scale;
    resolve(target)->field18 = self->field18;
    resolve(target)->field28 = self->field28;
    resolve(target)->field64 = self->field64;
    resolve(target)->field68 = self->field68;
    resolve(target)->field6C = self->field6C;
    resolve(target)->commit();
}
