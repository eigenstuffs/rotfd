#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A410C[];
struct InputView_800D558C;
extern "C" signed char fn_8006BD50(InputView_800D558C*, float);
extern "C" FactoryPyObject* fn_800D558C(FactoryPyObject*, FactoryPyObject* args) {
    InputView_800D558C* self;
    float value;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A410C, &parsed, &value)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_8006BD50(self, value));
}
