#include "Game/python_scalar_bindings.h"
extern "C" FactoryPyObject* PyFloat_FromDouble(double);
extern "C" const char lbl_802A4978[];
extern "C" void fn_8006ECE8(void*, void*, void*);

extern "C" FactoryPyObject* fn_800D7CA4(FactoryPyObject*, FactoryPyObject* args) {
    void* self;
    void* other;
    void* third;
    FactoryPyObject* parsed0 = 0;
    FactoryPyObject* parsed1 = 0;
    FactoryPyObject* parsed2 = 0;
    if (!PyArg_ParseTuple(args, lbl_802A4978, &parsed0, &parsed1, &parsed2)) return 0;
    if (fn_800CD864(parsed0, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    if (fn_800CD864(parsed1, (void**)&other, lbl_80318988[0xC8 / 4], 1) == -1) return 0;
    if (fn_800CD864(parsed2, (void**)&third, lbl_80318988[0xC8 / 4], 1) == -1) return 0;
    fn_8006ECE8(self, other, third);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
