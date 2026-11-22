#include "Game/python_scalar_bindings.h"
extern "C" FactoryPyObject* PyFloat_FromDouble(double);
extern "C" const char lbl_802A57E4[];
extern "C" signed char fn_8025CEA4(void*, void*);

extern "C" FactoryPyObject* fn_800DE350(FactoryPyObject*, FactoryPyObject* args) {
    void* self;
    void* other;
    FactoryPyObject* parsed0 = 0;
    FactoryPyObject* parsed1 = 0;
    if (!PyArg_ParseTuple(args, lbl_802A57E4, &parsed0, &parsed1)) return 0;
    if (fn_800CD864(parsed0, (void**)&self, lbl_80318988[0x40 / 4], 1) == -1) return 0;
    if (fn_800CD864(parsed1, (void**)&other, lbl_80318988[0xA8 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_8025CEA4(self, other));
}
