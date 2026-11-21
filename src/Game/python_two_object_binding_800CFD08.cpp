/* Two-object binding; see docs/notes/game-python-two-object-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" FactoryPyObject* PyFloat_FromDouble(double);
extern "C" const char lbl_802A2F44[];
extern "C" long fn_802067A0(void*, void*);

extern "C" FactoryPyObject* fn_800CFD08(FactoryPyObject*, FactoryPyObject* args) {
    void* self;
    void* other;
    FactoryPyObject* parsed0 = 0;
    FactoryPyObject* parsed1 = 0;
    if (!PyArg_ParseTuple(args, lbl_802A2F44, &parsed0, &parsed1)) return 0;
    if (fn_800CD864(parsed0, (void**)&self, lbl_80318988[0x1C / 4], 1) == -1) return 0;
    if (fn_800CD864(parsed1, (void**)&other, lbl_80318988[0xA8 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_802067A0(self, other));
}
