#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3898[];
struct ScalarView_800D2E74;
extern "C" unsigned short fn_800670B4(ScalarView_800D2E74*);

extern "C" FactoryPyObject* fn_800D2E74(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800D2E74* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A3898, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_800670B4(self));
}
