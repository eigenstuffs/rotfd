#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A2D90[];
struct ScalarView_800CEE4C { char prefix[0xDC]; int value; };
extern "C" FactoryPyObject* fn_800CEE4C(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800CEE4C* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A2D90, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x1C / 4], 1) == -1) return 0;
    return PyInt_FromLong(self->value);
}
