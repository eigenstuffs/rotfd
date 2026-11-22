#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3AA4[];
struct InputView_800D3840;
extern "C" signed char fn_800671E8(InputView_800D3840*, short);
extern "C" FactoryPyObject* fn_800D3840(FactoryPyObject*, FactoryPyObject* args) {
    InputView_800D3840* self;
    FactoryPyObject* parsed = 0;
    short value;
    if (!PyArg_ParseTuple(args, lbl_802A3AA4, &parsed, &value)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_800671E8(self, value));
}
