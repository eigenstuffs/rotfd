/* Scalar argument binding; see docs/notes/game-python-scalar-inputs.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A35C0[];
struct InputView_800D1FAC;
extern "C" signed char fn_8006653C(InputView_800D1FAC*, unsigned char);
extern "C" FactoryPyObject* fn_800D1FAC(FactoryPyObject*, FactoryPyObject* args) {
    InputView_800D1FAC* self;
    FactoryPyObject* parsed = 0;
    unsigned char value;
    if (!PyArg_ParseTuple(args, lbl_802A35C0, &parsed, &value)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_8006653C(self, value));
}
