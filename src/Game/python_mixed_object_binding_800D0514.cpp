/* Mixed object/scalar binding; see docs/notes/game-python-mixed-object-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A303C[];
extern "C" void fn_802001D4(void*, void*, signed char);

extern "C" FactoryPyObject* fn_800D0514(FactoryPyObject*, FactoryPyObject* args) {
    void* native0;
    void* native1;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    FactoryPyObject* arg2 = 0;
    signed char value = 1;
    if (!PyArg_ParseTuple(args, lbl_802A303C, &arg0, &arg1, &arg2)) return 0;
    if (fn_800CD864(arg0, (void**)&native0, lbl_80318988[0x1C / 4], 1) == -1) return 0;
    if (fn_800CD864(arg1, (void**)&native1, lbl_80318988[0x9C / 4], 1) == -1) return 0;
    if (arg2) value = PyInt_AsLong(arg2);
    fn_802001D4(native0, native1, (signed char)(long)value);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
