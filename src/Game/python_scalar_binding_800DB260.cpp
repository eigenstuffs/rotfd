/* Scalar field binding; see docs/notes/game-python-scalar-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A5180[];
struct ScalarView_800DB260 { char prefix[0x68]; int value; };
extern "C" FactoryPyObject* fn_800DB260(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800DB260* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A5180, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x20 / 4], 1) == -1) return 0;
    return PyInt_FromLong(self->value);
}
