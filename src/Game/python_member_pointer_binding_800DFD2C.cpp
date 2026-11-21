/* Native indexed pointer wrapper; see docs/notes/game-python-member-pointer-bindings.md. */
/* Pointer object binding; see docs/notes/game-python-pointer-bindings.md. */
#include "Game/python_indexed_pointer_encoding.h"
extern "C" const char lbl_802A5B90[];

extern "C" FactoryPyObject* fn_800DFD2C(FactoryPyObject*, FactoryPyObject* args) {
    char* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A5B90, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x50 / 4], 1) == -1) return 0;
    void*pointer=self + 0x58;
    return indexedPointerObject(pointer, lbl_80318988[0xA8 / 4]);
}
