#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A3E5C[];
extern "C" signed char fn_8006954C(void*, short, short);

extern "C" FactoryPyObject* fn_800D4870(FactoryPyObject*,FactoryPyObject* args){
    void* native0;
    FactoryPyObject* arg0 = 0;
    short arg1;
    short arg2;
    if(!PyArg_ParseTuple(args,lbl_802A3E5C, &arg0, &arg1, &arg2))return 0;
    if(fn_800CD864(arg0,(void**)&native0,lbl_80318988[0x84/4],1)==-1)return 0;
    return PyInt_FromLong(fn_8006954C(native0, arg1, arg2));
}
