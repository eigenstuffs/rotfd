/* Scalar argument binding; see docs/notes/game-python-scalar-inputs.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3E38[];
struct InputView_800D47DC;
extern "C" signed char fn_80069218(InputView_800D47DC*, unsigned char);
extern "C" FactoryPyObject* fn_800D47DC(FactoryPyObject*, FactoryPyObject* args) {
    InputView_800D47DC* self;
    FactoryPyObject* parsed = 0;
    unsigned char value;
    if (!PyArg_ParseTuple(args, lbl_802A3E38, &parsed, &value)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_80069218(self, value));
}
