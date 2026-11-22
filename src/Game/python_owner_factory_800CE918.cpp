#include "Game/python_owner_factories.h"
struct Hierarchy_80200478 { char unknown[0xEC]; Hierarchy_80200478(); };
extern "C" FactoryPyObject* fn_800CE918(FactoryPyObject*, FactoryPyObject* args) {
    register const char* pool = lbl_802A2AA0;
    if (!PyArg_ParseTuple(args, pool + 0x260)) return 0;
    Hierarchy_80200478* object = new(fn_801EFA1C(lbl_801EF5C8, sizeof(Hierarchy_80200478),
        pool + 0x174, pool + 0x60, 0x379, 4)) Hierarchy_80200478;
    return factoryPointerObject(object, lbl_80318988[0x1C / 4]);
}
