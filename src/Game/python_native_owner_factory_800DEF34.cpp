/* Python creation binding; see docs/notes/game-python-native-factory-expanded.md. */
#include "Game/python_owner_factories.h"
#include "Game/engine_container_layer_ctor.h"
extern "C" FactoryPyObject* fn_800DEF34(FactoryPyObject*,FactoryPyObject* args) {
 register const char* pool=lbl_802A2AA0;
 if(!PyArg_ParseTuple(args,pool+0x2ec8))return 0;
 ContainerLayer_802EC6A0* object=new(fn_801EFA1C(lbl_801EF5C8,0x70,pool+0x174,pool+0x60,0x19c2,4)) ContainerLayer_802EC6A0;
 return factoryPointerObject(object,lbl_80318988[0x4c/4]);
}
