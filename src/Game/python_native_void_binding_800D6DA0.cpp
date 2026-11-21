/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A462C[];
struct NativeVoidView_800D6DA0;
extern "C" void fn_80068854(NativeVoidView_800D6DA0*, short, short);
extern "C" FactoryPyObject* fn_800D6DA0(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D6DA0* self;
    FactoryPyObject* parsed = 0;
    short value0;
    short value1;
    if (!PyArg_ParseTuple(args, lbl_802A462C, &parsed, &value0, &value1)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_80068854(self, value0, value1);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
