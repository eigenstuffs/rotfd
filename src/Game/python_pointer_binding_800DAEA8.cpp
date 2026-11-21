/* Pointer object binding; see docs/notes/game-python-pointer-bindings.md. */
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
extern "C" const char lbl_802A50D4[];
extern "C" void* fn_8025E50C(void*);
extern "C" FactoryPyObject* fn_800DAEA8(FactoryPyObject*, FactoryPyObject* args) {
    char* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A50D4, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x20 / 4], 1) == -1) return 0;
    return reversePointerObject(lbl_80318988[0x8C / 4], fn_8025E50C(self));
}
