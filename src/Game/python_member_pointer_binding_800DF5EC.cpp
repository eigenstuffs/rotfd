#include "Game/python_indexed_pointer_encoding.h"
extern "C" const char lbl_802A5A58[];

extern "C" FactoryPyObject* fn_800DF5EC(FactoryPyObject*, FactoryPyObject* args) {
    char* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A5A58, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x4C / 4], 1) == -1) return 0;
    void*pointer=self + 0x60;
    return indexedPointerObject(pointer, lbl_80318988[0xD8 / 4]);
}
