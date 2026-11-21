#include "Game/named_owner_recursive_clone.h"

typedef unsigned long NamedOwnerCloneWord;

struct Handle_801F7F10 {
    union {
        NamedOwnerCloneWord value;
        struct { signed int generation : 8; signed int index : 24; } bits;
    };
    Handle_801F7F10();
    ~Handle_801F7F10();
};

struct NamedOwnerCloneName {
    NamedOwnerCloneWord value;
    NamedOwnerCloneName(const char*);
};

struct NamedOwnerClonePoint {
    float x, y, z;
    void operator=(const NamedOwnerClonePoint& point)
    {
        x = point.x;
        y = point.y;
        z = point.z;
    }
};

struct NamedOwnerCloneBasis { NamedOwnerCloneWord words[9]; };
struct NamedOwnerCloneMatrix { NamedOwnerCloneWord words[16]; };

struct NamedOwnerCloneStorage {
    NamedOwnerCloneName name;
    NamedOwnerCloneWord unknown04;
};

struct NamedOwnerCloneObject : NamedOwnerCloneStorage {
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
    virtual void lookup(Handle_801F7F10&, const Handle_801F7F10&);

    NamedOwnerCloneWord unknown0C;
    Handle_801F7F10 child, unknown14, next, parent, linked, handle24, handle28;
    NamedOwnerCloneWord unknown2C;
    NamedOwnerCloneBasis basis;
    char unknown54[0x64];
    NamedOwnerClonePoint pointB8;
    float unknownC4;
    NamedOwnerClonePoint pointC8;
    float fieldD4, fieldD8, fieldDC, fieldE0;
    char unknownE4[0x3C];
    NamedOwnerCloneWord flags;
    NamedOwnerCloneMatrix* local;
    NamedOwnerCloneMatrix* world;
    short localIndex, worldIndex;
    Handle_801F7F10 state;
    NamedOwnerCloneWord group;
};

struct NamedOwnerCloneEntry {
    NamedOwnerCloneObject* object;
    NamedOwnerCloneWord unknown04[2];
    signed char generation;
    char unknown0D[3];
};

struct NamedOwnerCloneManager {
    NamedOwnerCloneWord unknown00[2];
    NamedOwnerCloneEntry* entries;
};

struct NamedOwnerClonePool {
    NamedOwnerCloneMatrix* buffers[6];
    unsigned char active;
};

struct NamedOwnerCloneGlobals {
    char unknown00[0x118];
    NamedOwnerCloneManager* manager;
    char unknown11C[0x18];
    NamedOwnerClonePool* pool;
};

extern "C" {
extern NamedOwnerCloneGlobals lbl_801E9D24;
extern const char lbl_8037B338[5];
NamedOwnerCloneWord fn_801F948C(void*, const char*);
Handle_801F7F10 fn_801B550C(NamedOwnerCloneManager*,
    const NamedOwnerCloneName&, const NamedOwnerCloneName&);
void fn_801F86C8(NamedOwnerCloneManager*, const Handle_801F7F10*, short);
void fn_8023FBE4(NamedOwnerCloneObject*, NamedOwnerCloneWord, int);
void fn_8023D648(NamedOwnerCloneObject*);
void fn_8023EE7C(NamedOwnerCloneObject*, const Handle_801F7F10&);
void* fn_801F7EB8(const Handle_801F7F10*);
void fn_8023EE08(NamedOwnerCloneObject*, const Handle_801F7F10&);
}

inline NamedOwnerCloneName::NamedOwnerCloneName(const char* text)
{
    value = fn_801F948C(this, text);
}

struct NamedOwnerCloneZero : Handle_801F7F10 {
    NamedOwnerCloneZero() { value = 0; }
};

struct NamedOwnerCloneTwoZero : NamedOwnerCloneZero {
    NamedOwnerCloneTwoZero() { value = 0; }
};

struct NamedOwnerCloneCopy : NamedOwnerCloneZero {
    NamedOwnerCloneCopy(const Handle_801F7F10& handle)
    {
        value = handle.value;
        fn_801F86C8(lbl_801E9D24.manager, &handle, 1);
    }
};

extern "C" void fn_802408BC(NamedOwnerCloneObject*, NamedOwnerCloneCopy, int);

static inline void assign(Handle_801F7F10& target, const Handle_801F7F10& source)
{
    fn_801F86C8(lbl_801E9D24.manager, &target, -1);
    target.value = source.value;
    fn_801F86C8(lbl_801E9D24.manager, &source, 1);
}

static inline NamedOwnerCloneObject* resolve(const Handle_801F7F10& handle)
{
    NamedOwnerCloneEntry* entry =
        &lbl_801E9D24.manager->entries[handle.bits.index];
    if (entry->generation == handle.bits.generation)
        return entry->object;
    return 0;
}

static inline void setMatrix(NamedOwnerCloneObject* object,
    const NamedOwnerCloneMatrix& source)
{
    object->local = lbl_801E9D24.pool->buffers[lbl_801E9D24.pool->active]
        + object->localIndex;
    *object->local = source;
    object->flags |= 0x20;
    fn_8023D648(object);
}

extern "C" void fn_8023E994(NamedOwnerCloneObject* self,
    Handle_801F7F10& target, signed char children)
{
    NamedOwnerCloneName name(lbl_8037B338);
    assign(target, NamedOwnerCloneCopy(fn_801B550C(lbl_801E9D24.manager,
        name, self->name)));
    NamedOwnerCloneObject* copy = resolve(target);
    assign(copy->handle24, self->handle24);
    assign(copy->handle28, self->handle28);
    copy->pointB8 = self->pointB8;
    copy->pointC8 = self->pointC8;
    copy->fieldD4 = self->fieldD4;
    copy->fieldD8 = self->fieldD8;
    copy->fieldDC = self->fieldDC;
    copy->fieldE0 = self->fieldE0;
    fn_8023FBE4(copy, self->group, 0);
    copy->flags = self->flags;
    copy->basis = self->basis;
    setMatrix(copy, *self->local);
    fn_8023EE7C(copy, self->parent);

    NamedOwnerCloneTwoZero linked;
    if (fn_801F7EB8(&self->linked))
        resolve(self->linked)->lookup(linked, self->parent);
    fn_8023EE08(copy, linked);

    if (children) {
        NamedOwnerCloneObject* child = resolve(self->child);
        NamedOwnerCloneTwoZero cloned;
        while (child) {
            fn_8023E994(child, cloned, children);
            fn_802408BC(copy, NamedOwnerCloneCopy(cloned), 0);
            child = resolve(child->next);
        }
    }
}
