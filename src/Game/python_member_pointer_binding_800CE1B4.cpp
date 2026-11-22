#include "Game/python_indexed_pointer_encoding.h"
extern "C" const char lbl_802A2C38[];

extern "C" FactoryPyObject* fn_800CE1B4(FactoryPyObject*, FactoryPyObject* args) {
    char* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A2C38, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x5C / 4], 1) == -1) return 0;
    void*pointer=self + 0x4;
    return indexedPointerObject(pointer, lbl_80318988[0x7C / 4]);
}
