#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A32F0[];
struct ScalarView_800D138C;
extern "C" long fn_80066284(ScalarView_800D138C*);

extern "C" FactoryPyObject* fn_800D138C(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800D138C* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A32F0, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_80066284(self));
}
