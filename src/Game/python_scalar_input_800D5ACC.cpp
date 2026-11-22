#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A4260[];
struct InputView_800D5ACC;
extern "C" signed char fn_8006C508(InputView_800D5ACC*, unsigned char);
extern "C" FactoryPyObject* fn_800D5ACC(FactoryPyObject*, FactoryPyObject* args) {
    InputView_800D5ACC* self;
    FactoryPyObject* parsed = 0;
    unsigned char value;
    if (!PyArg_ParseTuple(args, lbl_802A4260, &parsed, &value)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_8006C508(self, value));
}
