// Shared native lower interface with the upper accumulated-float callbacks.
#ifndef GAME_OBJECTS_ROOT_CALLBACKS_INTERNAL_H
#define GAME_OBJECTS_ROOT_CALLBACKS_INTERNAL_H

#include "objects_owner_internal.h"

struct Manipulator_Z : Activable_Z {
    float accumulated;

    Manipulator_Z();
    virtual ~Manipulator_Z();
    virtual void slot2C(float delta);
    virtual void slot30();
    virtual void slot34();
    virtual void slot38(float delta);
    virtual void slot3C();
};

extern "C" {
void fn_802139D8(Activable_Z*);
void fn_80213A18(Activable_Z*);
}

typedef char CheckRootSize[sizeof(Manipulator_Z) == 0x20 ? 1 : -1];

#endif
