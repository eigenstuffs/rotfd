/* Miscellaneous object binding; see docs/notes/game-python-misc-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A4924[];
extern "C" void fn_8006EC60(void*, signed char, unsigned char);
extern "C" FactoryPyObject* fn_800D7B58(FactoryPyObject*, FactoryPyObject* args) {
    void* self;
    FactoryPyObject* parsed = 0;
    FactoryPyObject* number = 0;
    unsigned char option;
    if (!PyArg_ParseTuple(args, lbl_802A4924, &parsed, &number, &option)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    signed char value = PyInt_AsLong(number);
    fn_8006EC60(self, value, option);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
