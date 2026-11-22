#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3858[];
struct ScalarView_800D2D2C;
extern "C" long fn_80067034(ScalarView_800D2D2C*);

extern "C" FactoryPyObject* fn_800D2D2C(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800D2D2C* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A3858, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_80067034(self));
}
