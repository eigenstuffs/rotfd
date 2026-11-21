/* Native void binding; see docs/notes/game-python-native-void-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" const char lbl_802A3DF4[];
struct NativeVoidView_800D4688;
extern "C" void fn_80069504(NativeVoidView_800D4688*, float, short);
extern "C" FactoryPyObject* fn_800D4688(FactoryPyObject*, FactoryPyObject* args) {
    NativeVoidView_800D4688* self;
    float value0;
    FactoryPyObject* parsed = 0;
    short value1;
    if (!PyArg_ParseTuple(args, lbl_802A3DF4, &parsed, &value0, &value1)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x84 / 4], 1) == -1) return 0;
    fn_80069504(self, value0, value1);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
