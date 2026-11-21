/* Scalar method binding; see docs/notes/game-python-scalar-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3B48[];
struct ScalarView_800D3A78;
extern "C" short fn_800660E0(ScalarView_800D3A78*);

extern "C" FactoryPyObject* fn_800D3A78(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800D3A78* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A3B48, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_800660E0(self));
}
