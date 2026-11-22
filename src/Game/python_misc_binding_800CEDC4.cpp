#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A2D78[];
struct MiscView_800CEDC4 { char prefix[0x10]; char name[1]; };
extern "C" FactoryPyObject* fn_800CEDC4(FactoryPyObject*, FactoryPyObject* args) {
    MiscView_800CEDC4* self;
    FactoryPyObject* parsed = 0;

    if (!PyArg_ParseTuple(args, lbl_802A2D78, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x1C / 4], 1) == -1) return 0;
    return PyString_FromString(self->name);
}
