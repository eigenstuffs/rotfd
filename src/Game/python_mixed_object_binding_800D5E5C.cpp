/* Mixed object/scalar binding; see docs/notes/game-python-mixed-object-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A4340[];
extern "C" void fn_8006C620(void*, short, void*);

extern "C" FactoryPyObject* fn_800D5E5C(FactoryPyObject*, FactoryPyObject* args) {
    void* native0;
    void* native1;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg2 = 0;
    short arg1;
    if (!PyArg_ParseTuple(args, lbl_802A4340, &arg0, &arg1, &arg2)) return 0;
    if (fn_800CD864(arg0, (void**)&native0, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    if (fn_800CD864(arg2, (void**)&native1, lbl_80318988[0x28 / 4], 1) == -1) return 0;
    fn_8006C620(native0, arg1, native1);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
