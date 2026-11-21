/* Python creation binding with native placement construction.
 * See docs/notes/game-python-owner-factories.md. */
#include "Game/python_owner_factories.h"
struct BaseObject_Z { char unknown[0xC]; BaseObject_Z(); };
extern "C" FactoryPyObject* fn_800CDFEC(FactoryPyObject*, FactoryPyObject* args) {
    register const char* pool = lbl_802A2AA0;
    if (!PyArg_ParseTuple(args, pool + 0x160)) return 0;
    BaseObject_Z* object = new(fn_801EFA1C(lbl_801EF5C8, sizeof(BaseObject_Z),
        pool + 0x174, pool + 0x60, 0x2DC, 4)) BaseObject_Z;
    return factoryPointerObject(object, lbl_80318988[0x5C / 4]);
}
