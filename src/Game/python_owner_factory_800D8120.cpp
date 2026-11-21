/* Python creation binding with native placement construction.
 * See docs/notes/game-python-owner-factories.md. */
#include "Game/python_owner_factories.h"
struct ContainerBase_802563CC { char unknown[0x60]; ContainerBase_802563CC(); };
extern "C" FactoryPyObject* fn_800D8120(FactoryPyObject*, FactoryPyObject* args) {
    register const char* pool = lbl_802A2AA0;
    if (!PyArg_ParseTuple(args, pool + 0x1FB4)) return 0;
    ContainerBase_802563CC* object = new(fn_801EFA1C(lbl_801EF5C8, sizeof(ContainerBase_802563CC),
        pool + 0x174, pool + 0x60, 0x1182, 4)) ContainerBase_802563CC;
    return factoryPointerObject(object, lbl_80318988[0x28 / 4]);
}
