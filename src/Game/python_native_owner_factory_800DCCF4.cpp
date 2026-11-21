/* Python creation binding; see docs/notes/game-python-refined-native-factories.md. */
#include "Game/python_owner_factories.h"
#include "Game/engine_callback_variant_ctors.h"
extern "C" FactoryPyObject* fn_800DCCF4(FactoryPyObject*,FactoryPyObject* args) {
 register const char* pool=lbl_802A2AA0;
 if(!PyArg_ParseTuple(args,pool+0x2ac8))return 0;
 LodAgent_802EC8A8* object=new(fn_801EFA1C(lbl_801EF5C8,0x80,pool+0x174,pool+0x60,0x174a,4)) LodAgent_802EC8A8;
 return factoryPointerObject(object,lbl_80318988[0x3c/4]);
}
