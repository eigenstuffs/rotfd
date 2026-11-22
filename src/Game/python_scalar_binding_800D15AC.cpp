#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3380[];
struct ScalarView_800D15AC;
extern "C" long fn_8006635C(ScalarView_800D15AC*);

extern "C" FactoryPyObject* fn_800D15AC(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800D15AC* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A3380, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_8006635C(self));
}
