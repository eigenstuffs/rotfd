/* Scalar argument binding; see docs/notes/game-python-scalar-inputs.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A4158[];
struct InputView_800D56B4;
extern "C" signed char fn_8006BE60(InputView_800D56B4*, float);
extern "C" FactoryPyObject* fn_800D56B4(FactoryPyObject*, FactoryPyObject* args) {
    InputView_800D56B4* self;
    float value;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A4158, &parsed, &value)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_8006BE60(self, value));
}
