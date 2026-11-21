/* Scalar method binding; see docs/notes/game-python-scalar-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A33A8[];
struct ScalarView_800D1634;
extern "C" long fn_80066394(ScalarView_800D1634*);

extern "C" FactoryPyObject* fn_800D1634(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800D1634* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A33A8, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_80066394(self));
}
