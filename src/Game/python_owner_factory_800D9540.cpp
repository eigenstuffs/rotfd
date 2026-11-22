#include "Game/python_owner_factories.h"
struct CLevelAgent { char unknown[0x200]; CLevelAgent(); };
extern "C" FactoryPyObject* fn_800D9540(FactoryPyObject*, FactoryPyObject* args) {
    register const char* pool = lbl_802A2AA0;
    if (!PyArg_ParseTuple(args, pool + 0x22D4)) return 0;
    CLevelAgent* object = new(fn_801EFA1C(lbl_801EF5C8, sizeof(CLevelAgent),
        pool + 0x174, pool + 0x60, 0x1310, 4)) CLevelAgent;
    return factoryPointerObject(object, lbl_80318988[0x4 / 4]);
}
