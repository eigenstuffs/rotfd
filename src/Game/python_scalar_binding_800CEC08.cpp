#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A2D48[];
struct ScalarView_800CEC08;
extern "C" signed char fn_80206A20(ScalarView_800CEC08*);

extern "C" FactoryPyObject* fn_800CEC08(FactoryPyObject*, FactoryPyObject* args) {
    ScalarView_800CEC08* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A2D48, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x1C / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_80206A20(self));
}
