/* Scalar argument binding; see docs/notes/game-python-scalar-inputs.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3A1C[];
struct InputView_800D3600;
extern "C" signed char fn_800671A0(InputView_800D3600*, unsigned short);
extern "C" FactoryPyObject* fn_800D3600(FactoryPyObject*, FactoryPyObject* args) {
    InputView_800D3600* self;
    FactoryPyObject* parsed = 0;
    unsigned short value;
    if (!PyArg_ParseTuple(args, lbl_802A3A1C, &parsed, &value)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_800671A0(self, value));
}
