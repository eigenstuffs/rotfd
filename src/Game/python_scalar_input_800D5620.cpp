/* Scalar argument binding; see docs/notes/game-python-scalar-inputs.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A4134[];
struct InputView_800D5620;
extern "C" signed char fn_8006BDD8(InputView_800D5620*, float);
extern "C" FactoryPyObject* fn_800D5620(FactoryPyObject*, FactoryPyObject* args) {
    InputView_800D5620* self;
    float value;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A4134, &parsed, &value)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_8006BDD8(self, value));
}
