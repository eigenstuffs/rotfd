/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A5B58[];
struct NativeVoidView_800DFBC0;
extern "C" void fn_802554F4(NativeVoidView_800DFBC0*);
extern "C" FactoryPyObject* fn_800DFBC0(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800DFBC0* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A5B58, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x4C / 4], 1) == -1) return 0;
    fn_802554F4(self);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
