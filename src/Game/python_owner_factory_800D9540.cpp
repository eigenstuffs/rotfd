/* Python creation binding with native placement construction.
 * See docs/notes/game-python-owner-factories.md. */
#include "Game/python_owner_factories.h"
struct Agent_80061AC0 { char unknown[0x200]; Agent_80061AC0(); };
extern "C" FactoryPyObject* fn_800D9540(FactoryPyObject*, FactoryPyObject* args) {
    register const char* pool = lbl_802A2AA0;
    if (!PyArg_ParseTuple(args, pool + 0x22D4)) return 0;
    Agent_80061AC0* object = new(fn_801EFA1C(lbl_801EF5C8, sizeof(Agent_80061AC0),
        pool + 0x174, pool + 0x60, 0x1310, 4)) Agent_80061AC0;
    return factoryPointerObject(object, lbl_80318988[0x4 / 4]);
}
