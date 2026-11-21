/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A2D20[];
struct NativeVoidView_800CEADC;
extern "C" void fn_80201C14(NativeVoidView_800CEADC*);
extern "C" FactoryPyObject* fn_800CEADC(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800CEADC* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A2D20, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x1C / 4], 1) == -1) return 0;
    fn_80201C14(self);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
