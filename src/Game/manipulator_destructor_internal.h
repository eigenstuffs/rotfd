#ifndef GAME_MANIPULATOR_DESTRUCTOR_INTERNAL_H
#define GAME_MANIPULATOR_DESTRUCTOR_INTERNAL_H
#include "objects_owner_internal.h"
struct Manipulator_Z : Activable_Z {
    float accumulated;
    static void operator delete(void* p) throw() { fn_801EF610(lbl_801EF5C8, p); }
    Manipulator_Z();
    virtual ~Manipulator_Z();
    virtual void slot2C(float);
    virtual void slot30();
    virtual void slot34();
    virtual void slot38(float) = 0;
    virtual void slot3C();
};

typedef char CheckManipulatorSize[sizeof(Manipulator_Z) == 0x20 ? 1 : -1];
#endif
