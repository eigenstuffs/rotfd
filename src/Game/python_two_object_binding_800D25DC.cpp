#include "Game/python_scalar_bindings.h"
extern "C" FactoryPyObject* PyFloat_FromDouble(double);
extern "C" const char lbl_802A36E4[];
extern "C" float fn_80066BC8(void*, void*);

extern "C" FactoryPyObject* fn_800D25DC(FactoryPyObject*, FactoryPyObject* args) {
    void* self;
    void* other;
    FactoryPyObject* parsed0 = 0;
    FactoryPyObject* parsed1 = 0;
    if (!PyArg_ParseTuple(args, lbl_802A36E4, &parsed0, &parsed1)) return 0;
    if (fn_800CD864(parsed0, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    if (fn_800CD864(parsed1, (void**)&other, lbl_80318988[0xC8 / 4], 1) == -1) return 0;
    return PyFloat_FromDouble(fn_80066BC8(self, other));
}
