/* Miscellaneous object binding; see docs/notes/game-python-misc-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A2DD0[];
struct MiscView_800CEFE4 { char prefix[0xE4]; int value; };
extern "C" FactoryPyObject* fn_800CEFE4(FactoryPyObject*, FactoryPyObject* args) {
    MiscView_800CEFE4* self;
    FactoryPyObject* parsed = 0;

    if (!PyArg_ParseTuple(args, lbl_802A2DD0, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x1C / 4], 1) == -1) return 0;
    return PyInt_FromLong((signed char)(self->value >= 0));
}
