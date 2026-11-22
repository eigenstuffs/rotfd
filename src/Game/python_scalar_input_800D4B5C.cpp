#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3F00[];
struct InputView_800D4B5C;
extern "C" signed char fn_80068D28(InputView_800D4B5C*, unsigned char);
extern "C" FactoryPyObject* fn_800D4B5C(FactoryPyObject*, FactoryPyObject* args) {
    InputView_800D4B5C* self;
    FactoryPyObject* parsed = 0;
    unsigned char value;
    if (!PyArg_ParseTuple(args, lbl_802A3F00, &parsed, &value)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_80068D28(self, value));
}
