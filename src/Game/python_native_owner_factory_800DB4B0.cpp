#include "Game/python_owner_factories.h"
#include "Game/engine_callback_single_ctor.h"
extern "C" FactoryPyObject* fn_800DB4B0(FactoryPyObject*,FactoryPyObject* args) {
 register const char* pool=lbl_802A2AA0;
 if(!PyArg_ParseTuple(args,pool+0x2734))return 0;
 CallbackSingle_802ECA18* object=new(fn_801EFA1C(lbl_801EF5C8,0x78,pool+0x174,pool+0x60,0x157a,4)) CallbackSingle_802ECA18;
 return factoryPointerObject(object,lbl_80318988[0x30/4]);
}
