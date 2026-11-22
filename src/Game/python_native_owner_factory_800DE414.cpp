#include "Game/python_owner_factories.h"
#include "Game/engine_callback_variant_ctors.h"
extern "C" FactoryPyObject* fn_800DE414(FactoryPyObject*,FactoryPyObject* args) {
 register const char* pool=lbl_802A2AA0;
 if(!PyArg_ParseTuple(args,pool+0x2d5c))return 0;
 SkinAgent_802ECAF8* object=new(fn_801EFA1C(lbl_801EF5C8,0x70,pool+0x174,pool+0x60,0x18fb,4)) SkinAgent_802ECAF8;
 return factoryPointerObject(object,lbl_80318988[0x44/4]);
}
