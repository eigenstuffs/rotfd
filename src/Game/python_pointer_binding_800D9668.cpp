#include "Game/python_scalar_bindings.h"
inline FactoryPyObject* reversePointerObject(FactoryType* type, void* pointer) {
    if (!pointer) {
        ++_Py_NoneStruct.references;
        return &_Py_NoneStruct;
    }
    char text[512];
    factoryPointerString(text, pointer, type);
    return PyString_FromString(text);
}
extern "C" const char lbl_802A4D88[];
extern "C" void* fn_8025E548(void*);
extern "C" FactoryPyObject* fn_800D9668(FactoryPyObject*, FactoryPyObject* args) {
    char* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A4D88, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x24 / 4], 1) == -1) return 0;
    return reversePointerObject(lbl_80318988[0x90 / 4], fn_8025E548(self));
}
