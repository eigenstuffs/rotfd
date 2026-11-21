/* Python creation binding; see docs/notes/game-python-sdk-native-factories.md. */
#include "Game/python_owner_factories.h"
#include "Game/engine_native_factory_ctor_views.h"
extern "C" FactoryPyObject* fn_800DD764(FactoryPyObject*,FactoryPyObject* args) {
 register const char* pool=lbl_802A2AA0;
 if(!PyArg_ParseTuple(args,pool+0x2be0))return 0;
 Object_80065C60* object=new(fn_801EFA1C(lbl_801EF5C8,0x200,pool+0x174,pool+0x60,0x17f7,4)) Object_80065C60;
 return factoryPointerObject(object,lbl_80318988[0x70/4]);
}
