/* Python creation binding; see docs/notes/game-python-refined-native-factories.md. */
#include "Game/python_owner_factories.h"
#include "Game/engine_callback_control_ctor.h"
extern "C" FactoryPyObject* fn_800DBD3C(FactoryPyObject*,FactoryPyObject* args) {
 register const char* pool=lbl_802A2AA0;
 if(!PyArg_ParseTuple(args,pool+0x283c))return 0;
 CallbackControl_802ECC00* object=new(fn_801EFA1C(lbl_801EF5C8,0x80,pool+0x174,pool+0x60,0x160b,4)) CallbackControl_802ECC00;
 return factoryPointerObject(object,lbl_80318988[0xcc/4]);
}
