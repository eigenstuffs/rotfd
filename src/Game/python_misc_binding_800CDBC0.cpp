/* Miscellaneous object binding; see docs/notes/game-python-misc-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A2B40[];
extern "C" void* lbl_80377548;
extern "C" FactoryPyObject* fn_800CDBC0(FactoryPyObject*, FactoryPyObject* args) {
    void* self;
    FactoryPyObject* parsed = 0;

    if (!PyArg_ParseTuple(args, lbl_802A2B40, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x5C / 4], 1) == -1) return 0;
    lbl_80377548 = self;
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
