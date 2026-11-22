#include "Game/python_scalar_bindings.h"
extern "C" FactoryPyObject* PyFloat_FromDouble(double);
extern "C" const char lbl_802A4018[];
extern "C" signed char fn_8006B938(void*, void*, void*);

extern "C" FactoryPyObject* fn_800D50E0(FactoryPyObject*, FactoryPyObject* args) {
    void* self;
    void* other;
    void* third;
    FactoryPyObject* parsed0 = 0;
    FactoryPyObject* parsed1 = 0;
    FactoryPyObject* parsed2 = 0;
    if (!PyArg_ParseTuple(args, lbl_802A4018, &parsed0, &parsed1, &parsed2)) return 0;
    if (fn_800CD864(parsed0, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    if (fn_800CD864(parsed1, (void**)&other, lbl_80318988[0x28 / 4], 1) == -1) return 0;
    if (fn_800CD864(parsed2, (void**)&third, lbl_80318988[0x28 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_8006B938(self, other, third));
}
