#include "Game/python_owner_factories.h"
struct Agent_80052520 { char unknown[0x320]; Agent_80052520(); };
extern "C" FactoryPyObject* fn_800D9418(FactoryPyObject*, FactoryPyObject* args) {
    register const char* pool = lbl_802A2AA0;
    if (!PyArg_ParseTuple(args, pool + 0x22C0)) return 0;
    Agent_80052520* object = new(fn_801EFA1C(lbl_801EF5C8, sizeof(Agent_80052520),
        pool + 0x174, pool + 0x60, 0x1305, 4)) Agent_80052520;
    return factoryPointerObject(object, lbl_80318988[0x8 / 4]);
}
