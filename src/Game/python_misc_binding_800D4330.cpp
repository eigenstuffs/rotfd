/* Miscellaneous object binding; see docs/notes/game-python-misc-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A3D44[];
extern "C" signed char fn_8006910C(void*, const char*, unsigned short, signed char);
extern "C" FactoryPyObject* fn_800D4330(FactoryPyObject*, FactoryPyObject* args) {
    void* self;
    const char* sound;
    FactoryPyObject* parsed = 0;
    FactoryPyObject* number = 0;
    unsigned short option;
    if (!PyArg_ParseTuple(args, lbl_802A3D44, &parsed, &sound, &option, &number)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    signed char value = PyInt_AsLong(number);
    return PyInt_FromLong(fn_8006910C(self, sound, option, value));
}
