/* Scalar method binding; see docs/notes/game-python-scalar-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A39FC[];
struct ScalarView_800D3574;
extern "C" unsigned short fn_80067198(ScalarView_800D3574*);

extern "C" FactoryPyObject* fn_800D3574(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800D3574* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A39FC, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_80067198(self));
}
