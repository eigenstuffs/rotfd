#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A57C0[];
extern "C" const float lbl_8037970C;
extern "C" void fn_8025CF0C(void*, long, float);
extern "C" FactoryPyObject* fn_800DE294(FactoryPyObject*, FactoryPyObject* args) {
    void* self;
    float delay = lbl_8037970C;
    FactoryPyObject* parsed = 0;
    FactoryPyObject* number = 0;
    if (!PyArg_ParseTuple(args, lbl_802A57C0, &parsed, &number, &delay)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x40 / 4], 1) == -1) return 0;
    long value = PyInt_AsLong(number);
    fn_8025CF0C(self, value, delay);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
