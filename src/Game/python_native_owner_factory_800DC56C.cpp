/* Python creation binding; see docs/notes/game-python-refined-native-factories.md. */
#include "Game/python_owner_factories.h"
#include "Game/engine_callback_breakable_ctor.h"
extern "C" FactoryPyObject* fn_800DC56C(FactoryPyObject*,FactoryPyObject* args) {
 register const char* pool=lbl_802A2AA0;
 if(!PyArg_ParseTuple(args,pool+0x29c0))return 0;
 Breakable_802EC810* object=new(fn_801EFA1C(lbl_801EF5C8,0x88,pool+0x174,pool+0x60,0x16b5,4)) Breakable_802EC810;
 return factoryPointerObject(object,lbl_80318988[0xd0/4]);
}
