#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3A60[];
struct ScalarView_800D3720;
extern "C" unsigned short fn_800671C4(ScalarView_800D3720*);

extern "C" FactoryPyObject* fn_800D3720(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800D3720* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A3A60, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_800671C4(self));
}
