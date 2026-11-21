/* Scalar field binding; see docs/notes/game-python-scalar-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A2DBC[];
struct ScalarView_800CEF5C { char prefix[0xE4]; int value; };
extern "C" FactoryPyObject* fn_800CEF5C(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800CEF5C* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A2DBC, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x1C / 4], 1) == -1) return 0;
    return PyInt_FromLong(self->value);
}
