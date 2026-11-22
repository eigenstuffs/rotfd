#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3A3C[];
struct ScalarView_800D3694;
extern "C" unsigned short fn_800671BC(ScalarView_800D3694*);

extern "C" FactoryPyObject* fn_800D3694(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800D3694* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A3A3C, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_800671BC(self));
}
