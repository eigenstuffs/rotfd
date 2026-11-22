#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3498[];
struct InputView_800D1A80;
extern "C" long fn_80066508(InputView_800D1A80*, unsigned char);
extern "C" FactoryPyObject* fn_800D1A80(FactoryPyObject*, FactoryPyObject* args) {
    InputView_800D1A80* self;
    FactoryPyObject* parsed = 0;
    unsigned char value;
    if (!PyArg_ParseTuple(args, lbl_802A3498, &parsed, &value)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_80066508(self, value));
}
