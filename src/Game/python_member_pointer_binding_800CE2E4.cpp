/* Native indexed pointer wrapper; see docs/notes/game-python-member-pointer-bindings.md. */
/* Pointer object binding; see docs/notes/game-python-pointer-bindings.md. */
#include "Game/python_indexed_pointer_encoding.h"
extern "C" const char lbl_802A2C54[];

extern "C" FactoryPyObject* fn_800CE2E4(FactoryPyObject*, FactoryPyObject* args) {
    char* self;
    FactoryPyObject* parsed = 0;
    if (!PyArg_ParseTuple(args, lbl_802A2C54, &parsed)) return 0;
    if (fn_800CD864(parsed, (void**)&self, lbl_80318988[0x5C / 4], 1) == -1) return 0;
    void*pointer=self;
    return indexedPointerObject(pointer, lbl_80318988[0xD8 / 4]);
}
