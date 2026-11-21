/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A2DF8[];
struct NativeVoidView_800CF10C;
extern "C" void fn_802020AC(NativeVoidView_800CF10C*);
extern "C" FactoryPyObject* fn_800CF10C(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800CF10C* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A2DF8, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x1C / 4], 1) == -1) return 0;
    fn_802020AC(self);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
