/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A2D0C[];
struct NativeVoidView_800CEA40;
extern "C" void fn_8020349C(NativeVoidView_800CEA40*, float);
extern "C" FactoryPyObject* fn_800CEA40(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800CEA40* self;
    float value0;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A2D0C, &parsed, &value0)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x1C / 4], 1) == -1) return 0;
    fn_8020349C(self, value0);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
