/* Python creation binding with native placement construction.
 * See docs/notes/game-python-owner-factories.md. */
#include "Game/python_owner_factories.h"
struct Hierarchy_80200478 { char unknown[0xEC]; Hierarchy_80200478(); };
extern "C" FactoryPyObject* fn_800D0E50(FactoryPyObject*, FactoryPyObject* args) {
    register const char* pool = lbl_802A2AA0;
    if (!PyArg_ParseTuple(args, pool + 0x728)) return 0;
    Hierarchy_80200478* object = new(fn_801EFA1C(lbl_801EF5C8, sizeof(Hierarchy_80200478),
        pool + 0x174, pool + 0x73C, 0x79, 4)) Hierarchy_80200478;
    return factoryPointerObject(object, lbl_80318988[0x5C / 4]);
}
