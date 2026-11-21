/* Python creation binding; see docs/notes/game-python-sdk-native-factories.md. */
#include "Game/python_owner_factories.h"
#include "Game/engine_native_factory_ctor_views.h"
extern "C" FactoryPyObject* fn_800DD514(FactoryPyObject*,FactoryPyObject* args) {
 register const char* pool=lbl_802A2AA0;
 if(!PyArg_ParseTuple(args,pool+0x2bb8))return 0;
 Object_8006590C* object=new(fn_801EFA1C(lbl_801EF5C8,0x200,pool+0x174,pool+0x60,0x17e1,4)) Object_8006590C;
 return factoryPointerObject(object,lbl_80318988[0x78/4]);
}
