#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A56FC[];
struct ScalarPrefix_800DDC34 { char unknown[8]; };
struct ScalarView_800DDC34:ScalarPrefix_800DDC34 {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
};

extern "C" FactoryPyObject* fn_800DDC34(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800DDC34* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A56FC, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x40 / 4], 1) == -1) return 0;
    return PyInt_FromLong(self->slot1C());
}
