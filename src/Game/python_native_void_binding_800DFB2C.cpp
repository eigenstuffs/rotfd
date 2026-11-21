/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A5B3C[];
struct NativeVoidView_800DFB2C;
extern "C" void fn_80255588(NativeVoidView_800DFB2C*);
extern "C" FactoryPyObject* fn_800DFB2C(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800DFB2C* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A5B3C, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x4C / 4], 1) == -1) return 0;
    fn_80255588(self);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
