#include "Game/python_scalar_bindings.h"
extern "C" long PyInt_AsLong(FactoryPyObject*);
extern "C" const char lbl_802A2CA0[];
extern "C" void fn_802073E8(void*, long, void*, float);

extern "C" FactoryPyObject* fn_800CE55C(FactoryPyObject*,FactoryPyObject* args){
    void* native0;
    void* native1;
    float arg3;
    FactoryPyObject* arg0 = 0;
    FactoryPyObject* arg1 = 0;
    FactoryPyObject* arg2 = 0;
    if(!PyArg_ParseTuple(args,lbl_802A2CA0, &arg0, &arg1, &arg2, &arg3))return 0;
    if(fn_800CD864(arg0,(void**)&native0,lbl_80318988[0x5C/4],1)==-1)return 0;
    long value1=PyInt_AsLong(arg1);
    if(fn_800CD864(arg2,(void**)&native1,lbl_80318988[0xDC/4],1)==-1)return 0;
    fn_802073E8(native0, value1, native1, arg3);
    ++_Py_NoneStruct.references;
    return &_Py_NoneStruct;
}
