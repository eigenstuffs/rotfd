#include "Game/python_owner_factories.h"
#include "Game/engine_callback_clock_ctor.h"
extern "C" FactoryPyObject* fn_800DD88C(FactoryPyObject*,FactoryPyObject* args) {
 register const char* pool=lbl_802A2AA0;
 if(!PyArg_ParseTuple(args,pool+0x2bf4))return 0;
 CallbackClock_802ECEC0* object=new(fn_801EFA1C(lbl_801EF5C8,0x70,pool+0x174,pool+0x60,0x1802,4)) CallbackClock_802ECEC0;
 return factoryPointerObject(object,lbl_80318988[0x40/4]);
}
