/* Three-object binding; see docs/notes/game-python-three-object-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" FactoryPyObject* PyFloat_FromDouble(double);
extern "C" const char lbl_802A2FA4[];
extern "C" signed char fn_8020023C(void*, void*, void*);

extern "C" FactoryPyObject* fn_800CFFEC(FactoryPyObject*, FactoryPyObject* args) {
    void* self;
    void* other;
    void* third;
    FactoryPyObject* parsed0 = 0;
    FactoryPyObject* parsed1 = 0;
    FactoryPyObject* parsed2 = 0;
    if (!PyArg_ParseTuple(args, lbl_802A2FA4, &parsed0, &parsed1, &parsed2)) return 0;
    if (fn_800CD864(parsed0, (void**)&self, lbl_80318988[0x1C / 4], 1) == -1) return 0;
    if (fn_800CD864(parsed1, (void**)&other, lbl_80318988[0xD8 / 4], 1) == -1) return 0;
    if (fn_800CD864(parsed2, (void**)&third, lbl_80318988[0xA0 / 4], 1) == -1) return 0;
    return PyInt_FromLong(fn_8020023C(self, other, third));
}
