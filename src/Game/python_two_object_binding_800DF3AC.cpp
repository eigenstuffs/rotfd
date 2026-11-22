#include "Game/python_scalar_bindings.h"
extern "C" FactoryPyObject* PyFloat_FromDouble(double);
extern "C" const char lbl_802A5A0C[];
extern "C" void fn_80255140(void*, void*);

extern "C" FactoryPyObject* fn_800DF3AC(FactoryPyObject*, FactoryPyObject* args) {
    void* self;
    void* other;
    FactoryPyObject* parsed0 = 0;
    FactoryPyObject* parsed1 = 0;
    if (!PyArg_ParseTuple(args, lbl_802A5A0C, &parsed0, &parsed1)) return 0;
    if (fn_800CD864(parsed0, (void**)&self, lbl_80318988[0x4C / 4], 1) == -1) return 0;
    if (fn_800CD864(parsed1, (void**)&other, lbl_80318988[0x7C / 4], 1) == -1) return 0;
    fn_80255140(self, other);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
