/* Scalar argument binding; see docs/notes/game-python-scalar-inputs.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3228[];
struct InputView_800D10C4;
extern "C" long fn_800661B8(InputView_800D10C4*, unsigned short);
extern "C" FactoryPyObject* fn_800D10C4(FactoryPyObject*, FactoryPyObject* args) {
    InputView_800D10C4* self;
    FactoryPyObject* parsed = 0;
    unsigned short value;
    if (!PyArg_ParseTuple(args, lbl_802A3228, &parsed, &value)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_800661B8(self, value));
}
