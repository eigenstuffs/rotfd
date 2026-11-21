/* Scalar argument binding; see docs/notes/game-python-scalar-inputs.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A4904[];
struct InputView_800D7AC4;
extern "C" signed char fn_80069770(InputView_800D7AC4*, short);
extern "C" FactoryPyObject* fn_800D7AC4(FactoryPyObject*, FactoryPyObject* args) {
    InputView_800D7AC4* self;
    FactoryPyObject* parsed = 0;
    short value;
    if (!PyArg_ParseTuple(args, lbl_802A4904, &parsed, &value)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_80069770(self, value));
}
