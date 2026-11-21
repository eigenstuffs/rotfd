#ifndef ROTFD_MANIPULATOR_CALLBACKS_INTERNAL_H
#define ROTFD_MANIPULATOR_CALLBACKS_INTERNAL_H

// The inline destructor leaves slot2C as this class's first non-inline virtual.
#include "objects_owner_internal.h"
struct Manipulator_Z : Activable_Z {
    float accumulated;
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
    Manipulator_Z();
    virtual inline ~Manipulator_Z();
    virtual void slot2C(float);
    virtual void slot30();
    virtual void slot34();
    virtual void slot38(float) = 0;
    virtual void slot3C();
};
inline Manipulator_Z::~Manipulator_Z() {}

typedef char CheckManipulatorSize[sizeof(Manipulator_Z) == 0x20 ? 1 : -1];
#endif
