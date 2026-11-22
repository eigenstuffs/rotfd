#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A4A74[];
struct ScalarPrefix_800D82E8 { char unknown[8]; };
struct ScalarView_800D82E8:ScalarPrefix_800D82E8 {
    virtual void slot08();
    virtual void slot0C();
    virtual void slot10();
    virtual void slot14();
    virtual void slot18();
    virtual signed char slot1C();
};

extern "C" FactoryPyObject* fn_800D82E8(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800D82E8* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A4A74, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x28 / 4], 1) == -1) return 0;
    return PyInt_FromLong(self->slot1C());
}
