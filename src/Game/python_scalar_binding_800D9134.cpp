#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A4D10[];
struct ScalarView_800D9134 { char prefix[0x54]; int value; };
extern "C" FactoryPyObject* fn_800D9134(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800D9134* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A4D10, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x28 / 4], 1) == -1) return 0;
    return PyInt_FromLong(self->value);
}
