/* Mixed object/scalar binding; see docs/notes/game-python-mixed-object-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A4C78[];
extern "C" void fn_80255B78(void*, unsigned long);

extern "C" FactoryPyObject* fn_800D8E18(FactoryPyObject*, FactoryPyObject* args) {
    void* native0;
    unsigned long* native1;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    if (!PyArg_ParseTuple(args, lbl_802A4C78, &arg0, &arg1)) return 0;
    if (fn_800CD864(arg0, (void**)&native0, lbl_80318988[0x28 / 4], 1) == -1) return 0;
    if (fn_800CD864(arg1, (void**)&native1, lbl_80318988[0xB0 / 4], 1) == -1) return 0;
    fn_80255B78(native0, *native1);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
