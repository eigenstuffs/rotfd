/* Miscellaneous object binding; see docs/notes/game-python-misc-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A52BC[];
struct MiscView_800DBC98 { char prefix[0x90]; long value; };
extern "C" FactoryPyObject* fn_800DBC98(FactoryPyObject*, FactoryPyObject* args) {
    MiscView_800DBC98* self;
    FactoryPyObject* parsed = 0;
    FactoryPyObject* number = 0;
    if (!PyArg_ParseTuple(args, lbl_802A52BC, &parsed, &number)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x74 / 4], 1) == -1) return 0;
    self->value = PyInt_AsLong(number);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
