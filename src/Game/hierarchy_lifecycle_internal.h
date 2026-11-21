// Private ABI views for hierarchy lifecycle and owner setup.
#ifndef ROTFD_HIERARCHY_LIFECYCLE_INTERNAL_H
#define ROTFD_HIERARCHY_LIFECYCLE_INTERNAL_H

#include "group_runtime_internal.h"
struct RootStorage_80207414 {
    u32 unknown0; Handle identity;
    const Handle& getIdentity() const { return identity; }
};
struct BaseObject_Z : RootStorage_80207414 {
    virtual ~BaseObject_Z();
    virtual void slot0C(u32);
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
};
struct Hierarchy_80200478 : BaseObject_Z {
    Handle owner;
    char name[0x80];
    HandleList primary, second, secondary, assigned;
    Handle related;
    HandleList fourth, third;
    int count;
    virtual ~Hierarchy_80200478();
    virtual signed char slot1C();
};

#endif
