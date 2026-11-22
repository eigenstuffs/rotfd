#include "Game/python_scalar_bindings.h"
extern "C" FactoryPyObject* PyFloat_FromDouble(double);
extern "C" const char lbl_802A370C[];
extern "C" float fn_80066CC4(void*, void*);

extern "C" FactoryPyObject* fn_800D269C(FactoryPyObject*, FactoryPyObject* args) {
    void* self;
    void* other;
    FactoryPyObject* parsed0 = 0;
    FactoryPyObject* parsed1 = 0;
    if (!PyArg_ParseTuple(args, lbl_802A370C, &parsed0, &parsed1)) return 0;
    if (fn_800CD864(parsed0, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    if (fn_800CD864(parsed1, (void**)&other, lbl_80318988[0xC8 / 4], 1) == -1) return 0;
    return PyFloat_FromDouble(fn_80066CC4(self, other));
}
