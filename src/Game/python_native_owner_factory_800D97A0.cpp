/* Python creation binding; see docs/notes/game-python-native-factory-expanded.md. */
#include "Game/python_owner_factories.h"
#include "Game/engine_callback_pair_ctor.h"
extern "C" FactoryPyObject* fn_800D97A0(FactoryPyObject*,FactoryPyObject* args) {
 register const char* pool=lbl_802A2AA0;
 if(!PyArg_ParseTuple(args,pool+0x2308))return 0;
 CallbackPair_802EC798* object=new(fn_801EFA1C(lbl_801EF5C8,0x70,pool+0x174,pool+0x60,0x132a,4)) CallbackPair_802EC798;
 return factoryPointerObject(object,lbl_80318988[0x20/4]);
}
