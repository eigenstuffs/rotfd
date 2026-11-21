/* Scalar method binding; see docs/notes/game-python-scalar-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3B6C[];
struct ScalarView_800D3B04;
extern "C" unsigned char fn_800660E8(ScalarView_800D3B04*);

extern "C" FactoryPyObject* fn_800D3B04(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800D3B04* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A3B6C, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_800660E8(self));
}
