#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A39D8[];
struct ScalarView_800D34E8;
extern "C" unsigned short fn_80067190(ScalarView_800D34E8*);

extern "C" FactoryPyObject* fn_800D34E8(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800D34E8* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A39D8, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_80067190(self));
}
