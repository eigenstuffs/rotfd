/* Python creation binding; see docs/notes/game-python-sdk-native-factories.md. */
#include "Game/python_owner_factories.h"
#include "Game/engine_native_factory_ctor_views.h"
extern "C" FactoryPyObject* fn_800DBB70(FactoryPyObject*,FactoryPyObject* args) {
 register const char* pool=lbl_802A2AA0;
 if(!PyArg_ParseTuple(args,pool+0x2804))return 0;
 Object_8002AD98* object=new(fn_801EFA1C(lbl_801EF5C8,0x98,pool+0x174,pool+0x60,0x15ed,4)) Object_8002AD98;
 return factoryPointerObject(object,lbl_80318988[0x74/4]);
}
