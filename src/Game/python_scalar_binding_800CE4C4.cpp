#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A2C84[];
struct ScalarPrefix_800CE4C4 { char unknown[8]; };
struct ScalarView_800CE4C4:ScalarPrefix_800CE4C4 {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
};

extern "C" FactoryPyObject* fn_800CE4C4(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800CE4C4* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A2C84, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x5C / 4], 1) == -1) return 0;
    return PyInt_FromLong(self->slot1C());
}
