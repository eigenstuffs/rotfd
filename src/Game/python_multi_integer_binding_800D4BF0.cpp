/* Multiple integer/object argument binding; see docs/notes/game-python-multi-integer-bindings.md. */
#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A3F28[];
extern "C" signed char fn_80069CA8(void*, void*, signed char);

extern "C" FactoryPyObject* fn_800D4BF0(FactoryPyObject*,FactoryPyObject* args){
    void* native0;
    void* native1;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    FactoryPyObject* arg2 = 0;
    if(!PyArg_ParseTuple(args,lbl_802A3F28, &arg0, &arg1, &arg2))return 0;
    if(fn_800CD864(arg0,(void**)&native0,lbl_80318988[0x84/4],1)==-1)return 0;
    if(fn_800CD864(arg1,(void**)&native1,lbl_80318988[0xC8/4],1)==-1)return 0;
    signed char value2=PyInt_AsLong(arg2);
    return PyInt_FromLong(fn_80069CA8(native0, native1, value2));
}
