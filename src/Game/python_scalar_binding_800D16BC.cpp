#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A33C8[];
struct ScalarView_800D16BC;
extern "C" unsigned char fn_800663C8(ScalarView_800D16BC*);

extern "C" FactoryPyObject* fn_800D16BC(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800D16BC* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A33C8, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_800663C8(self));
}
