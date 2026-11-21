/* Python creation binding with native placement construction.
 * See docs/notes/game-python-owner-factories.md. */
#include "Game/python_owner_factories.h"
struct Agent_8002B5F4 { char unknown[0x90]; Agent_8002B5F4(); };
extern "C" FactoryPyObject* fn_800DD2C4(FactoryPyObject*, FactoryPyObject* args) {
    register const char* pool = lbl_802A2AA0;
    if (!PyArg_ParseTuple(args, pool + 0x2B8C)) return 0;
    Agent_8002B5F4* object = new(fn_801EFA1C(lbl_801EF5C8, sizeof(Agent_8002B5F4),
        pool + 0x174, pool + 0x60, 0x17CB, 4)) Agent_8002B5F4;
    return factoryPointerObject(object, lbl_80318988[0x58 / 4]);
}
