/* Scalar argument binding; see docs/notes/game-python-scalar-inputs.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A359C[];
struct InputView_800D1F18;
extern "C" signed char fn_800665D8(InputView_800D1F18*, unsigned char);
extern "C" FactoryPyObject* fn_800D1F18(FactoryPyObject*, FactoryPyObject* args) {
    InputView_800D1F18* self;
    FactoryPyObject* parsed = 0;
    unsigned char value;
    if (!PyArg_ParseTuple(args, lbl_802A359C, &parsed, &value)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_800665D8(self, value));
}
