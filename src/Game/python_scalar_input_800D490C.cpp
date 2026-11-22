#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3E80[];
struct InputView_800D490C;
extern "C" signed char fn_80069654(InputView_800D490C*, short);
extern "C" FactoryPyObject* fn_800D490C(FactoryPyObject*, FactoryPyObject* args) {
    InputView_800D490C* self;
    FactoryPyObject* parsed = 0;
    short value;
    if (!PyArg_ParseTuple(args, lbl_802A3E80, &parsed, &value)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_80069654(self, value));
}
