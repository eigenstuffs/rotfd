#include "Game/python_owner_factories.h"
struct CActorScriptAgent { char unknown[0x200]; CActorScriptAgent(); };
extern "C" FactoryPyObject* fn_800DD3EC(FactoryPyObject*, FactoryPyObject* args) {
    register const char* pool = lbl_802A2AA0;
    if (!PyArg_ParseTuple(args, pool + 0x2BA0)) return 0;
    CActorScriptAgent* object = new(fn_801EFA1C(lbl_801EF5C8, sizeof(CActorScriptAgent),
        pool + 0x174, pool + 0x60, 0x17D6, 4)) CActorScriptAgent;
    return factoryPointerObject(object, lbl_80318988[0x88 / 4]);
}
