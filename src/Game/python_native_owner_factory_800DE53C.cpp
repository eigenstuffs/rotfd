/* Python creation binding; see docs/notes/game-python-native-factory-expanded.md. */
#include "Game/python_owner_factories.h"
#include "Game/engine_callback_flag_ctor.h"
extern "C" FactoryPyObject* fn_800DE53C(FactoryPyObject*,FactoryPyObject* args) {
 register const char* pool=lbl_802A2AA0;
 if(!PyArg_ParseTuple(args,pool+0x2d70))return 0;
 CallbackFlag_802ECD68* object=new(fn_801EFA1C(lbl_801EF5C8,0x68,pool+0x174,pool+0x60,0x1906,4)) CallbackFlag_802ECD68;
 return factoryPointerObject(object,lbl_80318988[0x48/4]);
}
