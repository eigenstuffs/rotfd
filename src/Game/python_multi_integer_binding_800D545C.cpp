#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A40C0[];
extern "C" signed char fn_8006BBD4(void*, float, float);

extern "C" FactoryPyObject* fn_800D545C(FactoryPyObject*,FactoryPyObject* args){
    void* native0;
    float arg1;
    float arg2;
    FactoryPyObject* arg0 = 0;
    if(!PyArg_ParseTuple(args,lbl_802A40C0, &arg0, &arg1, &arg2))return 0;
    if(fn_800CD864(arg0,(void**)&native0,lbl_80318988[0x84/4],1)==-1)return 0;
    return PyInt_FromLong(fn_8006BBD4(native0, arg1, arg2));
}
