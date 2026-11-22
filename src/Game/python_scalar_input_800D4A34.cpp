#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3EC0[];
struct InputView_800D4A34;
extern "C" signed char fn_800699A8(InputView_800D4A34*, unsigned char);
extern "C" FactoryPyObject* fn_800D4A34(FactoryPyObject*, FactoryPyObject* args) {
    InputView_800D4A34* self;
    FactoryPyObject* parsed = 0;
    unsigned char value;
    if (!PyArg_ParseTuple(args, lbl_802A3EC0, &parsed, &value)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_800699A8(self, value));
}
