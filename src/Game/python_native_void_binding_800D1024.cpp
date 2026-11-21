/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3204[];
struct NativeVoidView_800D1024;
extern "C" void fn_8005E674(NativeVoidView_800D1024*, int);
extern "C" FactoryPyObject* fn_800D1024(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D1024* self;
    FactoryPyObject* parsed = 0;
    int value0 = 0;
    if (!PyArg_ParseTuple(args, lbl_802A3204, &parsed, &value0)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_8005E674(self, value0);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
